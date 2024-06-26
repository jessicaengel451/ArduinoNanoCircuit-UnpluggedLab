// Pin assignments
const int blinkLedPin = 3;    // LED for blinking
const int fadeLedPin = 5;     // LED for fading
const int buzzerPin = 6;      // Buzzer
const int motorPin = 9;       // DC motor
const int potPin = A0;        // Potentiometer pin
const int potLedPin = 10;     // Pot pin LED
const int photoPin = A1;      // Photoresistor pin
const int photoLedPin = 4;    // Photoresistor Led pin
const int slideSwitchPin = 2; // Slide switch pin
const int ssLedPin = 8;
const int buttonPin = 7; // Push button pin
const int buttonLedPin = 11;
// Timing variables
unsigned long previousBlinkTime = 0;
const long blinkInterval = 500;
unsigned long previousFadeTime = 0;
const long fadeInterval = 10;
int fadeBrightness = 0;
int fadeDirection = 1;
unsigned long previousBuzzerTime = 0;
const long buzzerInterval = 200;
bool buzzerState = LOW;
unsigned long previousMotorTime = 0;
const long motorInterval = 2000;
bool motorState = LOW;
void setup()
{
    // Set pin modes
    pinMode(blinkLedPin, OUTPUT);
    pinMode(fadeLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(motorPin, OUTPUT);
    pinMode(slideSwitchPin, INPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}
void loop()
{
    unsigned long currentTime = millis();
    // Blink LED
    if (currentTime - previousBlinkTime >= blinkInterval)
    {
        previousBlinkTime = currentTime;
        digitalWrite(blinkLedPin, !digitalRead(blinkLedPin));
    }
    // Fade LED
    if (currentTime - previousFadeTime >= fadeInterval)
    {
        previousFadeTime = currentTime;
        analogWrite(fadeLedPin, fadeBrightness);
        fadeBrightness += fadeDirection;
        if (fadeBrightness == 0 || fadeBrightness == 255)
        {
            fadeDirection = -fadeDirection;
        }
    }
    // Buzzer sound
    if (currentTime - previousBuzzerTime >= buzzerInterval)
    {
        previousBuzzerTime = currentTime;
        buzzerState = !buzzerState;
        digitalWrite(buzzerPin, buzzerState);
    }
    // Spin motor
    if (currentTime - previousMotorTime >= motorInterval)
    {
        previousMotorTime = currentTime;
        motorState = !motorState;
        analogWrite(motorPin, motorState ? 255 : 0);
    }
    // Potentiometer control
    int potValue = analogRead(potPin);
    int potBrightness = map(potValue, 0, 1023, 0, 255);
    analogWrite(potLedPin, potBrightness);
    // Photoresistor control
    int lightLevel = analogRead(photoPin);
    Serial.print("Light Level: ");
    Serial.println(lightLevel);
    if (lightLevel < 700)
    {
        digitalWrite(photoLedPin, HIGH);
    }
    else
    {
        digitalWrite(photoLedPin, LOW);
    }
    // Slide switch control
    int switchState = digitalRead(slideSwitchPin);
    if (switchState == LOW)
    {
        digitalWrite(ssLedPin, HIGH);
    }
    else
    {
        digitalWrite(ssLedPin, LOW);
    }
    // Push button control
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW)
    {
        digitalWrite(buttonLedPin, HIGH);
    }
    else
    {
        digitalWrite(buttonLedPin, LOW);
    }
}

6 : 40
    // Pin assignments
    const int blinkLedPin = 3; // LED for blinking
const int fadeLedPin = 5;      // LED for fading
const int buzzerPin = 6;       // Buzzer
const int motorPin = 9;        // DC motor
const int potPin = A0;         // Potentiometer pin
const int potLedPin = 10;      // Pot pin LED
const int photoPin = A1;       // Photoresistor pin
const int photoLedPin = 4;     // Photoresistor Led pin
const int slideSwitchPin = 2;  // Slide switch pin
const int ssLedPin = 8;
const int buttonPin = 7; // Push button pin
const int buttonLedPin = 11;
// Timing variables
unsigned long previousBlinkTime = 0;
const long blinkInterval = 500;
unsigned long previousFadeTime = 0;
const long fadeInterval = 10;
int fadeBrightness = 0;
int fadeDirection = 1;
unsigned long previousBuzzerTime = 0;
const long buzzerInterval = 200;
bool buzzerState = LOW;
unsigned long previousMotorTime = 0;
const long motorInterval = 2000;
bool motorState = LOW;
void setup()
{
    // Set pin modes
    pinMode(blinkLedPin, OUTPUT);
    pinMode(fadeLedPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(motorPin, OUTPUT);
    pinMode(slideSwitchPin, INPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}
void loop()
{
    unsigned long currentTime = millis();
    // Blink LED
    if (currentTime - previousBlinkTime >= blinkInterval)
    {
        previousBlinkTime = currentTime;
        digitalWrite(blinkLedPin, !digitalRead(blinkLedPin));
    }
    // Fade LED
    if (currentTime - previousFadeTime >= fadeInterval)
    {
        previousFadeTime = currentTime;
        analogWrite(fadeLedPin, fadeBrightness);
        fadeBrightness += fadeDirection;
        if (fadeBrightness == 0 || fadeBrightness == 255)
        {
            fadeDirection = -fadeDirection;
        }
    }
    // Buzzer sound
    if (currentTime - previousBuzzerTime >= buzzerInterval)
    {
        previousBuzzerTime = currentTime;
        buzzerState = !buzzerState;
        digitalWrite(buzzerPin, buzzerState);
    }
    // Spin motor
    if (currentTime - previousMotorTime >= motorInterval)
    {
        previousMotorTime = currentTime;
        motorState = !motorState;
        analogWrite(motorPin, motorState ? 255 : 0);
    }
    // Potentiometer control
    int potValue = analogRead(potPin);
    int potBrightness = map(potValue, 0, 1023, 0, 255);
    analogWrite(potLedPin, potBrightness);
    // Photoresistor control
    int lightLevel = analogRead(photoPin);
    Serial.print("Light Level: ");
    Serial.println(lightLevel);
    if (lightLevel < 700)
    {
        digitalWrite(photoLedPin, HIGH);
    }
    else
    {
        digitalWrite(photoLedPin, LOW);
    }
    // Slide switch control
    int switchState = digitalRead(slideSwitchPin);
    if (switchState == LOW)
    {
        digitalWrite(ssLedPin, HIGH);
    }
    else
    {
        digitalWrite(ssLedPin, LOW);
    }
    // Push button control
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW)
    {
        digitalWrite(buttonLedPin, HIGH);
    }
    else
    {
        digitalWrite(buttonLedPin, LOW);
    }
}