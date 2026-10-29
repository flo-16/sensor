#pragma once
#include "stores.h"

class Scanner {
	private:
		Store& rstore;																												// Referenz auf die Store-Klasse
	public:
		Scanner(Store& storeRef) : rstore(storeRef) {} 												// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		void update(const WatchPoint_t sensor);
};
																							
void Scanner::update(const WatchPoint_t sensor) {
	float f = 0.0;																												
	switch(sensor) {
		case LAUBE:
			f = 11.44;																												// hier lesen - Beispielwert für Laube
			break;
		case KELLER:
			f = 12.34;																												// hier lesen - Beispielwert für Keller
			break;
		case BODEN:
			f = 13.56;																												// hier lesen - Beispielwert für Boden
			break;
		case SCHUPPEN:
			f = 14.78;																												// hier lesen - Beispielwert für Schuppen
			break;
	}
	rstore.updateSensorData(sensor, f);																		// Update the sensor data in the Store class
};
