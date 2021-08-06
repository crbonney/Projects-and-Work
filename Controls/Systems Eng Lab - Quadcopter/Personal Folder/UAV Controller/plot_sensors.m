close all;

load('RSdata.mat');
Fs = 200;
% sensors
t  = rt_simout.time;

% sensors = rt_simout.signals.values;
u    = rt_simout.signals.values(:, 1);
v    = rt_simout.signals.values(:, 2);
w    = rt_simout.signals.values(:, 3);
z    = rt_simout.signals.values(:, 4);
p    = rt_simout.signals.values(:, 5);
q    = rt_simout.signals.values(:, 6);
r    = rt_simout.signals.values(:, 7);
phi  = rt_simout.signals.values(:, 8);
theta= rt_simout.signals.values(:, 9);

states = [u,v,w,z,p,q,r,phi,theta];
state_names = ["u","v","w","z","p","q","r","\phi","\theta"];

% PLOT STATES
for i=1:size(states,2)
    figure('Color', 'w');
    plot(t,states(:,i));
%     hold on
%     plot(t,states_unfiltered(:,i));
    xlabel('t');
    ylabel(state_names(i));
%     legend('filtered','unfiltered');
    grid on
end
% 
% fourier_data = [p,q,r,ax,ay,az,h];
% fourier_unfiltered_data = [p_uf,q_uf,r_uf,ax_uf,ay_uf,az_uf,h_uf];
% fourier_names = ["p","q","r","ax","ay","az","h"];
% fourier_out  = fft(fourier_data, [], 1);
% fourier_unfiltered_out  = fft(fourier_unfiltered_data, [], 1);
% L = size(fourier_out,1);
% if (mod(L,2) == 1)
%     L = L+1;
%     fourier_out = [fourier_out; zeros(1,size(fourier_out,2))];
%     fourier_unfiltered_out = [fourier_unfiltered_out; zeros(1,size(fourier_unfiltered_out,2))];
% end
% P2 = abs(fourier_out/L);
% P1 = P2(1:L/2+1,:);
% P1(2:end-1,:) = 2*P1(2:end-1,:);
% 
% P2_uf = abs(fourier_unfiltered_out/L);
% P1_uf = P2_uf(1:L/2+1,:);
% P1_uf(2:end-1,:) = 2*P1_uf(2:end-1,:);
% 
% 
% f = Fs*(0:(L/2))/L;

% PLOT FOURIER STATES
% for i=1:size(fourier_out,2)
%     figure;
%     plot(f,P1(:,i));
%     hold on
%     plot(f,P1_uf(:,i));
%     xlabel('f (Hz)');
%     ylabel(fourier_names(i));   
%     legend('filtered','unfiltered');
% end


