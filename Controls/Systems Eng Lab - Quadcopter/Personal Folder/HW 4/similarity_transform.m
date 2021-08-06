% Transforming code from HW3/Calculating_Jacobians

%% Defining Variables
syms x y z u v w phi theta psi p q r n1 n2 n3 n4

%starting state
states = [x,y,z,u,v,w,phi,theta,psi,p,q,r];

% desired state after transform
% new_states = [z,w,theta,q,phi,p,psi,r,x,u,y,v];

% Transformation Matrix X' = TX
T =     [... x  y  z  u  v  w phi theta psi p  q  r
             0  0  1  0  0  0  0    0    0  0  0  0 ;... x
             0  0  0  0  0  1  0    0    0  0  0  0 ;... y
             0  0  0  0  0  0  0    1    0  0  0  0 ;... z
             0  0  0  0  0  0  0    0    0  0  1  0 ;... u
             0  0  0  0  0  0  1    0    0  0  0  0 ;... v
             0  0  0  0  0  0  0    0    0  1  0  0 ;... w
             0  0  0  0  0  0  0    0    1  0  0  0 ;... phi
             0  0  0  0  0  0  0    0    0  0  0  1 ;... theta
             1  0  0  0  0  0  0    0    0  0  0  0 ;... psi
             0  0  0  1  0  0  0    0    0  0  0  0 ;... p
             0  1  0  0  0  0  0    0    0  0  0  0 ;... q 
             0  0  0  0  1  0  0    0    0  0  0  0 ;... r 
];             

inputs = [n1,n2,n3,n4];
trim_state = [0,0,0,0,0,0,0,0,0,0,0,0];
%n trim = 293 Hz;
trim_input = [293,293,293,293];

%% Rotation Matricies
R_phi = [...
        1       0       0      ;...
        0   cos(phi)  sin(phi) ;...
        0  -sin(phi)  cos(phi) ;...
];

R_theta = [...
        cos(theta)  0  -sin(theta) ;...
             0      1        0     ;...
        sin(theta)  0   cos(theta) ;...
];

R_psi = [...
         cos(psi)  sin(psi)  0 ;...
        -sin(psi)  cos(psi)  0 ;...
            0         0      1 ;...
];

Rotate_angles = R_phi*R_theta*R_psi;

Unrotate_angles = Rotate_angles';

%% System Constants
C_T = [0.069075;4.95e-05]; %C_T(n) = C_T(1) + C_T(2)*n
C_P = 0.041;
rho = 1.22495; % kg/m3
prop_dia = 0.066; %meters
UAV_mass = 0.068; %kg
thrust_eq = @(n) (C_T(1)+C_T(2)*n).*(n.^2)*rho*(prop_dia^4);
power_eq  = @(n) (C_P)*(n.^3)*rho*(prop_dia^5);

Jxx = 0.0000582857;
Jyy = 0.0000716914;
Jzz = 0.0001;
J = [... %Moment of Inertia Matrix of UAV
     Jxx   0   0 ;...
      0   Jyy  0 ;...
      0    0  Jzz;...
];

g = [0;0;UAV_mass*9.81];
F_G = Rotate_angles*g;

Jinv = inv(J);

prop_dist = sqrt(2)*0.09; %meters
prop_mass = 0.001; %kg (1 gram)

prop_mass_moment = 1/12*(prop_dia^2)*prop_mass;
%Moment of Inertia of propller in UAV frame (only care about Z component)
Jprop = prop_mass_moment + prop_mass*(prop_dist^2);

%% Matrices for Propellers in Simulink Nonlinear Model
%for summing prop angular momentums accounting for direction
%H = Prop_H*n
Prop_H = 2*pi*Jprop*[...
              0  0  0  0 ;...
              0  0  0  0 ;...
              1 -1  1 -1 ;...
];

%Calculates M_T for roll/pitch
%M_roll/pitch = diag(C_T(n))*C_rollpitch*[n.^2]
C_rollpitch    = rho*prop_dia^4*prop_dist/sqrt(2)*[...
                1  -1  -1   1 ;...
                1   1  -1  -1 ;...
                0   0   0   0 ;...
];
%Calculates M_T for yaw
%M_yaw = C_P.*C_yaw*[n.^2]
C_yaw          =   rho*prop_dia^5/(2*pi)*[...
                0   0   0   0 ;...
                0   0   0   0 ;...
               -1   1  -1   1 ;...
];
%M_T = M_rollpitch + M_yaw


%Calculates total thrust from propellers
%F_T = Thrust_sum*[n.^2].*C_T(n) 
Thrust_Sum = rho*prop_dia^4*[...
                0   0   0   0 ;...
                0   0   0   0 ;...
               -1  -1  -1  -1 ;...
];

MotorMix = [...%T  E  A  R
                1  1  1 -1 ;... %n1
                1  1 -1  1 ;... %n2
                1 -1 -1 -1 ;... %n3
                1 -1  1  1 ;... %n4
];

%% Calculating Jacobians
thrust = thrust_eq(n1) + thrust_eq(n2) + thrust_eq(n3) + thrust_eq(n4);
F_T = [0; 0; -(thrust)];

phi_dot   = p + tan(theta)*(q*sin(phi) + r*cos(phi));
theta_dot = q*cos(phi) - r*sin(phi);
psi_dot   = (q*sin(phi) + r*cos(phi))/cos(theta);

angle_dot = [phi_dot; theta_dot; psi_dot];
J_angle   = jacobian(angle_dot, states);
J_angle_n = jacobian(angle_dot, inputs);
% J_angle_trim = subs(J_angle, states, trim_state);

NED_dot = Unrotate_angles*[u; v; w];
J_NED   = jacobian(NED_dot, states);
J_NED_n = jacobian(NED_dot, inputs);
% J_NED_trim = subs(J_NED, states, trim_state);

V_dot = (F_G + F_T)/UAV_mass - cross([p;q;r],[u;v;w]);
J_V   = jacobian(V_dot, states);
J_V_n = jacobian(V_dot, inputs);
% J_V_trim = subs(J_V, states, trim_state);

M_gyro = cross([p;q;r], Jprop*2*pi*(n1-n2+n3-n4)*[0;0;1]);

M_roll_pitch = thrust_eq(n1)*prop_dist*[ 1/sqrt(2);  1/sqrt(2); 0] + ...
               thrust_eq(n2)*prop_dist*[-1/sqrt(2);  1/sqrt(2); 0] + ...
               thrust_eq(n3)*prop_dist*[-1/sqrt(2); -1/sqrt(2); 0] + ...
               thrust_eq(n4)*prop_dist*[ 1/sqrt(2); -1/sqrt(2); 0] ; 

M_yaw        = power_eq(n1)/(n1*2*pi)*[0; 0; -1] + ...
               power_eq(n2)/(n2*2*pi)*[0; 0;  1] + ...
               power_eq(n3)/(n3*2*pi)*[0; 0; -1] + ...
               power_eq(n4)/(n4*2*pi)*[0; 0;  1] ;               

M_T = M_roll_pitch + M_yaw;

omega_dot = J\(M_T + M_gyro - cross([p;q;r],J*[p;q;r]));
J_omega   = jacobian(omega_dot, states);
J_omega_n = jacobian(omega_dot, inputs);
% J_omega_trim = subs(J_omega, states, trim_state)
        
J_x =       [...
             J_NED    ;...
             J_V      ;...
             J_angle  ;...
             J_omega  ;...
];
J_x_n =     [...
             J_NED_n  ;...
             J_V_n    ;...
             J_angle_n;...
             J_omega_n;...
];

%% Evaluate Jacobians at Trim
A = double(round(subs(J_x,   [states, inputs], [trim_state, trim_input])*1000)/1000);
B = double(round(subs(J_x_n, [states, inputs], [trim_state, trim_input])*1000)/1000);

h = -z;
a_NED = Unrotate_angles*F_T/UAV_mass;

J_h   = jacobian(h, states);
J_h_n = jacobian(h, inputs);

J_a_NED   = jacobian(a_NED, states);
J_a_NED_n = jacobian(a_NED, inputs);

J_y =     [...
           J_h       ;...
           J_a_NED   ;...
];
      
J_y_n =     [...
           J_h_n     ;...
           J_a_NED_n ;...
];

C = double(round(subs(J_y,   [states, inputs], [trim_state, trim_input])*1000)/1000);
D = double(round(subs(J_y_n, [states, inputs], [trim_state, trim_input])*1000)/1000);

%% Transform states
% using TEAR as input   
B = B*MotorMix;
D = D*MotorMix;

% transform
A = T*A/T;
B = T*B;
C = C/T;
% D = D;

%% state decoupling

% Thrust
% Z,w
TA = A(1:2,1:2);
TB = B(1:2,1);
% Z,w,h,az
TC = eye(4);
TD = zeros(4,1);

% Elevator
% X,u,theta,q
EA = A(3:6,3:6);
EB = B(3:6,2);
% X,u,theta,q,ax
EC = eye(5);
ED = zeros(5,1);

% Aileron
% Y,v,phi,p
AA = A(7:10,7:10);
AB = B(7:10,3);
AC = eye(5);
AD = zeros(5,1);

% Rudder
% psi,r
RA = A(11:12,11:12);
RB = B(11:12,4);
% psi,r
RC = eye(2);
RD = zeros(2,1);


%% Clear extra variables
% clearvars -except A B C D C_P C_rollpitch C_T C_yaw g J Jinv Jprop MotorMix Prop_H Thrust_Sum trim_input trim_state UAV_mass