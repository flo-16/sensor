#pragma once
#include "outputs.h"

class Handler {
	private:
		Store& rstore;																// Referenz auf die Store-Klasse
		Scanner& rscanner;														// Referenz auf die Scanner-Klasse
		Viewer& rviewer;															// Referenz auf die Viewer-Klasse
		uint8_t menue;																// Aktuelles Menü
		uint32_t buttonBlock;													// Zeitstempel für den Button-Block
		ButtonState_t buttonState;										// Aktueller Zustand des Tasters
		uint32_t nextScan;														// Zeitstempel für den nächsten Scan
		uint8_t actSensor;														// Aktuell ausgewählter Sensor
		uint8_t counter;															// Zähler für die Anzahl der vollständigen Scans
		void buttonHandler(const uint32_t ticks);			// Funktion zur Handhabung des Tasters
	public:
		Handler(Store& storeRef, Scanner& scannerRef, Viewer& viewerRef) : 
			rstore(storeRef), rscanner(scannerRef), rviewer(viewerRef), menue(0), buttonBlock(0), buttonState(NONE) { initialize(); } 								
		void initialize();
		void update(const uint32_t ticks);
};

void Handler::initialize() {
	nextScan = 0;																		// Initialize the next scan time
	actSensor = 0;																	// Initialize the active sensor index
	counter = 0;																		// Initialize the counter for the number of complete scans
	buttonBlock = 0;																// Initialize the button block time
	buttonState = NONE;															// Initialize the button state
}

void Handler::update(const uint32_t ticks) {

	if(ticks > nextScan) {
		rscanner.update(actSensor); 									// Update the Scanner class for the active sensor
		actSensor++;																	// Move to the next sensor
		if(actSensor == SENSORS) {										// If all sensors have been scanned, reset the active sensor index and set the next scan time for the next cycle
			actSensor = 0;
			nextScan += ticks + BASE_INTERVAL; 					// Set the next scan time for the next cycle after all sensors have been scanned
			counter++;																	// Increment the counter for the number of complete scans
		}	
		else {
			nextScan = ticks + SHORT_UPDATE_INTERVAL;		// Set the next scan time
		}
	}

	if(counter == BASE) {														// If the counter reaches the BASE value:
		rstore.addHistoricalData(); 									// Add historical data to the Store class
		rstore.historyDataToFile(); 									// Write historical data to file
		rstore.resetSensorData(); 										// Reset the sensor data in the Store class
		initialize();
	}

	buttonHandler(ticks); 														// Call the button handler function to check for button presses
}

void Handler::buttonHandler(const uint32_t ticks) {
	if ((buttonBlock > 0) && (ticks > buttonBlock) && (buttonState == NONE)) 	{ buttonBlock = 0; }	// Button freigeben

	if ((digitalRead(BUTTON_PIN) == LOW) && (buttonState == NONE)) {
		buttonState = PRESS; 
		buttonBlock = ticks + BUTTON_BLOCK_TIME; 				// Button wurde gedrückt, Blockzeit setzen
	}	// Button wurde gedrückt

	if ((buttonBlock > 0) && (ticks > buttonBlock) && (buttonState == PRESS)) {
		buttonState = (digitalRead(BUTTON_PIN) == LOW) ? LONG : SHORT; 		// Button wurde kurz/lang gedrückt
		buttonBlock = ticks + BUTTON_BLOCK_TIME; 													// Blockzeit setzen
	}	
	
	if (buttonState == SHORT) {
		buttonState = NONE; 														// Reset button state
		menue = (menue + 1) % MENUES; 									// Increment the menu index and wrap around if it exceeds the number of menus
		switch (menue) {
			case 0:
				rviewer.seriellPrint();
				break;
			case 1:
				rviewer.setDiagramm(0); 											// Set the diagram for the first sensor
				break;
			case 2:
				rviewer.setDiagramm(1); 											// Set the diagram for the second sensor
				break;
			case 3:
				rviewer.setDiagramm(2); 											// Set the diagram for the third sensor
				break;
			case 4:
				rviewer.setDiagramm(3); 											// Set the diagram for the fourth sensor
				break;
			default:
				break;
		}
	};
	
	if (buttonState == LONG) {
		rstore.resetSensorData(); 										// Reset the sensor data in the Store class
		initialize(); 																// Reinitialize the Handler class
	}
}





