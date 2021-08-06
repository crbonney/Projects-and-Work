
%define constants and array for dT
zeta = 1/sqrt(2);
omega = 294;
dT = [1 1/8 1/80 1/600];

figure('Color', [1,1,1]);

for i=1:length(dT)

    %define z for ith timestep
    z = tf('z',dT(i));          

    %forwards and backwards transform to replace s w/ z
    s_f = @(z) (z-1)/dT(i);     
    s_b = @(z) (1-z^-1)/dT(i);  

    %get integrator transfer functions in terms of z
    Hf = 1/s_f(z);              
    Hb = 1/s_b(z);              

    %get numerator and denominator arrays for simulink values
    [num_f,dem_f] = tfdata(Hf, 'v');
    [num_b,dem_b] = tfdata(Hb, 'v');

    %run simulink model from [0 3] seconds and capture the outputs
    output = sim('ESE_448_HW_1_q2_simulink_model', [0 3]);
    %ith subplot is (half width, half height, ith position)
    subplot(2,2,i);
    %plot forwards
    plot(output.simout.Time, output.simout.Data(:,1),'LineWidth',1);
    hold all;
    %plot backwards
    plot(output.simout.Time, output.simout.Data(:,2),'LineStyle', '-','LineWidth',1);
    xlabel('Time (s)');
    ylabel('Output');
    %limit x, y so unstable parts aren't graphed
    xlim([0 3]);
    ylim([-1 3]);
    title(['Forward vs Backward Euler with \DeltaT = ' num2str(dT(i))]);
    legend({'Forward', 'Backward'},'Location','Best');
end
