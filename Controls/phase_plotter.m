
%% plot phase portrait compute multiple trajectories (via the ode45)

f = @(t,x) [x(1) - x(1)*x(2); -x(2)+x(1)*x(2)];

[Xs, Ys] = meshgrid(2:2:10, 2:2:10);
t_span = [0, 20];   % specify the simulation time duration

% initialize the cell for storing
x_traj_store = {numel(Xs),1};
t_store = {numel(Xs),1};
for i = 1:numel(Xs)
    % calling ode45 (ODE solver basded on Runge-Kutta-Fehlberg method)
    [t, x_traj]=ode45(f, t_span, [Xs(i),Ys(i)]);
    % use cell to store the computed trajectory
    x_traj_store{i} = x_traj;
    t_store{i} = t;
end

%% plot trajectory
figure
hold on
% plot each trajectory in a for loop
for i = 1:numel(x_traj_store)
    x_traj = x_traj_store{i};
    f = plot(x_traj(:,1),x_traj(:,2));
end

hold off
title('Volterra Function Phase Portrait')
xlabel('x_1','FontSize',16)
ylabel('x_2','FontSize',16)
grid on
xlim([-2 20])
ylim([-2 20])