
%% unit prefixes
k = 10^3;  %kilo
M = 10^6;  %mega

m = 10^-3; %milli
u = 10^-6; %micro
n = 10^-9; %nano
p = 10^-12;%pico

%% constants
Kboltz = 1.38065e-23; %boltzman constant
q_electron = 1.602177e-19; % magnitude of the charge of electron in coulombs
zero_C = -274.15; % absolute zero in Celcius 

%% functions
g2db = @(g) 20*log10(g); %convert gain to decibels
db2g = @(db) 10^(db/20); %convert decibels to gain

% calculates parallel resistance (or series capacitance), takes vector input
parallel = @(Z_values) 1/sum(1./Z_values);

% complex impedance for capacitors and inductors
% use the desired complex or symbolic variable as the 's' parameter
ZL = @(L,s) L*s;
ZC = @(C,s) 1/(C*s);

hz2rads = @(hz) hz*2*pi;
rads2hz = @(rads) rads/(2*pi);

