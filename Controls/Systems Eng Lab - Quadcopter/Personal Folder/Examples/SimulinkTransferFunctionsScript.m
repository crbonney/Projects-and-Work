Ti=1/10;
Td=2;
K=3;

dT = 1/200;
z = tf('z',dT); %define z
s = @(z) 2/dT*(1-z^-1)/(1+z^-1); %bilinear transform to replace s w/ z

H = Td*s(z)/(Td*s(z)+1); %get transfer function in terms of z

[num,dem] = tfdata(H, 'v');

figure('Color', [1,1,1]);
plot(out.simout.Time, out.simout.Data(:,1),'LineWidth',3);
hold all;
plot(out.simout.Time, out.simout.Data(:,2),'LineStyle', '--','LineWidth',3);
xlabel('Time (s)');
ylabel('Output');
title('Digital vs Continuous control');
legend({'Continuous', 'Digital'},'Location','Best');
