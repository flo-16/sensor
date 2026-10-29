#pragma once
#include <Arduino.h>

// Zeiger auf konstante Zeichenkette
typedef const char* pchar; 																							

// Konstanten für die Anzahl der Sensoren, Messungen und die Namen der Sensoren
constexpr uint8_t SENSORS = 4;																					// Anzahl der Sensoren - Messpunkte
constexpr uint8_t MEASUREMENTS = 4;																			// Anzahl der gespeicherten Werte pro Sensor
constexpr pchar SENSOR_NAMES[SENSORS] = {																// Array mit den Namen der Sensoren für die Anzeige)
	"LAUBE",
	"KELLER",
	"BODEN",
	"SCHUPPEN"
}; 	

constexpr uint32_t SHORT_UPDATE_INTERVAL = 50; 													// 50 milliseconds - Pause zwischen den einzelnen Messungen der Sensoren
constexpr uint32_t LONG_UPDATE_INTERVAL = 1000; 												// 1 second - Pause nach dem Lesen aller Sensoren

constexpr uint8_t MAX_AVERAGE = 32; 																		// Maximale Anzahl zur Berechnung von Durchschnittswerten
constexpr uint8_t MAX_STRING_LENGTH = 16; 															// Maximale Länge der Strings für die Anzeige																							

// Enum-Typen für die Sensoren und Messungen, die in der Schleife durchlaufen werden
typedef enum {																													// Nummerische Werte für die Sensoren, die in der Schleife durchlaufen werden
	LAUBE = 0,
	KELLER,
	BODEN,
	SCHUPPEN,
	NO_SENSOR																															// Stopper - nicht ändern, da er als Abbruchbedingung in der Schleife dient
} WatchPoint_t;

typedef enum {																													// Nummerische Werte für die Messungen, die in der Schleife durchlaufen werden
	AVERAGE = 0,
	MINIMUM,
	MAXIMUM,
	ACTUAL
} Measured_t;

// Vorwärtsdeklaration der Klassen - schützt vor zirkulären Abhängigkeiten
class Store;
class Scanner;
class Viewer;
