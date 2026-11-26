#pragma once
#include "inputs.h"

constexpr uint8_t MAX_BUFFER_LENGTH = 160; 																	// Maximale Länge des temp. Buffers

class Viewer {
	private:
		Store& rstore;																													// Referenz auf die Store-Klasse
		uint8_t currentSensor;																									// Aktuell ausgewählter Sensor
		char buffer[MAX_BUFFER_LENGTH];																					// Buffer für die Anzeige
		pchar getStoreMenue(const uint8_t sensor);
		uint8_t normalize(float value);																		// y-Koordinate for diagramm
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

uint8_t Viewer::normalize(float value) {
	if (value < 0.0f) value = 0.0f;
	if (value > 16.0f) value = 100;
	uint8_t normalizedValue = static_cast<uint8_t>((value / 16.0f) * 100.0f);
	return normalizedValue;
}

void Viewer::seriellPrint() {
	for (uint8_t i = 0; i < SENSORS; i++) { 
		Serial.println(getStoreMenue(i));
	}
}

void Viewer::setDiagramm(const uint8_t sensor) {
	if (sensor >= SENSORS) return;
	for(uint8_t i = 0; i < BASE; i++) {
		float value = rstore.getHistoricalData(sensor, i);
		uint8_t normalizedValue = normalize(value);
		// OLED setPixel(i, normalizedValue);  // Set pixel on OLED display (this line is commented out as a placeholder)
	}
	// Currently, this function is a placeholder for future implementation.
}
