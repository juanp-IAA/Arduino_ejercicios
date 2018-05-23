//Ejemplo de eio de una cadena por el puerto serie desde el Arduino

void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.println(.Hello Pi.);
    delay(2000);
}


