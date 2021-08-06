
Lp = -3; %has to be negative
Ld =  1;

A = [0 1 ; ...
     0 Lp; ...
]; 

B = [0 ; ...
     Ld; ...
];

C = eye(2); %y = [x1; x2];
D = [0 ; 0];

sys_plant = ss(A, B, C, D); %creates a system

k = 10*2*pi; %10 Hz

s = tf('s');
filter = k/(s+k)*eye(2);

%FOR PID CONTROLLER

K_iphi = 1;
K_phi = 0.1;
K_p = 3;

controller = [-K_iphi/s - K_phi, K_p];

% L = K * F * G
Loop_transfer = controller * filter * sys_plant;

L_tf = tf(Loop_transfer);

% solve for s in 1 + L = 0

poles = zero(1+L_tf);

minimum_realization = minreal(L_tf);