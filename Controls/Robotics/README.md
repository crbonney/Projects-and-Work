# Robotics

Swing up Controller Model \
![](swing_up_controller.jpg)

Inverted Pendulum swing up animation \
![](inverted_pendulum.gif)



Planar RRR arm model \
![](RRR_arm_axes.jpg)

Models open-loop dynamics and torque required for each joint to hold cancel the dynamics, and you can set the desired torque by hand.
![](open_loop_model.jpg)

The controller of the system, cancels the open-loop dynamics (Torque Calculator), and uses a PD controller to create spring-damper behavior to drive to a set point. \
![](pd_partitioned_control_law.jpg)

Below is the result of the controller.


![](rrr_animated.gif)
