const int mVolt = 3300;
const int tmpPin = A0;
const int phPin = A1;
const int waterPin = A2;
float tmpVal, phVal, waterVal = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int vin = 0;

    //read input voltage from analog pin and calculate the value based on formula
    vin = analogRead(tmpPin);
    tmpVal= (vin*(mVolt/1024)-500)/10;

    vin = analogRead(phPin);
    phVal = vin;

    vin = analogRead(waterPin);
    waterVal = vin;

    //write results to serial port (Nano 33 BLE serial is bluetooth)
    Serial.print("Example temperature reading: ");
    Serial.println(tmpVal, 5);
    
    Serial.print("Example PH reading: ");
    Serial.println(phVal, 2);
    
    Serial.print("Example flood reading: ");
    Serial.println(waterVal);
}