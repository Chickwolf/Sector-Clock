#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL4WIRE, 5, 6, 7, 8);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 9, 10, 11, 12);

void setup()
{  
    Serial.begin(9600);
    
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(100.0);
    stepper1.moveTo(360);
    
    stepper2.setMaxSpeed(200.0);
    stepper2.setAcceleration(100.0);
    stepper2.moveTo(360);
}
   
    String inBuffer = "";

void loop()
{
    while (Serial.available())
    {
      char c = Serial.read();
      inBuffer += c;
    }
    
    byte incomingByte = Serial.read();
   
    if (inBuffer == "servo1")
    {
      Serial.println("test point 1");
      if (stepper1.distanceToGo() == 0)
      {
          Serial.println("test point 2");
          stepper1.moveTo(-stepper1.currentPosition());
          stepper1.run();
      }
    }
    
    else if (inBuffer == "servo2")
    {
       Serial.println("test point 3");      
       if (stepper2.distanceToGo() == 0)
       {
          Serial.println("test point 4");
          stepper2.moveTo(-stepper2.currentPosition());
          stepper2.run();
       }
    }
    
    inBuffer = "";
}
