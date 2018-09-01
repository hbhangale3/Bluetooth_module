//#include <SoftwareSerial.h>
// the following code works for two way communication along with the bluetooth_tx code present in the same repository.
//SoftwareSerial mySerial(10, 11); // RX, TX
#include <EasyTransfer.h>
char c;
EasyTransfer ETpid, ETrpm;

struct RPM_data{
  int16_t rpm[4];
  }rpm_data;

struct PID_data{
  float Kp[4];
  float Ki[4];
  float Kd[4];
  }pid_data;
 
void setup() {
Serial.begin(38400);
Serial2.begin(38400);
Serial.println("Enter pid values");
ETrpm.begin(details(rpm_data), &Serial2);
 ETpid.begin(details(pid_data), &Serial2);
   for(int i=0;i<4;i++){
    pid_data.Kp[i]=1;
    pid_data.Ki[i]=3;
    pid_data.Kd[i]=7;
    
    }

}

void loop(){

  ETpid.sendData();
  if(ETrpm.receiveData()>0){
    for(int i=0;i<4;i++){
      Serial.println(rpm_data.rpm[i]);
      }
    }
//
//if (Serial2.available()>0){
//
//c= Serial2.read();
//Serial.println(c);
//}
//delay(100);
//if (Serial.available()>0){
//c=Serial.read();
//Serial2.write(c);
//}

}
