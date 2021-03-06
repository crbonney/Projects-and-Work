function [ Pnew ] = TRANSRRR(P, theta, L)

    [~,N] = size(P);
    T =   [...
           cos(theta)  -sin(theta)  0  L ;...
           sin(theta)   cos(theta)  0  0 ;...
               0             0      1  0 ;...
               0             0      0  1 ;...
    ];

    Pnew = [P; ones(1,N)];
    Pnew = T*Pnew;
    Pnew = Pnew(1:3,:);

end

