#include "outputs.h"

Trend trend;
Store store;
Scanner scanner(store);
Viewer viewer(trend, store);

void handler(const uint32_t ticks);

void setup() {
	Serial.begin(115200);																										// Initialize Serial communication at 115200 baud rate
	delay(1000); 																														// Wait for Serial to be ready
	pinMode(PIN_BUTTON_SERIELL, INPUT_PULLUP); 
	Serial.println("\nStarting Sensor System...");													// Print 	
}

void loop() {
	handler(millis());
	delay(5);
}

void handler(const uint32_t ticks) {
	static uint8_t wpStore = 0;
	static uint32_t nextStore = 0;
	static uint32_t nextTrend = 0;
	static uint32_t buttonBlock = 0;

	if (ticks > nextStore) {
		scanner.update(wpStore);
		wpStore++;
		nextStore = ticks + SHORT_UPDATE_INTERVAL;
		if (wpStore == SENSORS) {
			wpStore = 0;
			nextStore += LONG_UPDATE_INTERVAL;
		}
	}

	if (ticks > nextTrend) {
		trend.addTrendData(
			store.getSensorData(0, ACTUAL),
			store.getSensorData(1, ACTUAL),
			store.getSensorData(2, ACTUAL),
			store.getSensorData(3, ACTUAL)
		);
/* 
	viewer.setDiagramm(); 																									// Update the diagram with the latest trend data
 */	
		nextTrend = ticks + TREND_UPDATE_INTERVAL;
	}

	if (buttonBlock > 0 && ticks > buttonBlock) { buttonBlock = 0; }
	// Der Button wird nur alle BUTTON_BLOCK_TIME Millisekunden ausgewertet, um ein Prellen zu vermeiden
	// Digital input 0 is used for the button, if it is pressed (LOW) and the buttonBlock is not active, print the sensor data to Serial	
	if (!(digitalRead(PIN_BUTTON_SERIELL) == LOW) || (buttonBlock)) {			
		buttonBlock = ticks + BUTTON_BLOCK_TIME;	
		for (uint8_t i = 0; i < SENSORS; i++) {
			Serial.println(viewer.getStoreMenue(i));
		}
	}
};


