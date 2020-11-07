#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
// Go to the Project Settings (nut icon).
char auth[] = "5RyHY4aJ-i6cYA6B_-lbIyL8E3dPUU0g"; // You should get Auth Token in the Blynk App.
char ssid[] = "pratyush";  // Your WiFi credentials.
char pass[] = "pratyush624";  // Set password to "" for open networks.
BlynkTimer timer;
int ir_entrygate=15; //D8
int irentrygateval;

int ir_slot1=4;//D2
int irslot1val;

int ir_slot2=5;//D1
int irslot2val;

int ir_slot3=16;//D0
int irslot3val;


Servo myservo;// create servo object to control a servo
Servo myservol;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth,ssid,pass);
pinMode(ir_entrygate,INPUT);
pinMode(ir_slot1,INPUT);
pinMode(ir_slot2,INPUT);
pinMode(ir_slot3,INPUT);

myservo.attach(2);//D4
timer.setInterval(3000,senddata);
}

void senddata() 
{
  
irentrygateval=digitalRead(ir_entrygate);
irslot1val=digitalRead(ir_slot1);
irslot2val=digitalRead(ir_slot2);
irslot3val=digitalRead(ir_slot3);

if(irentrygateval==0)
{

myservo.write(90);
Serial.println("gate is open"); 
Blynk.virtualWrite(V1,"gate is open");
}
else
{
myservo.write(0);
Serial.println("gate is closed");
Blynk.virtualWrite(V1,"gate is closed");
}
if(irslot1val==0)
{
Serial.println(" slot_1 is occupied");
Blynk.virtualWrite(V2,"slot_1 is occupied");
  
}
else
{
Serial.println("slot_1 is empty");
Blynk.virtualWrite(V2,"slot1 is empty");

}
if(irslot2val==0)
{
Serial.println("slot_2 is occupied");
Blynk.virtualWrite(V3,"slot_2 is occupied");
 
}
else
{
Serial.println("slot_2 is empty");
Blynk.virtualWrite(V3,"slot_2 is empty");

}

if(irslot3val==0)
{
Serial.println("slot_3 is occupied");
Blynk.virtualWrite(V4,"slot_3 is occupied");
 
}
else
{
Serial.println("slot_3 is empty");
Blynk.virtualWrite(V4,"slot_3 is empty");

}
  

}

void loop() 
{ // put your main code here, to run repeatedly:
  
Blynk.run();
timer.run();
}
