% Funci�n para mostrar telemetr�a de robot m�vil
% Laboratorio de Rob�tica 4� GIERM 18-19
% Federico Cuesta
% USO: Pasar como par�metro el nombre del archivo de telemetr�a con el
% sigiente contenido por fila:
% -Incremento de tiempo transcurrido desde la lectura anterior (milisegundos),  
% -Distancia medida por sensor Izq/Frontal (cm), 
% -Distancia medida por sensor Dch/Trasero(cm), 
% -Referencia de control (cm), 
% -Modo activo (0: Parado, 1: Control frontal, � 4),
% -Velocidad PWM motor Izq (+/-255, negativo indica marcha atr�s), 
% -Velocidad PWM motor Dch (+/-255, negativo indica marcha atr�s).

function telemetria(archivo)

tel=load(archivo);
muestras=length(tel);
disp('Incremento de tiempo m�nimo:'); disp(min(tel(:,1)));
disp('Incremento de tiempo m�ximo:');disp(max(tel(:,1)));
disp('Incremento de tiempo promedio:'); disp(mean(tel(:,1)));
tiempo=zeros(1,muestras);
tiempo(1)=tel(1,1); %Vector de tiempo absoluto
for i=2:muestras
    tiempo(i)=tiempo(i-1)+tel(i,1);
end    

figure;
subplot(2,1,1);
plot(tiempo,tel(:,2), tiempo,tel(:,3), tiempo,tel(:,4));grid;
xlabel('Tiempo (ms)');
ylabel('Distancia (cm)');
title('Modo , Controlador, Sensores');
%legend('sensor iz','sensor der','referencia');
xlim(10^6*[0 16]);
legend('sensor Frontal','sensor Trasero','referencia');

subplot(2,1,2);
plot(tiempo,tel(:,5), tiempo,tel(:,6),'y', tiempo,tel(:,7),'g');grid;
title('Actuadores');
xlabel('Tiempo (ms)');
ylabel('Velocidad');
legend('modo','velocidad motor iz','velocidad motor der');
xlim(10^6*[0 16]);

end