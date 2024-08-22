int pino_sct = 34; // Pino a ser lido.
int leitura; // variável para armazenar o valor lido no pino_sct.
long int tempo; //tempo - servirá como o eixo X no gráfico DDP x Tempo.
int z = 0;
long int t2 = 0; // variável para armazenar os valores do cronômetro da função "micros".
void setup() {
  Serial.begin(115200);
  pinMode(pino_sct, INPUT); // Definição do pino como "input", para que este leia sinais analógicos.
}

void loop() {
  t2 = micros(); // Atribuímos o valor instantâneo do cronômetro à variável t2;
  if (t2-z >= 1000){ //Z será momento da última leitura. Subtraímos-o de t2 para verificar se já se passaram 1000 microsegundos. Caso positivo, a função "adquirir" será chamada.
    adquirir(); // Chama a função de leitura do sinal.
    z = t2; // Atribuímos o valor de tempo do início da leitura à z, que armazena o tempo de leitura da última leitura realizada.
  }
}

void adquirir() {
leitura = analogRead(pino_sct); // Lê o valor analógico no pino definido.
      Serial.print(t2/1000); // Envia à porta serial o valor do tempo dividido por 1000. O valor lido na porta será usado para o eixo X do gráfico e será, então, em ms.
      Serial.print(" "); // Espaço entre os dois valores na linha a ser enviada para a porta serial.
      Serial.println(analogRead(pino_sct)); //Lê o valor analógico instantâneo na porta e o envia para a porta serial.
}
