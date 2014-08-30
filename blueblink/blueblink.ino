


#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
char val;
int ledpin=13;
int relaypin=12;
int sensorPin = A0; 
int sensorValue = 0;
int delaycount =0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(relaypin,OUTPUT);
  
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  //mySerial.println("Hello, world?");
  
}
void loop()
{
  val = mySerial.read();
  if(val=='q')
  {
    setOn();
  }
  else if(val=='w')
  {
    setOff();
  }
  
  delayInfo();  
}

void setOn()
{
    digitalWrite(ledpin,HIGH);
    Serial.println("LED ON!");
    digitalWrite(relaypin,LOW);
}

void setOff()
{
    digitalWrite(ledpin,LOW);
    Serial.println("LED OFF!");
    digitalWrite(relaypin,HIGH);
}

void delayInfo()
{
  delaycount = delaycount + 1;
  if (delaycount >=30000 )
  {
    sensorValue = analogRead(sensorPin); 
    Serial.println("TH:"+sensorValue);
    Serial.println(sensorValue);
    //mySerial.write("hello\r\n");
    mySerial.write(sensorValue);
    if (sensorValue>100)
    {
      //mySerial.write('q');
      setOn();
    }
    else
    {
      //mySerial.write('w');
      setOff();
    }
    delaycount = 0;
  }
}
