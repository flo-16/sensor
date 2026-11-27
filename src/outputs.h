#pragma once
#include "inputs.h"

constexpr uint8_t MAX_BUFFER_LENGTH = 160; 																	// Maximale Länge des temp. Buffers
constexpr float LIMIT_MIN = 8.0f; 																					// Minimum Limit for normalization
constexpr float LIMIT_MAX = LIMIT_MIN + 8.0f; 															// Maximum Limit Range für Ausgabe: 0 .. 8V
constexpr uint8_t NORMALIZED_MIN = 63; 																			// Minimum normalized value for diagram
constexpr uint8_t NORMALIZED_MAX = 0; 																			// Maximum normalized value for diagram
class Viewer {
	private:
		Store& rstore;																													// Referenz auf die Store-Klasse
		uint8_t currentSensor;																									// Aktuell ausgewählter Sensor
		char buffer[MAX_BUFFER_LENGTH];																					// Buffer für die Anzeige
		pchar getStoreMenue(const uint8_t sensor);
		uint8_t normalize(const float value);																		// y-Koordinate for diagramm
	public:
		Viewer(Store& storeRef) : rstore(storeRef), currentSensor(0), buffer() {} 	// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		void seriellPrint();																												// Serielle Ausgabe der aktuellen Messwerte für alle Sensoren
		void setDiagramm(const uint8_t sensor);																			// Funktion zum Setzen des Diagramms
};

pchar Viewer::getStoreMenue(const uint8_t sensor) {
	char line[32];
	buffer[0] = '\0'; 			
	sprintf(buffer, "%s\n", SENSOR_NAMES[sensor]); 																// Add sensor name to the buffer
	for (Measured_t measurement = AVERAGE; measurement <= ACTUAL; measurement = static_cast<Measured_t>(measurement + 1)) {
		line[0] = '\0'; 	
		float f = rstore.getSensorData(sensor, measurement);
		sprintf(line, "%-16s: %6.2f V\n", MPNAMES[measurement], f);							// alternativ: dtostrf
		strcat(buffer, line);
	}
	return const_cast<const char*>(buffer);
}

uint8_t Viewer::normalize(const float value) {
	if (value == 0.0f) return NORMALIZED_MIN; 					// If value is below minimum limit, return minimum normalized value
	float f = value - LIMIT_MIN; 												// Range LIMIT_MIN .. LIMIT_MAX -> 0 .. 8V
	if (f < 0.0f) f = 0.0f;
	if (f > LIMIT_MAX) f = LIMIT_MAX;
	// Konvertiere den Wert in einen Bereich von 0 bis 800 (für 8V) und
	// skaliere ihn auf 63 bis 0 (für die Anzeige auf dem Diagramm)
	// 63 ist der niedrigste Punkt auf dem Diagramm, er entspricht 0V.
	// 0 ist der höchste Punkt auf dem Diagramm, er entspricht 8V.
	return static_cast<uint8_t>((f / LIMIT_MAX) * (NORMALIZED_MIN - NORMALIZED_MAX) + NORMALIZED_MAX);
}

void Viewer::seriellPrint() {
	for (uint8_t i = 0; i < SENSORS; i++) { 
		Serial.println(getStoreMenue(i));
	}
}

void Viewer::setDiagramm(const uint8_t sensor) {
	if (sensor >= SENSORS) return;
	for(uint8_t x = 0; x < BASE; x++) {
		uint8_t y = normalize(rstore.getHistoricalData(sensor, x));
		// OLED setPixel(x, y);  // Set pixel on OLED display (this line is commented out as a placeholder)
	}
}
