// Pin en el cual se encuentra el sensor LDR
int LDR_PIN = A0;




void setup() {
  // Seteamos los pines de los leds como OUTPUT
  // No hace falta que seteemos el PIN del LDR, ya que los pines analogicos son todos de entrada.
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

void loop() {
  // Leemos el valor actual del sensor, utilizando analogRead. 
  // Esto nos devolvera un numero entre 0 y 1023.
  int ldrValue = analogRead(LDR_PIN);

  if (ldrValue> 512) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  else{
    digitalWrite(13, LOW);   // turn the LED on (LOW is the voltage level)
    
  }

  delay(500);
}
