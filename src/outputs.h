#pragma once
#include "inputs.h"

class Viewer {
	private:
		Store& rstore;																													// Referenz auf die Store-Klasse
		char item[SENSORS][MEASUREMENTS][MAX_STRING_LENGTH];										// 3D Array, um die Daten in String zu speichern
	public:
		Viewer(Store& storeRef) : rstore(storeRef), item() {} 									// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		void update(const WatchPoint_t sensor);
		void convertToString(const WatchPoint_t sensor);
		const char* getItem(const WatchPoint_t sensor, const Measured_t measurement) {
			return const_cast<const char*>(item[sensor][measurement]);
		}
};

void Viewer::update(const WatchPoint_t sensor) {														// Nur ein Beispiel, um die Daten aus der Store-Klasse zu lesen und anzuzeigen
	convertToString(sensor);
};

void Viewer::convertToString(const WatchPoint_t sensor) {
	for (Measured_t measurement = AVERAGE; measurement <= ACTUAL; measurement = static_cast<Measured_t>(measurement + 1)) {
		float f = rstore.getSensorData(sensor, measurement);
		snprintf(item[sensor][measurement], sizeof(item[sensor][measurement]), "%.2f", f);
	}
}

