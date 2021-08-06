
// librarys
#include <Arduino.h>
#include <RotaryEncoder.h>
#include <LiquidCrystal_I2C.h>
#include <FastLED.h>
#include <Dusk2Dawn.h>

// create constants and define pins
#ifndef INIT_SKETCH
#define INIT_SKETCH

// helper function to describe length of array
#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0])))

// ENCODER PINS (if multiple, set in array)
const int CLK[] = {8};
const int DT[]  = {9};
const int SW[]  = {7};

#define num_encoders NUMITEMS(CLK) 
RotaryEncoder *encoder[num_encoders]; //defines pointer for encoders

//int lastStateCLK[] = {0}; //records changes in rotary encoders
int btnState[] = {0}; //records if button is currently pressed
unsigned long lastButtonPress[] = {0}; //time since last button press
int pos[] = {0}; //stores previous position of encoders

//////////////////////////// MENU SETTINGS ////////////////////////////
// menu titles
const String menu_items[] = {"Home", "Set date/time", "LED Pattern", "LED Brightness", "Pump timer", "LED auto"};
const int menu_length = NUMITEMS(menu_items);

//////////////////////////// MENU VARIABLES ////////////////////////////
//int pos_change = 0;
//bool btn_press = false;
int state = -1; //state of FSM (-1 is menu select, n>=0 is the menu item)
int setter = 0; //secondary state when in menu
int menu_pos = 0; //holds the position of the menu
const unsigned long timeout_time = 120000; // 2 minutes in miliseconds

//////////////////////////// CLOCK VARIABLES ////////////////////////////
int h = 20; // hours
int m = 58; // minutes
int s = 45; // seconds

int day = 19; // day of month
int month = 6; // month
int year = 2021; // year

bool savings = true; // daylight savings time active

unsigned long last_time = 0; // counter for incrementing time using millis()


//////////////////////////// AUTO TIMER VARIABLES ////////////////////////////
int led_auto = 1; // 0 = off, 1 = sunset, 2 = on at, 3 = on until midnight
int led_auto_hour = 8 + 12; // 24 hour system
int led_auto_minute = 0;

int pump_auto = 1; //0 = off, 1 = sunset, 2 = on for, 3 = on until midnight
int pump_auto_hour = 0; // max 10 hours
int pump_auto_minute = 0;

// SUNSET
int todays_sunset = 0; // tracks today's sunset (in minutes)
Dusk2Dawn albany(44.636513, -123.105927, -8); // initialize location for sunset calculations

//////////////////////////// LCD + LED INIT ////////////////////////////

// INIT LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

// LED STRING SETTINGS + INIT
#define DATA_PIN 2                // pin of LED data signal
#define LED_TYPE    WS2812        // tybe of LED string
#define COLOR_ORDER GRB           // order of LEDs for color
#define NUM_LEDS    60            // number of LEDs in string
CRGB leds[NUM_LEDS];              // init
#define TIME_BETWEEN_FRAMES  10   // update timer in miliseconds
unsigned long led_timer = 0;      // tracks time since last update
int brightness = 50;              // percent brightness

// PIN FOR PUMP SOLID STATE RELAY
#define pump_pin 3

#endif

// This interrupt routine will be called on any change of one of the input signals
// tracks changes in rotary encoder
void checkPosition() {
  for (int i = 0; i < num_encoders; i++) {
    encoder[i]->tick();
  }
}

void setup() {
  delay(1000); // 1 second delay to allow reset

  // calculate today's sunset
  todays_sunset = albany.sunset(year, month, day, false);

  // LCD STARTUP
  lcd.init();       // initialize the lcd
  lcd.backlight();  // turn on the backlight
  printHeader();    // print menu header
  printMenu();      // print menu item

  //Creates rotaty encoders and button initializations
  for (int i = 0; i < num_encoders; i++) {
    encoder[i] = new RotaryEncoder(CLK[i], DT[i], RotaryEncoder::LatchMode::FOUR3);
    attachInterrupt(digitalPinToInterrupt(CLK[i]), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(DT[i]), checkPosition, CHANGE);
    pinMode(SW[i], INPUT_PULLUP);
//    lastStateCLK[i] = digitalRead(CLK[i]);
  }

  pinMode(pump_pin, OUTPUT); // init pump SSR data pin

  //create LED object
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(brightness);
  led_timer = millis(); // set refresh timer to now

  last_time = millis(); // init clock

  Serial.begin(9600); // start Serial and print begin message
  while (! Serial);
  Serial.println("Sketch Begin.");
}

//////////////////////////// LED PREP STUFF ////////////////////////////

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = {setWhite, sparkle, rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };
String pattern_list[] = {"white", "sparkle", "rainbow", "rainbow glitter", "confetti", "sineline", "juggle", "bpm"};

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop() {
  static int pos_change = 0;
  static bool btn_press = false;

  // check for updates in encoders and buttons (put in for loop for 
  pos_change = updateEncoder(0);
  btn_press = readButton(0);    


  if (btn_press) {
    setState();
  }
  if (pos_change != 0) {
    updateStateParams(pos_change);
  }

  if (millis() - lastButtonPress[0] > timeout_time) {
    state = 0;
    lcd.noBacklight();
  }

  updateTime(false);
  switch (led_auto) {
    case 0:
      setBlack();
      break;
    case 1:
      if ((m + h * 60 > todays_sunset) && (!savings || h < 23)) {
        gPatterns[gCurrentPatternNumber]();
      } else {
        setBlack();
      }
      break;
    case 2:
      if ((m + h * 60) > (led_auto_hour * 60 + led_auto_minute) && (!savings || h < 23)) {
        gPatterns[gCurrentPatternNumber]();
      } else {
        setBlack();
      }
      break;
    case 3:
      gPatterns[gCurrentPatternNumber]();
      break;
  }

    switch (pump_auto) {
    case 0:
      digitalWrite(pump_pin, LOW);
      break;
    case 1:
      if ((m + h * 60 > todays_sunset) && (!savings || h < 23)) {
        digitalWrite(pump_pin, HIGH);
      } else {
        digitalWrite(pump_pin, LOW);
      }
      break;
    case 2:
      if (((m + h * 60) > (pump_auto_hour * 60 + pump_auto_minute)) && (!savings || h < 23)) {
        digitalWrite(pump_pin, HIGH);
      } else {
        digitalWrite(pump_pin, LOW);
      }
      break;
    case 3:
      digitalWrite(pump_pin, HIGH);
      break;
  }

  // send the 'leds' array out to the actual LED strip
  // insert a delay to keep the framerate modest
  if (millis() - led_timer > TIME_BETWEEN_FRAMES) {
    FastLED.show();
    led_timer = millis();
  }

  // do some periodic updates
  //  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  //  EVERY_N_SECONDS( 10 ) { nextPattern(); } // change patterns periodically
}

//////////////////////////// ENCODER/BTN UPDATES ////////////////////////////

// READ ENCODER CHANGES
int updateEncoder(int i) {
  encoder[i]->tick(); // track any changes
  int newPos = encoder[i]->getPosition(); // get new position
  int changePos = newPos - pos[i]; // note change in position
  pos[i] = newPos; // update position
  return changePos; // return change
} //updateEncoder(i)

// READS BUTTON PRESS
bool readButton(int i) {

  btnState[i] = digitalRead(SW[i]); // Read the button state

  // if button is pressed, and was not previously pressed within the last 200ms, record a press
  // helps with debouncing / multiple presses being recorded in a row
  bool btnPressed = (btnState[i] == LOW) && (millis() - lastButtonPress[i] > 200); 

  // if button is currently pressed, update lastPressed timer
  lastButtonPress[i] = (btnState[i] == LOW) ? millis() : lastButtonPress[i];

  // return if a button press is recorded
  return btnPressed;
} //readButton(i)


//////////////////////////// STATE MACHINE ////////////////////////////

// changes the state when a button press is recorded
void setState() {
  Serial.print("prior state: ");
  Serial.println(state);

  // menu select state
  if (state == -1) {
    // set state to correct menu
    state = menu_pos;

    // reset menu selector to 0
    setter = 0;

    //turn on cursor to show in menu
    lcd.blink();

    //menu specific code
    switch (menu_pos) {
      // sleep mode
      case 0:
        lcd.noBacklight();
        break;

      // set time
      case 1:
        lcd.setCursor(1, 1);
        break;
    }

    // print the correct menu
    printMenu();

    // if necessary, put cursor in correct position
    if (state == 1) {
      lcd.setCursor(1 + setter * 3, 1);
    } 
  }
  // set time, (setter == 3) = set minutes; (setter == 3 && button) = done with menu
  else if (state == 1 && setter < 3) {
    setter++;
    lcd.setCursor(1 + setter * 3, 1);
  }
  // set LED timer, and setting LED "on at" time
  else if (state == 5 && setter < 2 && led_auto == 2) {
    setter++;
    lcd.setCursor(5 + setter * 3, 1);
  }
  // set pump timer, and setting "on for" time
  else if (state == 4 && setter < 2 && pump_auto == 2) {
    setter++;
    lcd.setCursor(5 + setter * 3, 1);
  }
  // all other menus have only one select
  else if (state >= 0 ) {
    //apply specific changes if necessary, go back to menu
    switch (state) {
      case 4:
      case 5:
        updateTime(false);
        break;
    }

    // print the new menu, and turn off the cursor
    printMenu();
    lcd.noBlink();
    lcd.backlight();

    // set state back to menu select
    state = -1;
  }

  Serial.print("  new state: ");
  Serial.println(state);
} //setState();


// Updates selector based on current state and setter
void updateStateParams(int change) {

  // current state
  switch (state) {
    // menu select
    case -1:
      menu_pos = (menu_pos + change + menu_length) % menu_length;
      clearLine(0);
      lcd.print(menu_items[menu_pos]);

      break;

    // set time
    case 1:
      setTime(change);
      break;

    // led pattern
    case 2:
      nextPattern(change);
      break;

    // led brightness
    case 3:
      brightness = min(max(0, brightness + change * 25), 250);
      FastLED.setBrightness(brightness);
      break;

    // pump timer
    case 4:
      switch (setter) {
        case 0:
          pump_auto = (pump_auto + change + 4) % 4; // set timer option
          break;
        case 1:
          pump_auto_hour = min(max(pump_auto_hour + change, 0),10); //update auto hour
          break;
        case 2:
          pump_auto_minute = (pump_auto_minute + change + 60) % 60; //update auto minute
          break;
      }
      break;

    // led timer
    case 5:
      switch (setter) {
        case 0:
          led_auto = (led_auto + change + 4) % 4; // set timer option
          break;
        case 1:
          led_auto_hour = (led_auto_hour + change + 24) % 24; //update auto hour
          break;
        case 2:
          led_auto_minute = (led_auto_minute + change + 60) % 60; //update auto minute
          break;
      }
      break;

  }
  // print updated menu
  printMenu();

} // updateStateParams(int change)

// Helper function to change the time
void setTime(int change) {
  switch (setter) {
    case 0:
      month += change;
      break;

    case 1:
      day += change;
      break;

    case 2:
      h += change;
      break;

    case 3:
      m += change;
      s = 0;
      break;
  }

  clearLine(1);
  updateTime(true);
} // setTime(int change)

// Updates the time when required, and every loop
// bool parameter if desire automatic menu update
void updateTime(bool printed) {
  bool updateflag = false; // tracks if menu is supposed to be updated
  if (printed) updateflag = true; 

  // if more than a second has passed, seconds++
  if (millis() - last_time > 1000) {
    last_time += 1000;
    s++;
  }

  // if more than a minute has passed, minutes++, reset seconds
  // some functions update on minute change
  if (s >= 60) {
    s = 0;
    m++;
    updateflag = true;
    
    // pump_timer--
    if (pump_auto == 2) {
      pump_auto_minute--;
      if (pump_auto_minute < 0) {
        pump_auto_hour--;
        pump_auto_minute == 59;
      }
      if (pump_auto_hour < 0) {
        pump_auto = 0;
        pump_auto_hour = 0;
        pump_auto_minute = 0;
      }
    }
  }

  // if minutes > 59, hours++, reset minutes
  if (m >= 60) {
    m = 0;
    h++;
    updateflag = true;
  }
  // negative minute incrementing for setTime
  if (m < 0) {
    m = 59;
    h--;
    updateflag = true;
  }

  // if hours > 23, new day, reset hours
  // update daily/new day functions
  if (h >= 24) {
    h = 0;
    updateflag = true;
    day++;

    // if LED or pump set to "on until midnight", reset to default
    if (led_auto == 3) {
      led_auto = 1; // sunset timer
    }
    if (pump_auto == 3) {
      pump_auto = 0; // off
    }

    // check if daylight savings changes
    if (day == 14 && month == 3) {
      //daylight savings start
      savings = true;
    }
    if (day == 7 && month == 11) {
      //daylight savings ends
      savings = false;
    }
  }
  // negative increment for setTime
  if (h < 0) {
    h = 23;
    updateflag = true;
    day--;
  }
  
  // checks if month increments/day resets to 1
  updateDayMonth();

  // update sunset time for new day
  todays_sunset = albany.sunset(year, month, day, false);

  
  // if updateflag, reprint menu with changes
  if (updateflag == true) printMenu();
}

// helper function; prints date+time
void printTime() {
  if (month < 10)lcd.print("0");
  lcd.print(month);
  lcd.print("/");
  if (day < 10)lcd.print("0");
  lcd.print(day);
  lcd.print(" ");
  manualTime(h, m);
}

// prints current menu's title
void printHeader() {
  lcd.setCursor(0, 0);
  lcd.print(menu_items[pos[0]]);
} //printHeader()

// prints current menu's details
void printMenu() {
  clearLine(1);
  switch (menu_pos) {
    // sleep mode
    case 0:
      printTime();
      break;

    // set time
    case 1:
      printTime();
      break;

    // set led pattern
    case 2:
      lcd.print(pattern_list[gCurrentPatternNumber]);
      break;

    // set led brightness
    case 3:
      lcd.print((int)(brightness*10/25));
      lcd.print("%");
      break;

    // set pump timer
    case 4:
      switch (pump_auto) {
        case 0:
          lcd.print("OFF");
          break;
        case 1:
          lcd.print("SUNSET ");
          manualTime(todays_sunset / 60, todays_sunset % 60);
          break;
        case 2:
          lcd.print("ON FOR ");
          if(pump_auto_hour < 10) lcd.print("0");
          lcd.print(pump_auto_hour);
          lcd.print(":");
          if(pump_auto_minute < 10) lcd.print("0");
          lcd.print(pump_auto_minute);
          break;
        case 3:
          lcd.print("ON TIL MIDNIGHT");
          break;
      }
      break;

    // set LED timer
    case 5:
      switch (led_auto) {
        case 0:
          lcd.print("OFF");
          break;
        case 1:
          lcd.print("SUNSET ");
          manualTime(todays_sunset / 60, todays_sunset % 60);
          break;
        case 2:
          lcd.print("TIME   ");
          manualTime(led_auto_hour, led_auto_minute);
          break;
        case 3:
          lcd.print("ON TIL MIDNIGHT");
          break;
      }
      break;
  }

}

// helper function to clear i'th row of LCD and set cursor
void clearLine(int line_idx) {
  lcd.setCursor(0, line_idx);
  lcd.print("                "); //prints 16 spaces (length of LCD)
  lcd.setCursor(0, line_idx);
}

// helper function to print specificed "hours:minutes am/pm"
void manualTime(int hours, int minutes) {
  int hmod = (hours + (savings == true) * 1) % 24;
  int hmod2 = hmod % 12 + (hmod == 0 || hmod == 12) * 12;
  if (hmod2 < 10)lcd.print("0"); // always 2 digits
  lcd.print(hmod2);
  lcd.print(":");
  if (minutes < 10)lcd.print("0");
  lcd.print(minutes);

  String ampm = (hmod > 11) ? " PM" : " AM";
  lcd.print(ampm);
}

// helper function, checks if month incremenets/decrements
void updateDayMonth() {

  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (day > 31) {
        day = 1;
        month++;
      }
      break;
    case 2:
      if (day > 28) {
        day = 1;
        month++;
      }
      break;
    default:
      if (day > 30) {
        day = 1;
        month++;
      }
  }
  if (day < 1) {
    month--;
    switch (month) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
        day = 31;
        break;
      case 2:
        day = 28;
        break;
      default:
        day = 30;
    }
  }

  if (month > 12) {
    month = 1;
    year++;
  }
  if (month < 1) {
    month = 12;
    year--;
  }

}


//LED PATTERNS
////////////////////////////////////////////////////////////////////////////////////////////

void nextPattern(int change)
{
  // add/subtract one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + change + NUMITEMS( gPatterns)) % NUMITEMS( gPatterns);
}


void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter)
{
  if ( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int ledpos = random16(NUM_LEDS);
  leds[ledpos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS - 1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue + (i * 2), beat - gHue + (i * 10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for ( int i = 0; i < 8; i++) {
    leds[beatsin16( i + 7, 0, NUM_LEDS - 1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

void sparkle() {
//  fill_solid(leds,NUM_LEDS,CRGB::White);
  for ( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = CRGB(brightness/2, brightness/2, brightness/2);
  }
  if ( random8() < 80) {
    int i = random16(NUM_LEDS);
    leds[i] = CRGB(brightness, brightness, brightness);
  }
}

void setWhite() {
  fill_solid(leds,NUM_LEDS,CRGB::White);
}


void setBlack() {
  fill_solid(leds, NUM_LEDS, CRGB::Black);
}
