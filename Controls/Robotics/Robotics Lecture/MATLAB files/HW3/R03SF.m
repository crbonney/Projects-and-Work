%% From lecture Notes
function [ R03 ] = R03SF(theta1,theta2)

    R01 =   [...
           cos(theta1)  -sin(theta1)  0 ;...
           sin(theta1)   cos(theta1)  0 ;...
                0              0      1 ;...
    ];

    R12 =   [...
            cos(theta2)  -sin(theta2)  0 ;...
                 0             0       1 ;...
           -sin(theta2)  -cos(theta2)  0 ;...
    ];

    R23 =   [...
             1   0   0 ;...
             0   0  -1 ;...
             0   1   0 ;...
    ];

    R03 = R01*R12*R23;

end
