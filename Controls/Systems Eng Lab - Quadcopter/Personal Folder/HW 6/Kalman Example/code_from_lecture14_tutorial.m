load('Lecture14')
syms t
%continuous double integrator
A = [ 0 1 ; 0 0 ];
B = [0 ; 1];

%e^A(delta)t = discrete A matrix
A_sampled = expm(A*t)
%int (e^A(delta)t)*B = discrete B matrix
B_sampled = int(expm(A*t))*B

%deltaT = 1/200
t = 0.005

% create discrete matrices from symbolic
A_s = eval(subs(A_sampled,t))
B_s = eval(subs(B_sampled,t))


out
out.InputData
%show data from InputData scope
plot(out.InputData{2})
%get data from structure (noisy)
u=out.InputData{2}.Values.Data
%covariance of input data (w/ noise)
q = cov(out.InputData{2}.Values.Data)
%~ 21.1

out.OutputData
%show data from OutputData scope
plot(out.OutputData{2})
%get data from structure (noisy)
y = out.OutputData{2}.Values.Data
%covariance of output data (w/ noise)
r = cov(out.OutputData{2}.Values.Data)
%~171.4


%%% what we want
%Calculate vector covariance
cov(u,y)
% cov(u,y) = [cov(u)   crosscov(u,y) ;
%             crosscov(u,y)   cov(y) ]
%          = [21.1    2.05 ;
%             2.05   171.4 ]
% if off-diag is 0 (small), no relation between u,y
 
% Wiener Filter code
A_cont = [0 1 ; 0 0 ]
B_cont = [0 ; 1]
C_cont = [1 0 ]
D_cont = [0]
G_cont = B_cont; % noise input is same as process input
% Gain for the Wiener filter
L = lqe(A_cont, G_cont, C_cont, q, r, 0)