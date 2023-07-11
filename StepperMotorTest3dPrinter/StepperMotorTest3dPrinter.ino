/*
This sketch is a simple way to make sure all stepper motors work and test
the different stepping modes for each motor. May switch over to library but 
this is already written and works well. 

Each motor will spin one direction and then the other in sequential order, and 
then continue this pattern.
*/

// order is X,Y,Z,E0, E1

// set the direction pins
const int dirPin[5] = {A1,A7,48,28,34};

// set the step pins
const int stepPin[5] = {A0,A6,46,26,36};

// set the enable pins
const int enablePin[5] = {38,A2,A8,24,30};


// 200 teeth but we are doing 1/16 steps so mult by 16 for 1 revolution
const int steps = 200*16;


// this is the first delay time, it controls how fast the steppers spin
const unsigned long delaytime = 250;

// this is the second delay time, it controls how long between rotating the opposite direction
const unsigned long delaytime2 = 5;

void setup() {

  // iterate through each motor and set to output
  for(int i=0;i<5;i++) {
    pinMode(stepPin[i],OUTPUT);
    pinMode(dirPin[i],OUTPUT);
    pinMode(enablePin[i],OUTPUT);
    // set enable to LOW to allow for movement
    digitalWrite(enablePin[i],LOW);
  }
}
void loop() {
 // iterate through each motor so we can see them move inividually 
  for(int i=0;i<5;i++) {
    // Set motor direction clockwise
	  digitalWrite(dirPin[i], HIGH);

    // spin one direction
    for(int x = 0; x < steps; x++) {
      digitalWrite(stepPin[i], HIGH);
      delayMicroseconds(delaytime);
      digitalWrite(stepPin[i], LOW);
      delayMicroseconds(delaytime);
    }
    // wait before spinnning other way
    delay(delaytime2); 
	
	// Go other direction
	digitalWrite(dirPin[i], LOW);

  // spin for the same number of steps
	for(int x = 0; x < steps; x++)
	{
		digitalWrite(stepPin[i], HIGH);
		delayMicroseconds(delaytime);
		digitalWrite(stepPin[i], LOW);
		delayMicroseconds(delaytime);
	}
  // wait before going to next motor
	delay(delaytime2);
  }

}