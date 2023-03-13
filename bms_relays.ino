//https://docs.arduino.cc/built-in-examples/communication/SerialEvent
//https://reference.arduino.cc/reference/en/language/functions/communication/serial/serialevent/
//https://elcodigoascii.com.ar/
//https://www.youtube.com/watch?v=vHeG3Gt6STE
//https://learn.microsoft.com/en-us/visualstudio/ide/reference/toolbox?view=vs-2022
//https://www.youtube.com/watch?v=lY1Z0Hgo288
//https://www.youtube.com/watch?v=gi-Sruf8FNA
#define tiempo_apagados 3000
#define times 200
int Pines[]={2,3,4,5,6,7,8,9};
int dato=8;

void setup() {
  configurar_pines();
  Pone_todo_cero();
  Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for native USB
    }
  
  
}

void loop() {

}
void Pone_todo_cero(){
  for(int i=0;i<8;i++){
    digitalWrite(Pines[i], LOW);   // turn the LED on (HIGH is the voltage level)
  }
}




void ciclico(){
  for(int i=0;i<8;i++){
    digitalWrite(Pines[i], HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(times);                       // wait for a second
    digitalWrite(Pines[i], LOW);    // turn the LED off by making the voltage LOW
    delay(times);
  }
}
void configurar_pines(){
  for(int i=0;i<8;i++){
    pinMode(Pines[i], OUTPUT);
  }
}


void serialEvent() {
  while (Serial.available()) {
          // get the new byte:
          dato = Serial.read();

                  if(dato!=10){
                        Serial.println(dato-48);  
                        switch (dato-48) {
                        

                            case 0:  //prender todo 
                              Serial.println("PAGAR todo: 0");
                              digitalWrite(Pines[2], LOW);//fuente
                              digitalWrite(Pines[3], LOW);
                              delay(tiempo_apagados);
                              digitalWrite(Pines[0], LOW);//debuger
                              digitalWrite(Pines[1], LOW);     
                              delay(tiempo_apagados);                        
                              break;

                            case 1:  //prender todo 
                              Serial.println("PRENDER todo: 1");
                              digitalWrite(Pines[0], HIGH);//debuger
                              digitalWrite(Pines[1], HIGH);
                              delay(tiempo_apagados);
                              digitalWrite(Pines[3], HIGH);//fuente
                              digitalWrite(Pines[2], HIGH);     
                              delay(tiempo_apagados);                        
                              break;




                            case 2: 
                              Serial.println("RELAY 5 PENDIDO");
                              digitalWrite(Pines[4], HIGH);
                              break;
                            case 3:  
                              Serial.println("RELAY 6 PENDIDO");
                              digitalWrite(Pines[5], HIGH);
                              break;
                            case 4:  
                              Serial.println("RELAY 7 PENDIDO");
                              digitalWrite(Pines[6], HIGH);
                              break;
                            case 5: 
                              Serial.println("RELAY 8 PENDIDO");
                              digitalWrite(Pines[7], HIGH);
                              break;



                            case 6:  
                              Serial.println("RELAY 5 APAGADO");
                              digitalWrite(Pines[4], LOW);
                              break;
                            case 7: 
                              Serial.println("RELAY 6 APAGADO");
                              digitalWrite(Pines[5], LOW);
                              break;
                            case 8: 
                              Serial.println("RELAY 7 APAGADO");
                              digitalWrite(Pines[6], LOW);
                              break;
                            case 9:  
                              Serial.println("RELAY 8 APAGADO");
                              digitalWrite(Pines[7], LOW);
                              break;
                            case -1:  
                              Serial.println("APAGA TODO");
                              Pone_todo_cero();
                              break;  
                            case -2:  
                              Serial.println("Power on reset");
                              digitalWrite(Pines[2], LOW);//fuente
                              digitalWrite(Pines[3], LOW);
                              delay(3000);
                              digitalWrite(Pines[3], HIGH);//fuente
                              digitalWrite(Pines[2], HIGH);  
                              break; 


                              
                            default:
                              
                              Serial.println(" no entiendo ");
                             
                              break;
                          }

                  }
                  
              
  }

  
}
