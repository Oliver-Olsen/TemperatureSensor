//Oliver Olsen s205443
//Nils Wulff   s223968

// 9a. The LM 35 DZ Sensor has a conversion formula: tempInCelcius = /(v_out-0.5)*100. The v_out = (analog_read)*((voltage_in)/1024)
// The -0.5 is due to the sensor's ability to read negative temps. Therefor an offset is needed.

// 9b

#include <Arduino.h>
#define TEMPPIN A0
#define INPUTVOLTAGE 5.0
#define ANALOGMAX 1024

int analogInput = 0;
float volt = 0;
float tempMeasured = 0;




int voltConvert(int analogInput);

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
  tempMeasured = volt * 100;
  Serial.print("Temperature measured in deg c: ");
  Serial.println(tempMeasured);

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
int voltConvert(int analogInput){
  float voltage = 0;
  voltage = analogInput * (INPUTVOLTAGE/ANALOGMAX);
  return voltage;
}
