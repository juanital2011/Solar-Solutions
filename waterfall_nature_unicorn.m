%Solar Solutions

%Define constants

G=6.674e-11;      %Gravitational Constant
M_sun=1.988e30;   %Solar Mass
c=3.00e8;         %Speed of Light

%Define Parameters

m=3.163e23;    %Mass of Earth
r=[1.496e8; 2.279e8; 7.783e8];   %Radii of Earth, Venus, and Jupiter

%Calculate gravitational force

F_grav = G*m*M_sun./(r.^2);

%Calculate escape velocity

V_esc = sqrt(2*G*M_sun./r);

%Calculate solar flux

F_sol = 4*pi*r.^2.*1367./c;

%Calculate solar intensity

I_sol = F_sol./(4*pi*r.^2);

%Calculate angular speed

O_ang = sqrt(G*M_sun./r.^3);

%Calculate orbital period

T_orb = 2*pi.*sqrt(r.^3./G*M_sun);

%Calculate total energy

E = G*M_sun./r + (V_esc.^2)./2;

%Calculate total momentum

P = m*V_esc;

%Plot results

figure
subplot(2,2,1)
plot(r,F_grav)
title('Gravitational Force')
xlabel('Radius (m)')
ylabel('Gravitational Force (N)')

subplot(2,2,2)
plot(r,V_esc)
title('Escape Velocity')
xlabel('Radius (m)')
ylabel('Escape Velocity (m/s)')

subplot(2,2,3)
plot(r,I_sol)
title('Solar Intensity')
xlabel('Radius (m)')
ylabel('Solar Intensity (W/m^2)')

subplot(2,2,4)
plot(r,T_orb)
title('Orbital Period')
xlabel('Radius (m)')
ylabel('Orbital Period (s)')