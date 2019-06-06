//Blink without delay multitarea
unsigned long interval1 = 3000;
unsigned long interval2 = 2000;
unsigned long previousMillis1;
unsigned long previousMillis2;

bool state = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  
  previousMillis1 = millis();
  previousMillis2 = millis();
}

void loop() {
  unsigned long currentMillis = millis();

  // Gestionar el desbordamiento
  if ((unsigned long)(currentMillis - previousMillis1) >= interval1)
  {
    action1();
    previousMillis1 = millis();
  }
  if ((unsigned long)(currentMillis - previousMillis2) >= interval2)
  {
    action2();
    previousMillis2 = millis();
  }
}

void action1()
{
  Serial.println("action1.");
  switchLed();
  
}

void action2()
{
  Serial.println("action1.");
  switchLed();
}

void switchLed()
{
   state = !state;
   digitalWrite(LED_BUILTIN, state);
}
