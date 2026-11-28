#pragma once
#include "settings.h"

class Store {
	private:
		float sensorData[SENSORS][MEASUREMENTS]; 															// 2D array to store sensor data
		uint8_t measurementCount[SENSORS]; 																		// Array to keep track of the number of measurements for each sensor
		float historyData[SENSORS][MAX_SAVE]; 																// 2D array to store historical data for each sensor
	public:
		Store() {
			initialize(); 																											// Initialize the Store class
		};
		void initialize(); 																										// Initialize the Store class
		void resetSensorData();
		void updateSensorData(const uint8_t sensor, const float newValue);
		void addHistoricalData();
		void historyDataToFile();
		float getSensorData(const uint8_t sensor, const Measured_t measurement) const {
			return sensorData[sensor][measurement];
		}	
		float getHistoricalData(const uint8_t sensor, const uint8_t index) const {
			return historyData[sensor][index];
		}																			
	};

void Store::initialize() {
	for (uint8_t sensor = 0; sensor < SENSORS; ++sensor) {
		for (uint8_t i = 0; i < MAX_SAVE; ++i) {
			historyData[sensor][i] = 0.0f; 																			// Reset historical data
		}
	}	
	resetSensorData(); 																											// Reset all sensor data
};

void Store::resetSensorData() {
	for (uint8_t sensor = 0; sensor < SENSORS; ++sensor) {
		measurementCount[sensor] = 0; 																				// Reset measurement count
		sensorData[sensor][AVERAGE] = 0.0f; 																	// Reset average value
		sensorData[sensor][MINIMUM] = 99.9f; 																	// Reset minimum value
		sensorData[sensor][MAXIMUM] = 0.0f; 																	// Reset maximum value
		sensorData[sensor][ACTUAL] = 0.0f; 																		// Reset actual value
	}
}

void Store::updateSensorData(const uint8_t sensor, const float newValue) {
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

void Store::addHistoricalData() {
	for (uint8_t sensor = 0; sensor < SENSORS; ++sensor) {
		for (uint8_t i = 1; i < MAX_SAVE; ++i) {
			historyData[sensor][i - 1] = historyData[sensor][i]; 												// Shift historical data to the left
		}
		historyData[sensor][MAX_SAVE - 1] = sensorData[sensor][AVERAGE];
	}
}

void Store::historyDataToFile() {
	// This function is a placeholder for future implementation.
	// It can be used to write historical data to a file or external storage.
};


