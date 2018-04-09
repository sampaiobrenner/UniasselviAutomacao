const int LED = 3;
//const int SELETOR = A3;

void setup()
{
  pinMode(LED, OUTPUT);
  //pinMode(SELETOR, OUTPUT);
  //digitalWrite(SELETOR, HIGH);
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Conectado");
  Serial.println("Informe um valor entre 0 e 255 para");
  Serial.println("controlar o brilho do led...");
  Serial.println("Informe somente valores inteiros...");
  Serial.println();
}

void loop()
{
  if (Serial.available())
  {
    int Brilho = Serial.parseInt();
    if (Brilho >= 0 and Brilho <= 255)
    {
      Serial.print("Brilho = ");
      Serial.println(Brilho);

      analogWrite(LED, Brilho);
    }
  }
}
