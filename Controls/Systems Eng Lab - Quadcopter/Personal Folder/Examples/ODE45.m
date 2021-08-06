

x_0 = [3;5];
mu = 4;
timespan = linspace(0,10,100);
f = @(x,y) [mu*(x-1/3*x^3-y);1/mu*x];

% f = @(t,x) [mu*(x(1)-1/3*x(1)^3-x(2));1/mu*x(1)]
%[t,X] = ode45(f,[0 100],[0.1 0]);
[t,state] = ode45( @(t,z) f(z(1),z(2)),timespan, x_0);

plot(state(:,1),state(:,2));

