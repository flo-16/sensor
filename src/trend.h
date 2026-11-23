#pragma once
#include "settings.h"

class Trend {
	private:
		float trendData[SENSORS][MAX_TREND_LENGTH]; 													// 2D array to Trend sensorLoop data
	public:
		Trend() : trendData{
			{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, 
			{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, 
			{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f}, 
			{0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f} 
		} {}	
		void addTrendData(const float v0, const float v1, const float v2, const float v3);
		float getTrendData(const uint8_t sensorLoop, const uint8_t index) const {
			uint8_t h = static_cast<uint8_t> (sensorLoop);
			return trendData[h][index];
		}																					
};

void Trend::addTrendData(const float v0, const float v1, const float v2, const float v3) {
	// Shift the trend data to the left
	// Add the new value at the end
	float newValues[SENSORS] = {v0, v1, v2, v3};
	for (uint8_t sensorLoop = 0; sensorLoop < SENSORS; sensorLoop++) {
		for (uint8_t i = 0; i < MAX_TREND_LENGTH - 1; i++) {
			trendData[sensorLoop][i] = trendData[sensorLoop][i + 1];
		}
		trendData[sensorLoop][MAX_TREND_LENGTH - 1] = newValues[sensorLoop];
	}
}	

