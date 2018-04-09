// Declara constantes contendo valores do tipo inteiro
// https://www.arduino.cc/en/Reference/Const
// https://www.arduino.cc/en/Reference/Int
const int LEDVERDE = 3;
const int SELETOR = A3;

// Função responsável por realizar as configurações
// iniciais para o funcionamento do Arduino e suas Shields
// https://www.arduino.cc/en/Reference/Setup
void setup()
{
  // Configura a forma de funcionamento dos
  // pinos do Arduino como INPUT (entrada) ou OUTPUT (saída)
  // https://www.arduino.cc/en/Reference/PinMode
  pinMode(LEDVERDE, OUTPUT);
  pinMode(SELETOR, OUTPUT);

  // Escreve um valor HIGH (Ligado) ou LOW (Desligado)
  // numa porta configurada como OUTPUT (Saída)
  // https://www.arduino.cc/en/Reference/DigitalWrite
  digitalWrite(SELETOR, HIGH);
  
  // Inicialização a porta serial a 9600 bauds,
  // 8 bits, sem paridade e 1 stop bit
  // https://www.arduino.cc/en/Serial/Begin
  Serial.begin(9600);

  // Aguarda até que seja detectada a
  // conexão serial com o computador
  // https://www.arduino.cc/en/Serial/IfSerial
  while(!Serial)
  {
    ;
  }
  
  // Envia dados pela porta serial
  // https://www.arduino.cc/en/Serial/Println
  Serial.println("Conectado...");
  Serial.println("Informe um valor entre 0 e 100%");
  Serial.println("para controlar o brilho do LED...");
  Serial.println("Use '.' para valores decimais...");
  Serial.println();
}

// Executa os comandos necessárias para que o
// Arduino realize o que desejamos
// https://www.arduino.cc/en/Reference/Loop
void loop()
{
  // Verifica se existem dados para leitura na serial
  // https://www.arduino.cc/en/Serial/Available
  if (Serial.available())
  {
    // Lê os dados disponíveis na serial na
    // forma de valor com casas decimais
    // https://www.arduino.cc/en/Serial/ParseFloat
    float percentual = Serial.parseFloat();
    
    // Verifica se o valor lido está entre 0 e 100 porcento
    // https://www.arduino.cc/en/Reference/If
    if (percentual >= 0 and percentual <= 100)
    {
      // Calcula o brilho a ser aplicado ao LED
      // (int) guarda apenas a parte inteira do resultado
      // https://www.arduino.cc/en/Reference/IntCast
      int brilho = (int)(percentual * 255) / 100;
      
      Serial.print("Percentual = ");
      Serial.print(percentual, 2); // Exibe o valor com 2 casas decimais
      Serial.println("%");
      Serial.print("Brilho = ");
      Serial.println(brilho);
      Serial.println();
      
      // Escreve um valor analógico (PWM) num pino digital
      // identificado com o "~" e configurado como saída (OUTPUT)
      // https://www.arduino.cc/en/Reference/AnalogWrite
      analogWrite(LEDVERDE, brilho);
    }
    else // https://www.arduino.cc/en/Reference/Else
    {
      Serial.println("O valor informado deve estar entre 0 e 100...");
    }
  }
}
