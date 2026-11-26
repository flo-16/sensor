# Sensor
### Version: 3.0.0  
&emsp;Ein Applications-Fragment das Daten aufnimmt und für die weitere Bearbeitung bereit stellt.   
&emsp;Die konkreten Eingabe Funktionen sind nicht implementiert, hier muss eine Erweiterung erfolgen.    
&emsp;Die Ausgabe der momentanen Werte erfolgt über die serielle Schnittstelle.    
&emsp;Der Button zur Auslöse der seriellen Schnittstelle ist implementiert.    
&emsp;Die einzelnen Files beinhalten:     
#### src/main.cpp
&emsp;Wie immer: Initialisierung der App und der Klasseninstanzen.<br>
#### src/settings.h
&emsp;Globale Konstanten, Typen, Vorwärtsdeklarationen usw.<br>
#### src/trend.h - Klasse Trend  
&emsp;Aufbau einer Reihe von Messpunkten.<br>
&emsp;Diese können dann z.B. als Diagramm ausgegeben werden.<br>
&emsp;Als Platzhalter für die Ausgabe ist die Methode Viewer::setDiagramm vorgesehen.<br>
#### src/stores.h - Klasse Store
&emsp;Sammlung aller Daten mit implementierten allgemeinen Ein- und Ausgabe Funktionen in der Klasse.<br>
&emsp;Das Datenformat ist 'float'. Folgende Werte werden gespeichert: Aktuell, Minimum, Maximum und Durchschnitt.<br>
#### src/inputs.h - Klasse Scanner
&emsp;Einlesen und in Store ablegen.<br>
&emsp;Ein entsprechender Analog-Chip ist nicht definiert.<br>
&emsp;Hierzu muss der Chip in der Klasse Scanner implementiert und die update-Funktion angepasst werden.<br>
&emsp;Die Messwerte müssen im Format 'float' vorliegen.<br>
#### src/outputs.h - Klasse Viewer
&emsp;Ausgabe der Daten über eine Methode dieser Klasse.<br>
&emsp;Falls der 'f-Spezifer' nicht funktioniert(Arduino) sollte als alterntive Methode(dtostrf) benutzt werden.<br>
&emsp;Die Ausgabe erfolgt über die Methoden getStoreMenue(seriell) und setDiagramm(OLE).<br>
#### src/handling.h - Klasse für das Menue
&emsp;Diese Klasse übernimmt das gesamte Handling und implementiert ein Menü.<br>
&emsp;Der Button unterscheidet zwischen kurzem und langem Druck.<br>
&emsp;Kurzer Druck: Nächster Menüpunkt.<br>
&emsp;Langer Druck: Sytem reset.<br>	
## Anmerkung
&emsp;Das Programm wurde wegen fehlenden In/Out Modulen nie geflasht.<br>
&emsp;Aber der Compiler hat keinerlei Einwände, also: Augen zu und durch!<br>
&emsp;Und für den Feinschliff gilt die uralte Weisheit:<br>
# Mist rein - Mist raus	
#### Viel Erfolg bei den Anpassungen und im Einsatz. Und wenn es nicht weitergeht:
## Frag die KI !!!
