#include <EasyTransfer.h>

//#include <SoftEasyTransfer.h>
#define mySerial Serial2
//#include <SoftEasyTransfer.h>

struct PWM_data {
    float pwm[4];
  };

  char pwm_data_sent[4];
  char pwm_data_received[4];
  int i;  
  EasyTransfer ETin, ETout;
  PWM_data data1;
  PWM_data data2;
  
void setup() {
  // put your setup code here, to run once:
float a[4]={100,200,330,450};
Serial.begin(9600);
mySerial.begin(38400);
ETin.begin( details(data1), &mySerial);
ETout.begin( details(data2), &mySerial);
for(int i=0;i<=3;i++){
  data2.pwm[i]=a[i];
  Serial.println(data2.pwm[i]);
}
}

void loop() {
      ETout.sendData();
      if(ETin.receiveData())
      {  
        for(i=0;i<=3;i++){
        pwm_data_received[i]=data1.pwm[i];
        }
      }
      for(i=0;i<=3;i++){
        //Serial.println(pwm_data_received[i]);
        }
     delay(100);
     
}
