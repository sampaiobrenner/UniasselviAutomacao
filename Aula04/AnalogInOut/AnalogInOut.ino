const int POTENCIOMETRO = A2;
const int SELETOR = A3;
const int LED = 3;

int valorEntrada = 0;
int valorSaida = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(SELETOR, OUTPUT);
  digitalWrite(SELETOR, HIGH);

  pinMode(LED, OUTPUT);
  
  analogReference(INTERNAL);
}

void loop()
{
  valorEntrada = analogRead(POTENCIOMETRO);
  
  valorSaida = map(valorEntrada, 0, 1023, 0, 255);
  
  analogWrite(LED, valorSaida);
  
  Serial.print("Potenciometro = ");
  Serial.print(valorEntrada);
  Serial.print("\t");
  Serial.print("Led = ");
  Serial.println(valorSaida);

  delay(100);
}
