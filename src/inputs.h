#pragma once
#include "stores.h"

class Scanner {
	private:
		Store& rstore;																												// Referenz auf die Store-Klasse
	public:
		Scanner(Store& storeRef) : rstore(storeRef) {} 												// Konstruktor, der eine Referenz auf die Store-Klasse entgegennimmt
		void update(const uint8_t sensor);
};
																							
void Scanner::update(const uint8_t sensor) {
	float f = 0.0;																												
	switch(sensor) {
		case 0:
			f = 11.44;																												// hier lesen - Beispielwert für Laube
			break;
		case 1:
			f = 12.34;																												// hier lesen - Beispielwert für Keller
			break;
		case 2:
			f = 13.56;																												// hier lesen - Beispielwert für Boden
			break;
		case 3:
			f = 14.78;																												// hier lesen - Beispielwert für Schuppen
			break;
	}
	rstore.updateSensorData(sensor, f);																		// Update the sensor data in the Store class
}
