int sensorPin = A0; //sensor pin

// reading samples 
int readMean(int pin, int samples){  
  // reading sum
  int sum = 0;
  for (int i = 0; i < samples; i++){
    sum = sum + analogRead(pin);
  }
  sum = sum/samples;
  return sum;
}

// some number of samples from the sensor; reurns median 
int readMedian (int pin, int samples){
  int raw[samples];
  for (int i = 0; i < samples; i++){
    raw[i] = analogRead(pin);
  }

  // sorting values 
  int temp = 0; 
  for (int i = 0; i < samples; i++){
    for (int j = i; j < samples - 1; j++){
      // Check if values out of order
      if (raw[j] > raw[j + 1]){
        // If so, swap them
        temp = raw[j];
        raw[j] = raw[j + 1];
        raw[j + 1] = temp;
      }
    }
  }

  return raw[samples/2];
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  // value from sensor
  Serial.print(analogRead(sensorPin));
  Serial.print(" ");
  Serial.print(readMean(sensorPin, 15));
  Serial.print(" ");
  Serial.println(readMedian(sensorPin, 15));
  delay(100); // delay for serial
}
