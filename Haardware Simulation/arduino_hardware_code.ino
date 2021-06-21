const int trigPin1 = 2;       //defining echo sensor pins  1
const int echoPin1 = 3;
const int trigPin2 = 4;      //defining echo sensor pins 2
const int echoPin2 = 5;
const int trigPin3 = 6;      //defining echo sensor pins 3
const int echoPin3 = 7;
const int trigPin4 = 8;      //defining echo sensor  pins 4
const int echoPin4 = 9;
const int ledLight_and_Buuzer = 12;     // defining LED Pin
// const int buzzerPin= 13;     // the number of the buzzer pin actually we didn't use this 13 no. pin
float distance;
long duration;
float distance1;
float distance2;
float distance3;
float distance4;
int setdis=30;

void setup() {
      pinMode(trigPin1, OUTPUT);   // Sets the trigPin as an Output 1
      pinMode(echoPin1, INPUT);    // Sets the echoPin as an Input  1
      pinMode(trigPin2, OUTPUT);   // Sets the trigPin as an Output 2
      pinMode(echoPin2, INPUT);    // Sets the echoPin as an Input  2
      pinMode(trigPin3, OUTPUT);   // Sets the trigPin as an Output 3
      pinMode(echoPin3, INPUT);    // Sets the echoPin as an Input  3
      pinMode(trigPin4, OUTPUT);   // Sets the trigPin as an Output 4
      pinMode(echoPin4, INPUT);    // Sets the echoPin as an Input  4
      pinMode(ledLight_and_Buuzer, OUTPUT);
      pinMode(buzzerPin, OUTPUT);
      Serial.begin(9600); 
}

 float sonar1(){

    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin1, HIGH);// Calculating the distance
    distance = duration * 0.034 / 2;
    Serial.print("Distance1: ");
    Serial.print(distance);
    Serial.println(" cm");

    return distance;
 
 }
 float sonar2(){

    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin2, HIGH);// Calculating the distance
    distance = duration * 0.034 / 2;
    Serial.print("Distance2: ");
    Serial.print(distance);
    Serial.println(" cm");

    return distance;
 
 }
 float sonar3(){

    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin3, HIGH);// Calculating the distance
    distance = duration * 0.034 / 2;
    Serial.print("Distance3: ");
    Serial.print(distance);
    Serial.println(" cm");

    return distance;
 
 }
 float sonar4(){

    digitalWrite(trigPin4, LOW);
    delayMicroseconds(2);// Sets the trigPin HIGH (ACTIVE) for 10 microseconds 
    digitalWrite(trigPin4, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin4, LOW);// Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin4, HIGH);// Calculating the distance
    distance = duration * 0.034 / 2;
    Serial.print("Distance4: ");
    Serial.print(distance);
    Serial.println(" cm");
    return distance;
 
 }
 
void loop() {
  // put your main code here, to run repeatedly:
  distance1= sonar1();
  distance2= sonar2();
  distance3= sonar3();
  distance4= sonar4();

   if(distance1==0 || distance2==0 || distance3==0){
    digitalWrite(ledLight_and_Buuzer, LOW);
    
    }
   else if( distance1 < setdis || distance2 < setdis || distance3 < setdis || distance4 < setdis){

    digitalWrite(ledLight_and_Buuzer, HIGH);
   //  tone(buzzerPin,2000);
   //    delay(1000);
   //    digitalWrite(ledLight_and_Buuzer, LOW);
    }
    else{
      digitalWrite(ledLight_and_Buuzer, LOW);
    }
      

}
