# Sensor
Version: 1.0.1<br>
Ein Applications-Fragment das Daten aufnimmt und für die weitere Bearbeitung bereit stellt.<br>
Die konkreten Ein- und Ausgabe Funktionen sind nicht implementiert, hier muss eine Erweiterung erfolgen.<br>
Die einzelnen Files beinhalten:<br>
#### src/main.cpp
	Wie immer: Initialisierung und Steuerung der App.
#### src/settings.h
	Globale Konstanten, Typen usw.
	Tipp: Eine exakte Übereinstimmung zwischen 'SENSOR_NAMES' und 'WatchPoint_t' ist zwar nicht erforderlich, aber hilfreich.
#### src/stores.h - Klasse Store
	Sammlung aller Daten mit implementierten allgemeinen Ein- und Ausgabe Funktionen in der Klasse.
	Das Datenformat ist 'float'. Folgende Werte werden gespeichert: Aktuell, Minimum, Maximum und Durchschnitt.
#### src/inputs.h - Klasse Scanner
	Einlesen und in Store ablegen.
	Hierzu muss die update-Funktion angepasst werden.
	Die Werte müssen im Format 'float' vorliegen.
#### src/outputs.h - Klasse Viewer
	Ausgabe der Daten.
	Die Ausgabe erfogt im Format: Zeiger auf Char. 
	Beispiel für die Ausgabe über die serielle Schnittstelle in main.cpp.
	Für eigene Anpassungen die update-Funktion benutzen!
	Falls der 'f-Spezifer' nicht funktioniert(Arduino und co.) sollte die alterntive Methode(dtostrf) benutzt werden.
## Anmerkung
	Das Programm wurde wegen fehlenden In/Out Modulen nie geflasht.
	Aber der Compiler hat keinerlei Einwände, also: Augen zu und durch!
	Ich wünsche viel Erfolg bei den Anpassungen und im Einsatz.
