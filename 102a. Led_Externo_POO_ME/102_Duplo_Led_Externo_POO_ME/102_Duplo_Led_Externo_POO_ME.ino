//102. Piscar 2 LEDs Externo, em paralelo
//Usando Máquina de Estados e Mills

class PiscaLed
{
  int ledPin;
  long OnTime;
  long OffTime;

  int ledState;
  unsigned long previusMillis;


  public:
  PiscaLed(int pin, long on, long off)
  {
    ledPin = pin;
    pinMode(ledPin, OUTPUT);

    OnTime = on;
    OffTime = off;

    ledState = LOW;
    previusMillis = 0;
  }

  void Update()
  {
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
};

PiscaLed led1 (12,100,400);
PiscaLed led2 (13,350,350);

void setup(){

}

void loop(){
  led1.Update();
  led2.Update();
}