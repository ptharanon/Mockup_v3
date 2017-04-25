Output = csvread('Output.txt');
Statorcurrent = Output(:,1);
Rotorspeed = Output(:,2);
ElectromagneticTorque = Output(:,3);
DCbusvoltage = Output(:,4);

statorCurrent_ref = statorCurrent_ref.Data;
rotorSpeed_ref = rotorSpeed_ref.Data;
electroMagneticTorque_ref = electroMagneticTorque_ref.Data;
DCBusVoltage_ref = DCBusVoltage_ref.Data;

for i=1:size(statorCurrent_ref)
    if i==1
        TimeVector(i)=0;
    else
    TimeVector(i) = TimeVector(i-1) + 2e-06;    
    end
end

for i=1:size(statorCurrent_ref)
    err_StatorCurrent = abs(statorCurrent_ref - Statorcurrent(i));
end

for i=1:size(rotorSpeed_ref)
    err_Rotorspeed = abs(rotorSpeed_ref - Rotorspeed(i));
end

for i=1:size(electroMagneticTorque_ref)
    err_ElectromagneticTorque = abs(electroMagneticTorque_ref - ElectromagneticTorque(i));
end

for i=1:size(DCBusVoltage_ref)
    err_DCbusvoltage = abs(DCBusVoltage_ref - DCbusvoltage(i));
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