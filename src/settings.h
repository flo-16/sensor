#pragma once
#include <Arduino.h>

constexpr uint8_t SENSORS = 4;																					// Anzahl der Sensoren
constexpr uint8_t MEASUREMENTS = 4;																			// Anzahl der gespeicherten Werte pro Sensor

constexpr uint32_t SHORT_UPDATE_INTERVAL = 50; 													// 50 milliseconds - Pause between sensor readings
constexpr uint32_t LONG_UPDATE_INTERVAL = 1000; 												// 1 second - Pause nach dem Lesen aller Sensoren

constexpr uint8_t MAX_AVERAGE = 32; 																		// Maximale Anzahl zur Berechnung von Durchschnittswerten

constexpr uint8_t MAX_STRING_LENGTH = 16; 															// Maximale Länge der Strings für die Anzeige


typedef enum {
	LAUBE = 0,
	KELLER,
	BODEN,
	SCHUPPEN,
	NO_SENSOR																															// stopwatch for no sensor - nicht ändern, da es als Abbruchbedingung in der Schleife dient
} WatchPoint_t;

typedef enum {
	AVERAGE = 0,
	MINIMUM,
	MAXIMUM,
	ACTUAL
} Measured_t;

// Vorwärtsdeklaration der Klassen
class Store;
class Scanner;
class Viewer;

