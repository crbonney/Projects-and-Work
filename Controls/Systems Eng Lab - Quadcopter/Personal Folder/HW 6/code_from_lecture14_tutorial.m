load('Lecture14')
syms t
A = [ 0 1 ; 0 0 ];
B = [0 ; 1];

A_sampled = expm(A*t)
B_sampled = int(expm(A*t))*B
t = 0.005

eval(subs(A_sampled,t))

A_s = eval(subs(A_sampled,t))
B_s = eval(subs(B_sampled,t))


out
out.InputData
plot(out.InputData{2})
y=out.InputData{2}.Values.Data
q = cov(out.InputData{2}.Values.Data)

out
out.OutputData
plot(out.OutputData{2})
r = cov(out.OutputData{2}.Values.Data)

%Calculate vector covariance
cov(u,y)


% Wiener Filter code
A_cont = [0 1 ; 0 0 ]
B_cont = [0 ; 1]
C_cont = [1 0 ]
D_cont = [0]
G_cont = B_cont; % noise input is same as process input
% Gain for the Wiener filter
L = lqe(A_cont, G_cont, C_cont, q, r, 0)