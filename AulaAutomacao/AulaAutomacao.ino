const int LED = 13;

void setup() 
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Conectado...");  
  Serial.println("Digite [L]igar ou [D]esligar o Led");
  Serial.println("São aceitos 'L' ou 'l' e 'D' ou 'd'... ");
  Serial.println("Outros caracteres são ignorados ");
  Serial.println();
}

void loop() 
{
 if (Serial.available())
 {
    byte byteLido = Serial.read();

     switch(byteLido)
     {
        case 'd':
        case 'D':
          digitalWrite(LED, LOW);
          Serial.println("Led desligado...");
          break;

        case 'l':
        case 'L':
          digitalWrite(LED, HIGH);
          Serial.println("Led ligado...");
          break;

        case 'p':
        case 'P':
        
        for(int i = 1; i < 50; i++)
        {
          digitalWrite(LED, HIGH);
          delay(100);
          digitalWrite(LED, LOW);
          delay(100);
        }
        break;          
          
        default:
          Serial.println("Comando inválido...");
          break;
     }
 }

}
