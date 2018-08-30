#include <SoftEasyTransfer.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);


struct PWM_data {
    float pwm[4];
  };

  //char pwm_data_sent[4];
  //char pwm_data_received[4];
  int i,count=0;  
  SoftEasyTransfer ETin, ETout;
  PWM_data data1;
  PWM_data data2;
  char pwm_data_received[4];

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(38400);
ETout.begin(details(data1), &mySerial);
ETin.begin(details(data2), &mySerial);

}

void loop() {
    //for(i = 0; i<=3; i++){
//      while(!(Serial.available()));
//      if(Serial.available()>0)
//      data.pwm[i]= Serial.read();
//      }
//      for(int i=0;i<=3;i++){
      //Serial.println(data1.pwm[i]);  
      //}
      ETout.sendData();
      i=0;
     
     
     
      if(ETin.receiveData())
      {  
        for(i=0;i<=3;i++){
          pwm_data_received[i]=data2.pwm[i];
          Serial.println(pwm_data_received[i]);
        }
      }
  delay(100);
}

void serialEvent(){
  while(Serial.available()){
    data1.pwm[count%4]=Serial.read();
  }  
  count++;
}
