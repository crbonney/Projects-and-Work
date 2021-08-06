Vp = 3;             % positive voltage peak
Vn = 0.5;           % negative voltage peak
tau = 1.866*10^-3;  % RC time constant
T = 1/50;           % period of offset square wave

k = @(t) t - T/2*floor(t/(T/2)); %resets t for the decay every T/2

% equation for exponential wave
V = @(t) (mod(t,T) < T/2).*Vp.*exp(-k(t)./tau) - (mod(t,T) >= T/2).*Vn.*exp(-(k(t))/tau);

% plot exponential wave
figure
fplot(V,[0, 0.1])
grid on
title('Pseudo-Exponential Waveform')
ylabel('voltage (V)')
xlabel('time (s)')


% generate data for FFT
n = 100000;
t = linspace(0,1,n);
Vt = V(t);

% take FFT
ffV = fft(Vt);

% plot FFT of the waveform
figure
plot(abs(ffV(1:500))/n);
grid on
title('Harmonics of Pseudo-Exponential Wave')
xlabel('frequency (Hz)')
ylabel('V_{rms} (V)')

