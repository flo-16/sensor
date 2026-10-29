#pragma once
#include "inputs.h"

class Viewer {
	private:
		Store& rstore;																													// Referenz auf die Store-Klasse
		const pchar* bez;
		char item[SENSORS][MEASUREMENTS][MAX_STRING_LENGTH];										// 3D Array, um die Daten in String zu speichern
	public:
		Viewer(Store& storeRef, const pchar* p1) : rstore(storeRef), bez(p1), item() {} 									// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		void update(const WatchPoint_t sensor);
		void convertToString(const WatchPoint_t sensor);
		pchar getItem(const WatchPoint_t sensor, const Measured_t measurement) {
			return const_cast<const char*>(item[sensor][measurement]);
		}
		pchar getBezeichnung(const WatchPoint_t sensor) {
			return bez[sensor];
		}
};

void Viewer::update(const WatchPoint_t sensor) {														
	convertToString(sensor);
	// hier können weitere Aktionen hinzugefügt werden, z.B. das Senden der Daten an ein Display oder eine andere Schnittstelle
};

void Viewer::convertToString(const WatchPoint_t sensor) {
	for (Measured_t measurement = AVERAGE; measurement <= ACTUAL; measurement = static_cast<Measured_t>(measurement + 1)) {
		float f = rstore.getSensorData(sensor, measurement);
		snprintf(item[sensor][measurement], sizeof(item[sensor][measurement]), "%.2f", f);
/* Alternative Methode zur Umwandlung von float in String, falls snprintf() nicht direkt mit float umgehen kann
 		char floatStr[MAX_STRING_LENGTH];
		dtostrf(f, MAX_STRING_LENGTH, 2, floatStr);
		snprintf(item[sensor][measurement], sizeof(item[sensor][measurement]), "%s", floatStr);
*/		
	}
}
