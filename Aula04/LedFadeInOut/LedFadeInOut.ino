const int SELETOR = A3;
const int LED = 3;

int brilho = 0;
int fade = 5;

void setup()
{
  pinMode(SELETOR, OUTPUT);
  digitalWrite(SELETOR, HIGH);
  
  pinMode(LED, OUTPUT);
}

void loop()
{
  analogWrite(LED, brilho);
  
  brilho = brilho + fade;
  
  if (brilho <= 0 || brilho >= 255)
  {
    fade = -fade;
  }
  
  delay(25);
}
