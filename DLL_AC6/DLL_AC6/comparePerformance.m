Output = csvread('Output.txt');
Statorcurrent = Output(:,1);
Rotorspeed = Output(:,2);
ElectromagneticTorque = Output(:,3);
DCbusvoltage = Output(:,4);

statorCurrent1_ref = statorCurrent_ref.Data;
rotorSpeed1_ref = rotorSpeed_ref.Data;
electroMagneticTorque1_ref = electroMagneticTorque_ref.Data;
DCBusVoltage1_ref = DCBusVoltage_ref.Data;

size = size(Statorcurrent,1);

for i=1:size
    if i==1
        TimeVector(i)=0;
    else
    TimeVector(i) = TimeVector(i-1) + 2e-06;    
    end
end

for i=1:size
    err_StatorCurrent = abs(statorCurrent1_ref(i) - Statorcurrent(i));
end

for i=1:size
    err_Rotorspeed = abs(rotorSpeed1_ref(i,1) - Rotorspeed(i));
end

for i=1:size
    err_ElectromagneticTorque = abs(electroMagneticTorque1_ref(i,1) - ElectromagneticTorque(i));
end

for i=1:size
    err_DCbusvoltage = abs(DCBusVoltage1_ref(i) - DCbusvoltage(i));
end

figure;

subplot(4,1,1)
plot(TimeVector,err_StatorCurrent,'b');
xlabel('Time');
ylabel('Amplitude');
title('Stator current');
grid on

subplot(4,1,2)
plot(TimeVector,err_Rotorspeed,'b');
xlabel('Time');
ylabel('Amplitude');
title('Rotorspeed');
grid on

subplot(4,1,3)
plot(TimeVector,err_ElectromagneticTorque,'b');
xlabel('Time');
ylabel('Amplitude');
title('ElectromagneticTorque');
grid on

subplot(4,1,4)
plot(TimeVector,err_DCbusvoltage,'b');
xlabel('Time');
ylabel('Amplitude');
title('DCbusvoltage');
grid on