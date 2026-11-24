#pragma once
#include <Arduino.h>

// Hardware-Pins
#define PIN_BUTTON_SERIELL 21

// Zeiger auf konstante Zeichenkette
typedef const char* pchar; 																							

// Konstanten für die Anzahl der Sensoren, Messungen und die Namen der Sensoren
constexpr uint8_t SENSORS = 4;																					// Anzahl der Sensoren - Messpunkte
constexpr uint8_t MEASUREMENTS = 4;																			// Anzahl der gespeicherten Werte pro Sensor
constexpr pchar SENSOR_NAMES[SENSORS] = {																// Array mit den Namen der Sensoren für die Anzeige)
	"LAUBE", "KELLER", "BODEN", "SCHUPPEN"
}; 	
constexpr pchar MPNAMES[MEASUREMENTS] = {
	"Durchschnitt", "Minimum", "Maximum", "Aktuell" 
};

constexpr uint8_t MAX_AVERAGE = 32; 																		// Maximale Anzahl zur Berechnung von Durchschnittswerten
constexpr uint8_t MAX_DIAGRAMM_POINTS = 16; 														// Maximale Anzahl zur Speicherung von Trend-Daten

// Zeitkonstanten
constexpr uint32_t SHORT_UPDATE_INTERVAL = 50; 													// 50 milliseconds - Pause zwischen den einzelnen Messungen der Sensoren
constexpr uint32_t LONG_UPDATE_INTERVAL = 1000; 												// 1 second - Pause nach dem Lesen aller Sensoren
constexpr uint32_t TREND_UPDATE_INTERVAL = 60000; 											// 1 Minute - Pause für  Trend-Daten(links shift)
constexpr uint32_t BUTTON_BLOCK_TIME = 200; 														// 200 milliseconds - Blockzeit für den Taster
// max. Stringlängen																		
constexpr uint8_t MAX_TREND_LENGTH = 16; 																// Maximale Länge der Trend-Daten für die Anzeige
constexpr uint8_t MAX_BUFFER_LENGTH = 160; 															// Maximale Länge des Buffers für die Anzeige

typedef enum {																													// Nummerische Werte für die Messungen, die in der Schleife durchlaufen werden
	AVERAGE = 0,
	MINIMUM,
	MAXIMUM,
	ACTUAL
} Measured_t;

// Vorwärtsdeklaration der Klassen - schützt vor zirkulären Abhängigkeiten
class Trend;
class Store;
class Scanner;
class Viewer;
