/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/schul/Documents/Hedorah_NDIR_BoronTest/src/Hedorah_NDIR_BoronTest.ino"
/*
  Reading CO2, humidity and temperature from the SCD30
  By: Nathan Seidle
  SparkFun Electronics
  Date: May 22nd, 2018
  License: MIT. See license file for more information but you can
  basically do whatever you want with this code.

  Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/15112

  This example prints the current CO2 level, relative humidity, and temperature in C.

  Hardware Connections:
  Attach RedBoard to computer using a USB cable.
  Connect SCD30 to RedBoard using Qwiic cable.
  Open Serial Monitor at 115200 baud.
*/

// #include <Wire.h>

#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30
void setup();
void loop();
#line 23 "c:/Users/schul/Documents/Hedorah_NDIR_BoronTest/src/Hedorah_NDIR_BoronTest.ino"
SCD30 airSensor;

namespace Pins { //Use for Boron
	constexpr uint16_t WD_HOLD  = 7;
	constexpr uint16_t EXT_EN   = 8;
	constexpr uint16_t SD_EN    = 9;
	constexpr uint16_t SD_CS    = 14;
	constexpr uint16_t SDA_CTRL = 2;
	constexpr uint16_t TIP      = 15;
	constexpr uint16_t GPIOXA 	= 16;
	constexpr uint16_t Clock_INT 	= 2;
  constexpr uint16_t Port1D 	= D6;
	constexpr uint16_t Port2D 	= D5;
	constexpr uint16_t Port3D  	= D4;
	constexpr uint16_t Port1A 	= A2;
	constexpr uint16_t Port2A 	= A1;
	constexpr uint16_t Port3A 	= A0;
}

SYSTEM_MODE(MANUAL)
SYSTEM_THREAD(DISABLED)

void setup()
{
  pinMode(Pins::EXT_EN, OUTPUT);
	digitalWrite(Pins::EXT_EN, HIGH); //Turn on external power 
	pinMode(Pins::SDA_CTRL, OUTPUT);
	digitalWrite(Pins::SDA_CTRL, HIGH); //Turn on internal SDA

  Serial.begin(115200);
  delay(1000); //DEBUG!
  Serial.println("SCD30 Example");
  Wire.begin();

  if (airSensor.begin() == false)
  {
    Serial.println("Air sensor not detected. Please check wiring. Freezing...");
    while (1)
      ;
  }

  //The SCD30 has data ready every two seconds
}

void loop()
{
  if (airSensor.dataAvailable())
  {
    Serial.print("co2(ppm):");
    Serial.print(airSensor.getCO2());

    Serial.print(" temp(C):");
    Serial.print(airSensor.getTemperature(), 1);

    Serial.print(" humidity(%):");
    Serial.print(airSensor.getHumidity(), 1);

    Serial.println();
  }
  else
    Serial.println("Waiting for new data");

  delay(500);
}
