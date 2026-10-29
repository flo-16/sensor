#include "outputs.h"

Store store;
Scanner scanner(store);
Viewer viewer(store, SENSOR_NAMES);

void setup() {
	Serial.begin(115200);																										// Initialize Serial communication at 115200 baud rate
	delay(1000); 																														// Wait for Serial to be ready
	Serial.println("\nStarting Sensor System...");													// Print 	
}

void loop() {
	static WatchPoint_t watchPoint = LAUBE;
	static uint32_t nextUpdate = 0;
	if (millis() > nextUpdate) {
		scanner.update(watchPoint);
		viewer.update(watchPoint);
		Serial.println(																												// nur Beispielausgabe über die serielle Schnittstelle: 
			"Sensor: " + String(viewer.getBezeichnung(watchPoint)) + 
			", Average: " + String(viewer.getItem(watchPoint, AVERAGE)) +
			", Minimum: " + String(viewer.getItem(watchPoint, MINIMUM)) +
			", Maximum: " + String(viewer.getItem(watchPoint, MAXIMUM)) +
			", Actual: " + String(viewer.getItem(watchPoint, ACTUAL))
		);
	}
	watchPoint = static_cast<WatchPoint_t>(watchPoint + 1);
	nextUpdate = millis() + SHORT_UPDATE_INTERVAL;
	if (watchPoint == NO_SENSOR) {
		watchPoint = LAUBE;
		nextUpdate += LONG_UPDATE_INTERVAL;
	}
	delay(5);
}

