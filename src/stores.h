#pragma once
#include "settings.h"

class Store {
	private:
		float sensorData[SENSORS][MEASUREMENTS]; 															// 2D array to store sensor data
		uint8_t measurementCount[SENSORS]; 																		// Array to keep track of the number of measurements for each sensor
	public:
		Store() : sensorData{{0.0f, 99.9f, 0.0f, 0.0f}, {0.0f, 99.9f, 0.0f, 0.0f}, {0.0f, 99.9f, 0.0f, 0.0f}, {0.0f, 99.9f, 0.0f, 0.0f}}, measurementCount{0} {} 	
		void updateSensorData(const WatchPoint_t sensor, const float newValue);	
		float getSensorData(const WatchPoint_t sensor, const Measured_t measurement) const {
			return sensorData[sensor][measurement];
		}																					
};

void Store::updateSensorData(const WatchPoint_t sensor, const float newValue) {
	// Update the actual value
	sensorData[sensor][ACTUAL] = newValue;

	// Update the minimum value
	if (newValue < sensorData[sensor][MINIMUM]) {
		sensorData[sensor][MINIMUM] = newValue;
	}

	// Update the maximum value
	if (newValue > sensorData[sensor][MAXIMUM]) {
		sensorData[sensor][MAXIMUM] = newValue;
	}

	// Update the average value
	sensorData[sensor][AVERAGE] = (measurementCount[sensor] * sensorData[sensor][AVERAGE] + newValue) / (measurementCount[sensor] + 1);
	if(measurementCount[sensor] < MAX_AVERAGE) {
		measurementCount[sensor]++;
	}
}