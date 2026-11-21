#include "outputs.h"

Trend trend;
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
/* So kann man die Trend-Daten verwenden oder anzuzeigen.
Speichern: Die Methode alle Stunde aufzurufen, um die Durchschnittswerte der Sensoren zu speichern:

 	trend.addTrendData(					
		store.getSensorData(LAUBE, AVERAGE),
		store.getSensorData(KELLER, AVERAGE),
		store.getSensorData(BODEN, AVERAGE),
		store.getSensorData(SCHUPPEN, AVERAGE)
	);

Auslesen: Die Methode alle Stunde aufzurufen, um die Trend-Daten auszulesen und anzuzeigen.

	Serial.println(
		"Trend Data: " +
		String(trend.getTrendData(LAUBE, 0)) + ", " +
		String(trend.getTrendData(KELLER, 0)) + ", " +
		String(trend.getTrendData(BODEN, 0)) + ", " +
		String(trend.getTrendData(SCHUPPEN, 0))
	);
	
Für ein Diagramm oder eine grafische Darstellung kann man die Trend-Daten in einem Array speichern(index)
und dann die Werte für die Anzeige verwenden.	Das muss dann in der Klasse Viewer implementiert werden.
*/

	delay(5);
}

