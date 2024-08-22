clear
arduinoObj = serialport("COM4",115200)
configureTerminator(arduinoObj,"CR/LF");
flush(arduinoObj);
dados = struct("x",[],"y",[]);
i = 0;
z = 0;
while i >=0 %define um loop a ser executado indefinidamente.
data = readline(arduinoObj);
leitura = str2num(data); %converte a leitura para numeros
if i > 3 %ignora as três primeiras leituras na porta, geralmente dados em escrito do sistema arduino.
dados.x(i) = leitura(1); %grava a variável x
dados.y(i) = leitura(2); %grava a variável y
end
i = i+1;
end
% plot(dados.x,dados.y);
%plot(dados.x,dados.y,'*'); - comandos de plotagem para serem usados
%manualmente ao fim da aquisição.