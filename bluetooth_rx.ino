#include <SoftwareSerial.h>

//SoftwareSerial mySerial(10, 11); // RX, TX
char c;

void setup() {

Serial.begin(9600);

Serial.println("Enter AT commands:");

Serial2.begin(38400);

}

void loop()

{

if (Serial2.available()>0){

c= Serial2.read();
Serial.write(c);
}
delay(100);
if (Serial.available()>0){
c=Serial.read();
Serial2.write(c);
}

}
