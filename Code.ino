// defines pins
#define stepPin 3
#define dirPin 7
int motor_90 = A0;
int motor_180 = A1;
int motor_270 = A2;
int motor_360 = A3;
int n;

void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(motor_270, INPUT);
  pinMode(motor_90, INPUT);
  pinMode(motor_180, INPUT);
  pinMode(motor_360, INPUT);
}

void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation (360)
  if ((digitalRead(motor_90) == 0) && (digitalRead(motor_180) == 0) && (digitalRead(motor_270) == 0) && (digitalRead(motor_360) == 0)){
    n = 0;
 
  }
  if ((digitalRead(motor_90) == 1) || (digitalRead(motor_180) == 1) || (digitalRead(motor_270) == 1) || (digitalRead(motor_360) == 1)){
    if (digitalRead(motor_90) == 1){
      n = 1000;
    }else if (digitalRead(motor_180) == 1){
      n = 1500;
    }else if (digitalRead(motor_270) == 1){
      n = 1900;
    }else if (digitalRead(motor_360) == 1){
      n = 200;
    }
    for (int x = 0; x < n; x++){
      digitalWrite(stepPin, HIGH); 
      delayMicroseconds(2500);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin, LOW); 
      delayMicroseconds(2500);
    }
    digitalWrite(dirPin, LOW);
    for (int x = 0; x < n; x++){
      digitalWrite(stepPin, HIGH); 
      delayMicroseconds(2500);    // by changing this time delay between the steps we can change the rotation speed
      digitalWrite(stepPin, LOW); 
      delayMicroseconds(2500);
    }
    }
}