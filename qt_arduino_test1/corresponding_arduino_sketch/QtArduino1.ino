/*
**    Arduino - Qt 'qextserialport' lib test file 1
**
**    controls the brightness of a LED present on the pin 9
**
**    ~schematics: Gnd <->l LED L<->1KOhm resistor<->pin9
**
*/

const int ledPin = 9; // the pin the LED is attached to
//const byte ledBrightness = 150;

void setup()
{
    Serial.begin(9600); //start the serial port at 9600 bauds
    pinMode(ledPin, OUTPUT); // init the LED pin as an output
    //analogWrite(ledPin, ledBrightness);// set the brightness of the LED
}

void loop()
{
    byte brightness;
    // if we get data from the computer, update the LED brightness
    if ( Serial.available() > 0 ) // if data is available from the serial
    {
        brightness = Serial.read(); // read the most recent byte ('ll be from 0 to 255)
        analogWrite(ledPin, brightness);// set the brightness of the LED
    }
}
