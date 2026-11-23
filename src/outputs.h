#pragma once
#include "inputs.h"

class Viewer {
	private:
		Trend& rtrend;																													// Referenz auf die Trend-Klasse
		Store& rstore;																													// Referenz auf die Store-Klasse
		char buffer[MAX_BUFFER_LENGTH];																					// Buffer für die Anzeige
	public:
		Viewer(Trend& trendRef, Store& storeRef) : rtrend(trendRef), rstore(storeRef), buffer() {} 									// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		pchar getStoreMenue(const uint8_t sensor);
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
