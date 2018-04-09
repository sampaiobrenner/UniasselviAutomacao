const int SELETOR = A3;
const int LED_R = 5;
const int LED_G = 3;
const int LED_B = 6;

int brilho = 0;
int fade = 5;

int contador = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(SELETOR, OUTPUT);
  digitalWrite(SELETOR, HIGH);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop()
{
  switch(contador)
  {
    case 0:
      analogWrite(LED_R, brilho);
      Serial.println("LED Vermelho");
      break;
      
    case 1:  
      analogWrite(LED_G, brilho);
      Serial.println("LED Verde");
      break;
      
    case 2:
      analogWrite(LED_B, brilho);
      Serial.println("LED Azul");
      break;
      
    default:
      contador = 0;
      Serial.println("Reiniciando contador...");
      break;
  }
  
  brilho = brilho + fade;
  
  if (brilho <= 0 || brilho >= 255)
  {
    fade = -fade;

    contador++;
  }
  
  delay(25);
}
