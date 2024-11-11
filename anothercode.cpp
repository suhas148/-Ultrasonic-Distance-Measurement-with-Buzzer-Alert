int duration;
int distance;


void setup()
{
	pinMode(13, OUTPUT);// led red
	pinMode(12, OUTPUT);// led blue
	pinMode(11, OUTPUT);// led green
	pinMode(10, OUTPUT);// piezo
	pinMode(9, OUTPUT);// vibrator
	pinMode(2, OUTPUT); // ultra-sonic sensor
	pinMode(3, INPUT);
	
	Serial.begin(9600);
}

void loop()
{
	digitalWrite(2, HIGH);
	delayMicroseconds(10);
	digitalWrite(2,LOW);
	
	duration= pulseIn(3, HIGH);
	distance = (duration/2)/29;
	
	Serial.print("Distance :");
	Serial.print(distance);
	Serial.print("cm");
	Serial.print(" ");
	
	if(distance>320){
		digitalWrite(11, HIGH);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
		Serial.println("Safe");
	}
	else {
		digitalWrite(11, LOW);
	}
	
	if(distance>=150 && distance<320){
		digitalWrite(12, HIGH);
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		Serial.println("Mid range");
		delay(2000);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
	}
	else {
		digitalWrite(12, LOW);
	}
		if(distance<150){
		digitalWrite(13, HIGH);
		digitalWrite(10, HIGH);
		digitalWrite(9, HIGH);
		Serial.println("Unsafe");
		delay(50);
		digitalWrite(10, LOW);
		digitalWrite(9, LOW);
	}
	else {
		digitalWrite(13, LOW);
	}
}
//in these code for three different distances three different sound wii be made
