//Oliver Olsen s205443
//Nils Wulff   s223968

// 9a.  The LM 35 DZ Sensor has a conversion formula: tempInCelcius = /(v_out-0.5)*100. The v_out = (analog_read)*((voltage_in)/1024)
// The -0.5 is due to the sensor's ability to read negative temps. Therefor an offset is needed.

// 9b   It prints out 0 deg c, 2 deg c, 4 deg c and 6 deg c.
// 9c   The write() sends a raw byte. The print() will try to send the ASSCII version of the number
// 9d   Can be read in the monitor. ()is calclated in the func voltConverter.
// 9e   Can also be read in the monitor. It is a result of the calculated voltage.
// 9f   Watch the attached video in the folder.
#include <Arduino.h>
#define TEMPPIN A0
#define INPUTVOLTAGE 5.0
#define ANALOGMAX 1024.0
#define OFFSET 0

int analogInput = 0;
float volt = 0;
float tempMeasured = 0;




float voltConvert(int analogInput);

void setup() {
  Serial.begin(9600);
  pinMode(TEMPPIN, INPUT);
  
}

void loop() {
  analogInput = analogRead(TEMPPIN);

  // Store the new voltage
  volt = voltConvert(analogInput);
  Serial.print("Voltage measured/calculated: ");
  Serial.println(volt);
  // Temp calculated with formula: temperature_c = voltage * 100
  tempMeasured = (volt-OFFSET) * 100;
  Serial.print("Temperature measured: ");
  Serial.print(tempMeasured);
  Serial.write(u8"\u00B0");
  Serial.println("C");

  // Delay added to reduce number print-outs
  // The sensor can output data once per second
  delay(1000);

}


/**
 * @brief Converts the analog reading tol voltage by utilizing the formula: v = analog_reading * (V_in/analogMax)
 * 
 * @param analogInput 
 * @return int 
 */
  float voltConvert(int analogInput){
  float voltage = 0;
  voltage = analogInput * (INPUTVOLTAGE/ANALOGMAX);
  return voltage;
}
