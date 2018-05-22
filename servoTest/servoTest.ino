#include <Servo.h>
 
Servo myservo;  // Crea un Objeto servo
int pos;    // Variable de la posicion del servo
 
void setup()
{
  myservo.attach(10);  // Selecionamos el pin 2 como el pin de control para els ervo
}
     
void loop()
{

  myservo.write(90);              // tell servo to go to position in variable 'pos' 
    
  delay(10000); 



  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
  
  delay(150); 
   
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(50);                       // waits 15ms for the servo to reach the position 
  } 
                   
//                   
// delay(150);                    
//
// myservo.write(20);
// delay(2000); 
// 
// myservo.write(30);
// delay(2000); 
//                   
// myservo.write(50);
// delay(2000);                    
//                   
//                   
// myservo.write(100);
// delay(2000);      
//
//
// myservo.write(70);
// delay(2000);      

     
 
}


