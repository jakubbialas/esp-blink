#include <user_config.h>
#include <SmingCore/SmingCore.h>

#define LAMP1 4
#define LAMP2 5
#define LAMP3 0 //!!
#define LAMP4 2
#define LAMP5 15
#define LAMPR 13
#define LAMPG 12
#define LAMPB 14

Timer procTimer1;
Timer procTimer2;
bool state = true;

uint8_t pins[3] = { LAMPR, LAMPG, LAMPB }; // List of pins that you want to connect to pwm
HardwarePWM HW_pwm(pins, 3);

void blink()
{
        debugf("\n\n############# blink #############################################");
	digitalWrite(LAMP1, state);
	digitalWrite(LAMP2, state);
	digitalWrite(LAMP3, state);
	digitalWrite(LAMP4, state);
	digitalWrite(LAMP5, state);
//	digitalWrite(LAMPR, state);
//	digitalWrite(LAMPG, state);
//	digitalWrite(LAMPB, state);

	state = !state;
}

int32 i = 0;
int32 inc = 1;

void doPWM() {
	i += inc;

	HW_pwm.analogWrite(LAMPR, (i + 0 ) % 60);
	HW_pwm.analogWrite(LAMPG, (i + 20) % 60);
	HW_pwm.analogWrite(LAMPB, (i + 40) % 60);


        debugf("\n\n############################ %i ##########################################", i);
}

void init()
{
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(true); // Enable debug output to serial

    WifiAccessPoint.enable(false, true);

    WifiStation.enable(true, true);
    WifiStation.config("Valhalla", "dalejdupa", true, true);
    WifiStation.enableDHCP(true);
    WifiStation.connect();

	pinMode(LAMP1, OUTPUT);
	pinMode(LAMP2, OUTPUT);
	pinMode(LAMP3, OUTPUT);
	pinMode(LAMP4, OUTPUT);
	pinMode(LAMP5, OUTPUT);
//	pinMode(LAMPR, OUTPUT);
//	pinMode(LAMPG, OUTPUT);
//	pinMode(LAMPB, OUTPUT);

        debugf("\n\n###########################################################################");

	procTimer1.initializeMs(500, blink).start();

	HW_pwm.analogWrite(LAMPR, 1);
	HW_pwm.analogWrite(LAMPG, 1);
	HW_pwm.analogWrite(LAMPB, 1);
//
//	//debugf("PWM output set on all 8 Pins. Kindly check...");
//	//debugf("Now Pin 2 will go from 0 to VCC to 0 in cycles.");
//
	procTimer2.initializeMs(100, doPWM).start();
}

