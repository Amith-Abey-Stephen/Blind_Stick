const int trigPin = 11;
const int echoPin = 10;
const int buzzerPin = 2;
const int maxDistance = 50; // Maximum distance to sense in centimeters

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  long duration, distance;
  
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = (duration / 2) / 29.1; // Speed of sound wave divided by 2 (go and back) and divided by 29.1 to convert to cm
  
  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // If the distance is less than the max distance, beep the buzzer
  if (distance <= maxDistance) {
    int delayTime = map(distance, 0, maxDistance, 100, 1000); // Map the distance to delay time between 100ms to 1000ms
    digitalWrite(buzzerPin, HIGH);
    delay(100); // Beep duration
    digitalWrite(buzzerPin, LOW);
    delay(delayTime - 100); // Subtract the beep duration from the delay
  } else {
    digitalWrite(buzzerPin, LOW); // Turn off buzzer if out of range
  }
}
