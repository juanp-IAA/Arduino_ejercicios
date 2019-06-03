#include <EEPROM.h>

#define LED_BUILTIN 4
#define MY_BUTTON 3

#define STATE_ON 0xEE //enable
#define STATE_OFF 0xDD  //dsable

unsigned int led_status_address = 0;
byte led_status = 0, new_status = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MY_BUTTON, INPUT_PULLUP); 

  led_status = EEPROM.read(led_status_address );
  if ((led_status != STATE_ON) &&
       (led_status != STATE_OFF))
       {
            EEPROM.update(led_status_address ,STATE_ON);
            led_status = STATE_ON;
       }
  new_status = led_status;
}

// the loop function runs over and over again forever
void loop() {

  if(led_status == STATE_ON)
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  if(led_status == STATE_OFF)                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  delay(1000);                       // wait for a second

  while(digitalRead(MY_BUTTON) != HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(200);                       // wait for 200 millisecond
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(200);                       // wait for  200 millisecond

    if (led_status == STATE_ON)
      new_status = STATE_OFF;

    if (led_status == STATE_OFF)
      new_status = STATE_ON;
  
  }

  if (led_status != new_status){
    EEPROM.update(led_status_address ,new_status);
    led_status = new_status;
  }
  
}
