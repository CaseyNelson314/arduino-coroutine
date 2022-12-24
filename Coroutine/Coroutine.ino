#include "Coroutine.hpp"

void setup() {
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

	// HOGEを出力
	CO_BEGIN;
	Serial.println("HOGE");
	CO_DELAY(1000);
	CO_END;

	
	// LED点滅
	CO_BEGIN;
	digitalWrite(LED_BUILTIN, HIGH);
	CO_DELAY(500);
	digitalWrite(LED_BUILTIN, LOW);
	CO_DELAY(300);
	CO_END;
	
}
