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
	float f = 11.44;																												// Hier sollte der entsprechende Sensorwert gelesen werden, z.B. von einem Temperatursensor
	rstore.updateSensorData(sensor, f);																			// Update the sensor data in the Store class
};
