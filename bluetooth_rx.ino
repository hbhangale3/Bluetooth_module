#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX
char c;

void setup() {

Serial.begin(9600);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{

if (mySerial.available()>0)

c= mySerial.read();
Serial.write(c);

if (Serial.available()>0)

c=Serial.read();
mySerial.write(c);


}
