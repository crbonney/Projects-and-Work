clear all;
close all;

%% Paramaters and System Defenition
%parameters of Lorenz Eq'ns
rho = 10;
sigma = 1.1;
beta = 2/3;

%define system of ODEs
f = @(t,x) [sigma*(x(2)-x(1));x(1)*(rho-x(3))-x(2);x(1)*x(2)-beta*x(3)];

%% Create Phase portrait
%Create grid for phase portrait (x,y,z have same values)
x = -30:10:30; 
%size of gride
len = length(x)^3;

%create empty array to hold ode45 sol'ns for all points in grid
t_phase = zeros(len,4000,1);
X_phase = zeros(len,4000,3);

%nth data point (n=1:len)
n=1;
for i=1:length(x)
    for j=1:length(x)
        for k=1:length(x)
            %solve for each point on grid
            [t,X]= ode45(f, [0 20], [x(i) x(j) x(k)]);
            soln_len = length(t);
            %append 0s to sol'n to make it same dims as t_phase, X_phase
            t(numel(t_phase(n,:))) = 0;
            X(numel(t_phase(n,:)),:) = 0;

            %store the values of the sol'n
            t_phase(n,:) = t;
            t_phase(n,1) = soln_len; %stores the num steps of the sol'n for plotting
            X_phase(n,:,:) = X;
            n=n+1;
        end
    end
end

% PHASE PORTRAIT
figure;

%plots all sol'ns
for n=1:len
    %plots only the number of steps in the sol'n for each initial condition
    plot3(X_phase(n,1:t_phase(n,1),1), X_phase(n,1:t_phase(n,1),2), X_phase(n,1:t_phase(n,1),3));
    hold on;
end

grid on;
title('Phase Portrait');
xlabel('x');
ylabel('y');
zlabel('z');

%VECTOR FIELD
%create grid 
[x,y,z] = meshgrid(-50:10:50);

%calculate force vector at each point
u = sigma.*(y-x); %x_dot
v = x.*(rho-z);   %y_dot
w = x.*y-beta.*z; %z_dot

%calculate one random sol'n to plot for reference in field graph
[t,X] = ode45(f, [0,20], [50,40,20]);

figure;
%quiver plots vector field for each point in the mesh
quiver3(x,y,z,u,v,w,3);
hold on;
plot3(X(:,1), X(:,2), X(:,3));
grid on;
title('Vector Field Plot');
xlabel('x');
ylabel('y');
zlabel('z');

%TIME SERIES
%uses sol'n from ode45 in vector field
figure;
%subplots x,y,z over time for sol'n
subplot(3,1,1);
plot(t,X(:,1));
ylabel('x');
subplot(3,1,2);
plot(t,X(:,2));
ylabel('y');
subplot(3,1,3);
plot(t,X(:,3));
ylabel('z');
