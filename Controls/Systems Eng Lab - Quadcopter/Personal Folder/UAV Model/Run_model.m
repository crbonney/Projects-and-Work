function Run_model(input,states_shown,outputs_shown)
%% Instructions
% input binary vector for subsystems desired to be shown
% parentheses are location of data within data vector
% States:  [Position (1,5,9), Velocity (2,6,10), Angles (7,3,11), Angular Velocity (8,4,12)]
% Outputs: [u,ax (1:2), v,ay (4:5), z,az (7:8), p,q,r (6,3,9)]

%% Run simulation, get data
out = sim('Drone_Model', [0 1]);

% linear
% states = (out.linearstates.Data);
% output = (out.linearoutput.Data);
% kalman = (out.linearkalman.Data);
% time   = (out.linearstates.Time);

% nonlinear
states = squeeze(out.nonlinearstates.Data)';
output = (out.nonlinearoutput.Data);
kalman = (out.nonlinearkalman.Data);
time   = (out.nonlinearstates.Time);

%% Plot states
% decide on num of plots needed
n_states = nnz(states_shown);
if (n_states == 1)
    subplot_size = [1,1];
elseif (n_states == 2)
    subplot_size = [1,2];
else 
    subplot_size = [2,2];
end

figure('Color', 'w');
sgtitle(['System States, Input: ' input]);
plot_num = 1;
% Make subplots
for i=1:4
    if (states_shown(i))
        switch i            
            case 1

                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,states(:,[1,5,9]));
                hold on
                plot(time,kalman(:,4));
                title('Linear Position States');
                legend({'X_{NED}','Y_{NED}','Z_{NED}','Z_{e_{NED}}'},'Location','Best');
                ylabel('position (m)');
                xlabel('time (s)');

                plot_num = plot_num + 1;
            case 2

                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,states(:,[2,6,10]));
                hold on
                plot(time,kalman(:,1:3));
                title('Linear Velocity States');
                legend({'u','v','w','u_e','v_e','w_e'},'Location','Best');
                ylabel('velocity (m/s)');
                xlabel('time (s)');

                plot_num = plot_num + 1;
            case 3

                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,states(:,[3 7 11]));
                hold on
                plot(time,kalman(:,8:9));
                title('Linear Euler Angle States');
                legend({'\phi','\theta','\psi','\phi_e','\theta_e'},'Location','Best');
                ylabel('angle (rad)');
                xlabel('time (s)');
           
                plot_num = plot_num + 1;               
            case 4
     
                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,states(:,[4 8 12]));
                hold on
                plot(time,kalman(:,5:7));
                title('Linear Angular Velocity States');
                legend({'p','q','r','p_e','q_e','r_e'},'Location','Best');
                ylabel('angular velocity (rad/s)');
                xlabel('time (s)');

                plot_num = plot_num + 1;               
        end 
    end  
end


%% Plot Outputs
% decide on size
n_states = nnz(outputs_shown);
if (n_states == 1)
    subplot_size = [1,1];
elseif (n_states == 2)
    subplot_size = [1,2];
else 
    subplot_size = [2,2];
end

figure('Color', 'w');
sgtitle(['Outputs, Input: ' input]);

plot_num = 1;
for i=1:4
    if (outputs_shown(i))
        switch i            
            case 1
                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,output(:,1:2))
                title('X vel and acc')
                legend({'u', 'a_x'},'Location','Best');
%                 ylabel('position (m)');
                xlabel('time (s)');

                plot_num = plot_num + 1;                
            case 2
                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,output(:,4:5))
                title('Y vel and acc')
                legend({'v', 'a_y'},'Location','Best');
%                 ylabel('acceleration (m/s2)');
                xlabel('time (s)');

                plot_num = plot_num + 1;                
            case 3
                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,output(:,7:8))
                title('Z pos and acc')
                legend({'Z', 'a_z'},'Location','Best');
%                 ylabel('acceleration (m/s2)');
                xlabel('time (s)');
           
                plot_num = plot_num + 1;               
            case 4
                subplot(subplot_size(1),subplot_size(2),plot_num);
                plot(time,output(:,[6,3,9]));
                title('angular velocities')
                legend({'p','q','r'},'Location','Best');
%                 ylabel('acceleration (m/s2)');
                xlabel('time (s)');

                plot_num = plot_num + 1;               
        end 
    end  
end


end

