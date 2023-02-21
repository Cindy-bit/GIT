#define powerpin 4
#define SignalPin A4
int led =11;
int led2 =10;
int led3 =8;
// Value for storing water level


void setup() {
  // Set D7 as an OUTPUT
  pinMode(powerpin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  // Set to LOW so no power flows through the sensor
  digitalWrite(powerpin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  //get the reading from the function below and print it
 int val = 0;
  
  Serial.print("Water level: ");
  Serial.println(val);
  
  delay(1000);
  readSensor();
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(powerpin, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  int val = analogRead(SignalPin);    // Read the analog value form sensor
  
  if (val <=150) {
  digitalWrite(led, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  }
else if(val>376&&val<750){
digitalWrite(led, LOW);
digitalWrite(led2, HIGH);
digitalWrite(led3,LOW);
}  
else {
digitalWrite(led, LOW);
digitalWrite(led2, LOW);
digitalWrite(led3,HIGH);
}
}