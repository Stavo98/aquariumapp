const int mVolt = 3300;
const int tmpPin = A0;
const int phPin = A1;
const int otherPin = A2;
float tmpVal, phVal, otherVal = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int vin = 0;

    //read input voltage from analog pin and calculate the value based on formula
    vin = analogRead(tmpPin);
    tmpVal= vin*(mVolt/1024)-500)/10;

    vin = analogRead(phPin);
    phVal = vin;

    vin = analogRead(otherPin);
    otherVal = vin;

    //write results to serial port (Nano 33 BLE serial is bluetooth)
    Serial.print("Example temperature reading: ");
    Serial.println(tmpVal, 5);
}