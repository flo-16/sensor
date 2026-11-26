#include "handling.h"

Store store;
Scanner scanner(store);
Viewer viewer(store);
Handler handler(store, scanner, viewer);

void setup() {	
	Serial.begin(115200);																										// Initialize Serial communication at 115200 baud rate
	delay(1000); 																														// Wait for Serial to be ready
	pinMode(BUTTON_PIN, INPUT_PULLUP); 
	Serial.println("\nStarting Sensor System...");													// Print 	
}

void loop() {
	handler.update(millis());
	delay(5);
}
