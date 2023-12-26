//102. Piscar LED Externo
//Usando Máquina de Estados e Mills

int ledPin = 9; //Atribui valor 9 a ledPin, pino digital 9 (cabo vermelho)
int ledState  = LOW; //guarda estado
unsigned long previusMillis = 0; //ultima vez update do ledState
long OnTime = 150; //tempo ligado
long OffTime = 850; // tempo desligado

void setup(){
  pinMode(ledPin, OUTPUT); //Estabelece pino 9 como saída
}

void loop(){
  // verifica se é para alterar o LED
  unsigned long currentMillis = millis();

  if ((ledState == HIGH) && (currentMillis - previusMillis >= OnTime))
  {
    ledState = LOW; //desliga
    previusMillis = currentMillis; //guarda tempo
    digitalWrite(ledPin, ledState); //faz atualização do Led
  }
  else if ((ledState == LOW) && (currentMillis - previusMillis >= OffTime))
  {
    ledState = HIGH; //desliga
    previusMillis = currentMillis; //guarda tempo
    digitalWrite(ledPin, ledState); //faz atualização do Led    
  }
}