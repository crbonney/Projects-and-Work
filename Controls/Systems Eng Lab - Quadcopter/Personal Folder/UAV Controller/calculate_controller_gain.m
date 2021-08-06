
load('decoupled_system')
load('In_out_data')

% Calculate Covariances 
q_single = cov(out.In_Out_Data{1}.Values.Data); % input data
r_single = cov(out.In_Out_Data{2}.Values.Data); % output data

% don't worry about size of Q, the lqe function handle it
% q_double = q_single;
% r_double = r_single;

%for states we dont care about
q_small = 0.01;
%because we don't care about input
r = 0.01;
%for states we care about
q = 1;

% states: z,w; care about z,w
thrust_ss = ss(Athrust,Bthrust,Cthrust,Dthrust);
[K_thrust,S_thrust,Eig_thrust] = lqr(thrust_ss, diag([q;q]), r)

% states: X,u,theta,q; care about u,theta,q
elevator_ss = ss(Aelevator,Belevator,Celevator,Delevator);
[K_elevator,S_elevator,Eig_elevator] = lqr(elevator_ss, diag([q_small;q_small;q;q]), r)

% states: Y,v,phi,p; care about v,phi,p
aileron_ss = ss(Aaileron,Baileron,Caileron,Daileron);
[K_aileron,S_aileron,Eig_aileron] = lqr(aileron_ss, diag([q_small;q_small;q;q]), r)

% states: psi,r; care about neither much
rudder_ss = ss(Arudder,Brudder,Crudder,Drudder);
[K_rudder,S_rudder,Eig_rudder] = lqr(rudder_ss, diag([q_small;q]), r)

% Athrust-Bthrust*K_thrust
% Aelevator-Belevator*K_elevator
% Aaileron-Baileron*K_aileron
% Arudder-Brudder*K_rudder

