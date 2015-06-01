/*
**    Arduino - Qt 'qextserialport' &  Qt 'qwt' lib test file 1
**
**    generates random data & send them throught the serial port
**    can serve as base implementation for real probes
**
**    ~schematics: N/A
**
*/

int randNumber; // an int to host a random number

void setup()
{
    Serial.begin(9600); // start the serial port at 9600 bauds
    randomSeed(analogRead(0));// init the pseudo-random number generator in such a way that generated values'll differ on each program execution ( see above notes )
}

void loop()
{
    randNumber = random(255); // pass a number to generate the random seed, wich is held in the 'randNumber' var
    //Serial.print(randNumber, BYTE); // send the number, precising the format to use [ from the orinigal instructables tutorial ]
    Serial.write(randNumber); // 'new way of doing the above' ( starting with Arduino 1.0 )
    //Serial.print((char)randNumber); // second 'new way of doing so'
    delay(1000); // wait for 1 s
}
