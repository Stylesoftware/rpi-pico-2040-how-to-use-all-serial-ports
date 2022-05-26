// Use all serial ports on the Pico

SerialPIO ser3(2,3);
SerialPIO ser4(4,5);
SerialPIO ser5(6,7);
SerialPIO ser6(10,11);

void setup() {
  Serial.begin(115200);   // USB
  Serial1.begin(115200);  // 0,1
  Serial2.begin(115200);  // 8,9

  ser3.begin(115200);
  ser4.begin(115200);
  ser5.begin(115200);
  ser6.begin(115200);
}

int a=0;

void loop() {
  delay(20);
  a++;
  if(a>100) {
    Serial.write('a');
    Serial1.write('a');
    Serial2.write('a');
    ser3.write('a');
    ser4.write('a');
    ser5.write('a');
    ser6.write('a');
  } else {
    Serial.write('Z');
    Serial1.write('Z');
    Serial2.write('Z');
    ser3.write('Z');
    ser4.write('Z');
    ser5.write('Z');
    ser6.write('Z');
  }
  
  if(a > 200)
    a=0;
}
