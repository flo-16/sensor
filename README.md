# Sensor
### Version: 2.1.1  
&emsp;Ein Applications-Fragment das Daten aufnimmt und für die weitere Bearbeitung bereit stellt.    
&emsp;Die konkreten Eingabe Funktionen sind nicht implementiert, hier muss eine Erweiterung erfolgen.    
&emsp;Die Ausgabe der momentanen Werte erfolgt über die serielle Schnittstelle.    
&emsp;Der Button zur Auslöse der seriellen Schnittstelle ist implementiert.    
&emsp;Die einzelnen Files beinhalten:      
#### src/main.cpp
	Wie immer: Initialisierung und Steuerung der App.
	Das gesamte Handling der App wird über die Funktion 'handler' gesteuert.
#### src/settings.h
	Globale Konstanten, Typen, Vorwärtsdeklarationen usw.
#### src/trend.h - Klasse Trend  
	Aufbau einer Reihe von Messpunkten.
	Diese können dann z.B. als Diagramm ausgegeben werden.
	Als Platzhalter für die Ausgabe ist die Methode Viewer::setDiagramm vorgesehen.
#### src/stores.h - Klasse Store
	Sammlung aller Daten mit implementierten allgemeinen Ein- und Ausgabe Funktionen in der Klasse.
	Das Datenformat ist 'float'. Folgende Werte werden gespeichert: Aktuell, Minimum, Maximum und Durchschnitt.
#### src/inputs.h - Klasse Scanner
	Einlesen und in Store ablegen.
	Ein entsprechender Analog-Chip ist nicht definiert.
	Hierzu muss der Chip in der Klasse Scanner implementiert und die update-Funktion angepasst werden.
	Die Messwerte müssen im Format 'float' vorliegen.
#### src/outputs.h - Klasse Viewer
	Ausgabe der Daten über eine Methode dieser Klasse.
	Falls der 'f-Spezifer' nicht funktioniert(Arduino und co.) sollte als alterntive Methode(dtostrf) benutzt werden.
	Die Ausgabe erfolgt über die Methoden getStoreMenue(seriell) und setDiagramm(OLE).
## Anmerkung
	Das Programm wurde wegen fehlenden In/Out Modulen nie geflasht.
	Aber der Compiler hat keinerlei Einwände, also: Augen zu und durch!
	Und für den Feinschliff gilt die uralte Weisheit:
# Mist rein - Mist raus	
	Viel Erfolg bei den Anpassungen und im Einsatz.
