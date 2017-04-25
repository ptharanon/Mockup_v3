clear all
close all

Output = csvread('Output.txt');
Statorcurrent = Output(:,1);
Rotorspeed = Output(:,2);
ElectromagneticTorque = Output(:,3);
DCbusvoltage = Output(:,4);

for i=1:size(Statorcurrent)
    if i==1
        TimeVector(i)=0;
    else
    TimeVector(i) = TimeVector(i-1) + 2e-06;    
    end
end

figure;

subplot(4,1,1)
plot(TimeVector,Statorcurrent,'b');
xlabel('Time');
ylabel('Amplitude');
title('Stator current');
grid on

subplot(4,1,2)
plot(TimeVector,Rotorspeed,'b');
xlabel('Time');
ylabel('Amplitude');
title('Rotorspeed');
grid on

subplot(4,1,3)
plot(TimeVector,ElectromagneticTorque,'b');
xlabel('Time');
ylabel('Amplitude');
title('ElectromagneticTorque');
grid on

subplot(4,1,4)
plot(TimeVector,DCbusvoltage,'b');
xlabel('Time');
ylabel('Amplitude');
title('DCbusvoltage');
grid on