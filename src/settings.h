#pragma once
#include <Arduino.h>

// Hardware-Pins
#define BUTTON_PIN 21

// Zeiger auf konstante Zeichenkette
typedef const char* pchar; 																							

// 864000000 milliseconds = 24 hours
constexpr uint8_t BASE = 96;																						// Historie - Messwerte in 24 Stunden
constexpr uint32_t BASE_INTERVAL = 900000; 															// 15 Minuten - Zeitintervall für die Historie
constexpr uint32_t BUTTON_BLOCK_TIME = 100; 														// 100 milliseconds - Blockzeit für den Taster
constexpr uint8_t MAX_AVERAGE = 10; 																		// Maximale Anzahl zur Berechnung von Durchschnittswerten
constexpr uint32_t SHORT_UPDATE_INTERVAL = 50; 													// 50 milliseconds - Pause zwischen den einzelnen Messungen der Sensoren

// Konstanten für die Anzahl der Sensoren, Messungen und die Namen der Sensoren
constexpr uint8_t SENSORS = 4;																					// Anzahl der Sensoren - Messpunkte
constexpr uint8_t MEASUREMENTS = 4;																			// Anzahl der gespeicherten Werte pro Sensor
constexpr uint8_t MENUES = 8; 																					// Anzahl der Menüs für die Anzeige

constexpr pchar SENSOR_NAMES[SENSORS] = {																// Array mit den Namen der Sensoren für die Anzeige)
	"LAUBE", "KELLER", "BODEN", "SCHUPPEN"
}; 	
constexpr pchar MPNAMES[MEASUREMENTS] = {
	"Durchschnitt", "Minimum", "Maximum", "Aktuell" 
};

typedef enum {																													// Nummerische Werte für die Messungen, die in der Schleife durchlaufen werden
	AVERAGE = 0,
	MINIMUM,
	MAXIMUM,
	ACTUAL
} Measured_t;

typedef enum {
	NONE = 0,
	PRESS,
	SHORT,
	LONG
} ButtonState_t;

// Vorwärtsdeklaration der Klassen - schützt vor zirkulären Abhängigkeiten
class Store;
class Scanner;
class Viewer;
class Handler;
