% Creating Linear and Nonlinear Model Variables


%% Defining Variables
syms x y z u v w phi theta psi p q r n1 n2 n3 n4

% states = [x,y,z,u,v,w,phi,theta,psi,p,q,r];

% Altenate state definitions to make couplings visible
states = [x,u,theta,q,y,v,phi,p,z,w,psi,r];
inputs = [n1,n2,n3,n4];
trim_state = [0,0,0,0,0,0,0,0,0,0,0,0];
%n trim = 293 Hz;
trim_input = [293,293,293,293]; %TEAR

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
thrust_eq = @(n) [(C_T(1)+C_T(2)*n).*(n.^2)*rho*(prop_dia^4)];
power_eq  = @(n) [(C_P)*(n.^3)*rho*(prop_dia^5)];

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

phi_dot   = [p + tan(theta)*(q*sin(phi) + r*cos(phi))];
theta_dot = [q*cos(phi) - r*sin(phi)];
psi_dot   = [(q*sin(phi) + r*cos(phi))/cos(theta)];

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
 
% Altenate state definitions to make couplings visible
J_x =      [...
        J_NED(1,:) ;...
        J_V(1,:)   ;...
        J_angle(2,:);...
        J_omega(2,:);...
        J_NED(2,:) ;...
        J_V(2,:)   ;...
        J_angle(1,:);...
        J_omega(1,:);...
        J_NED(3,:) ;...
        J_V(3,:)   ;...
        J_angle(3,:);...
        J_omega(3,:);...
];
J_x_n =      [...
        J_NED_n(1,:) ;...
        J_V_n(1,:)   ;...
        J_angle_n(2,:);...
        J_omega_n(2,:);...
        J_NED_n(2,:) ;...
        J_V_n(2,:)   ;...
        J_angle_n(1,:);...
        J_omega_n(1,:);...
        J_NED_n(3,:) ;...
        J_V_n(3,:)   ;...
        J_angle_n(3,:);...
        J_omega_n(3,:);...
];

        
% J_x =       [...
%              J_NED    ;...
%              J_V      ;...
%              J_angle  ;...
%              J_omega  ;...
% ];
% J_x_n =     [...
%              J_NED_n  ;...
%              J_V_n    ;...
%              J_angle_n;...
%              J_omega_n;...
% ];

%% Evaluate Jacobians at Trim
A = double(round(subs(J_x,   [states, inputs], [trim_state, trim_input])*1000)/1000);
B = double(round(subs(J_x_n, [states, inputs], [trim_state, trim_input])*1000)/1000);

h = -z;
a_NED = F_T/UAV_mass;

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

%% Decouple States

% Thrust
% Z,w
Athrust = A(9:10,9:10);
Bthrust = B(9:10,1);
% Z,h,az
Cthrust = [ 1 0; -1 0; 0 0];  
Dthrust = [0 ; 0 ; D(4,1)];

% Elevator
% X,u,theta,q
Aelevator = A(1:4,1:4);
Belevator = B(1:4,2);
% u,q,ax
Celevator = [0 1 0 0; 0 0 0 1; 0 0 0 0];
Delevator = [0 ; 0 ; 0];

% Aileron
% Y,v,phi,p
Aaileron = A(5:8,5:8);
Baileron = B(5:8,3);
% v,p,ay
Caileron = [0 1 0 0; 0 0 0 1; 0 0 0 0];
Daileron = [0 ; 0 ; 0];

% Rudder
% psi,r
Arudder = A(11:12,11:12);
Brudder = B(11:12,4);
% r
Crudder = [0 1];
Drudder = 0;

%% Clear extra variables
clearvars -except A B C D ...
                  Athrust Bthrust Cthrust Dthrust ...
                  Aelevator Belevator Celevator Delevator ...
                  Aaileron Baileron Caileron Daileron ...
                  Arudder Brudder Crudder Drudder ...                  
                  C_P C_rollpitch C_T C_yaw ...
                  g J Jinv Jprop MotorMix ...
                  Prop_H Thrust_Sum trim_input trim_state UAV_mass

%% Controllability/Observability (not used)
% 
% % Thrust: Con + Obs
% Wthrust = [Bthrust Athrust*Bthrust];
% thrustCon = (rank(Wthrust) == 2); 
% 
% Mthrust = [Cthrust; Cthrust*Athrust]';
% thrustObs = (rank(Mthrust) == 2);
% 
% % Elevator: Con, not Obs (no Y)
% Welevator   = [Belevator Aelevator*Belevator Aelevator^2*Belevator Aelevator^3*Belevator];
% elevatorCon = (rank(Welevator) == 4);
% 
% Melevator   = [Celevator; Celevator*Aelevator; Celevator*Aelevator^2; Celevator*Aelevator^3]';
% elevatorObs = (rank(Melevator) == 4);
% 
% % Aileron: Con, not Obs (no X)
% Waileron   = [Baileron Aaileron*Baileron Aaileron^2*Baileron Aaileron^3*Baileron];
% aileronCon = (rank(Waileron) == 4);
% 
% Maileron   = [Caileron; Caileron*Aaileron; Caileron*Aaileron^2; Caileron*Aaileron^3]';
% aileronObs = (rank(Maileron) == 4);
% 
% % Rudder: Con, not Obs (no psi)
% Wrudder = [Brudder Arudder*Brudder];
% rudderCon = (rank(Wrudder) == 2);
% 
% Mrudder = [Crudder; Crudder*Arudder]';
% rudderObs = (rank(Mrudder) == 2);
% 
% %% Eigenvectors and Values
% 
% %all 0 eig values, just care about calculating eig_vectors
% [eigVec_thrust, eigVal_thrust] = eig(Athrust);
% %eigVal = diag(eigValues) -> turn into row vector
% eigVal_thrust = [1 1]*eigVal_thrust;
% 
% [eigVec_elevator, eigVal_elevator] = eig(Aelevator);
% eigVal_elevator = [1 1 1 1]*eigVal_elevator;
% 
% [eigVec_aileron, eigVal_aileron] = eig(Aaileron);
% eigVal_aileron = [1 1 1 1]*eigVal_aileron;
% 
% [eigVec_rudder, eigVal_rudder] = eig(Arudder);
% eigVal_rudder = [1 1]*eigVal_rudder;
