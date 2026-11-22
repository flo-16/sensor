#include "outputs.h"

Trend trend;
Store store;
Scanner scanner(store);
Viewer viewer(trend, store, SENSOR_NAMES);

void handler(const uint32_t ticks);

void setup() {
	Serial.begin(115200);																										// Initialize Serial communication at 115200 baud rate
	delay(1000); 																														// Wait for Serial to be ready
	Serial.println("\nStarting Sensor System...");													// Print 	
}

void loop() {
	handler(millis());
	delay(5);
}

void handler(const uint32_t ticks) {
	static WatchPoint_t wpStore = LAUBE;
	static uint32_t nextStore = 0;
	static uint32_t nextTrend = 0;
	if (ticks > nextStore) {
		scanner.update(wpStore);
		viewer.update(wpStore);
		wpStore = static_cast<WatchPoint_t>(wpStore + 1);
		nextStore = ticks + SHORT_UPDATE_INTERVAL;
		if (wpStore == NO_SENSOR) {
			// Hier Ausgabe der Store-Daten oder andere Aktionen, die nach dem Lesen aller Sensoren durchgeführt werden sollen
			// z.B. Ausgabe der Daten auf dem Serial Monitor store.viewer(); - nicht implementiert!!!
			wpStore = LAUBE;
			nextStore += LONG_UPDATE_INTERVAL;
		}
	}
	if (ticks > nextTrend) {
		trend.addTrendData(
			store.getSensorData(LAUBE, ACTUAL),
			store.getSensorData(KELLER, ACTUAL),
			store.getSensorData(BODEN, ACTUAL),
			store.getSensorData(SCHUPPEN, ACTUAL)
		);
		nextTrend = ticks + TREND_UPDATE_INTERVAL;
		// Hier Ausgabe der Trend-Daten oder andere Aktionen, die nach dem Lesen aller Sensoren durchgeführt werden sollen
	}
};


