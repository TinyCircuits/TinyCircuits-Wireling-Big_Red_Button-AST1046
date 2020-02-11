/*************************************************************************
 * Big Red Button Wireling
 * Program will print to the Serial Monitor if the button has been pressed.
 * If the button has not been pressed, it will print the AnalogRead value.
 * 
 * Written by: Laveréna Wienclaw for TinyCircuits
 *************************************************************************/
 
#include <Wireling.h>

float buttonPin = A0;

// Make Serial Monitor compatible for all TinyCircuits processors
#if defined(ARDUINO_ARCH_AVR)
  #define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
  #define SerialMonitorInterface SerialUSB
#endif

void setup() {
  SerialMonitorInterface.begin(9600);     
  Wireling.begin();

  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = analogRead(buttonPin);

  if(buttonState == LOW)
  {
    SerialMonitorInterface.println("Button pressed!");
  }
  else
  {
    SerialMonitorInterface.print("button state: "); SerialMonitorInterface.println(buttonState);
  }
  //Poll Sensor Data
  delay(500);
}
