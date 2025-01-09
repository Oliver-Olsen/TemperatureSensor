//Oliver Olsen s205443
//Nils Wulff   s223968


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

  // Temp calculated with formula: temperature_c = voltage * 100
  tempMeasured = volt * 100;
  Serial.println(tempMeasured);

  // Delay added to reduce number print-outs
  delay(500);

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
