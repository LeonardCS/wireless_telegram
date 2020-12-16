# wireless_telegram
DWZ GPX van groene energie uit Arnhem.

Een Dwz GPX idee.

serial_read is de lezende en versturende kant van de set.
serial_receive is de ontvangende kant van de set.

ToDo: 
1. telegram weer goed ontvangen (is laatst weer niet gaan werken).
2. received chars dynamisch opslaan in 32byte data sets (mogelijk met structs en data parsing het beste te regelen).
3. radio.write de goede data in de juiste volgorde door laten sturen.
4. code test serial_read.
5. serial_receive instellen zodat de data goed ontvangen kan worden.
6. ontvangen data weer samenvoegen.
7. ontvangen data over serial naar de rj12 sturen.
8. ontvangen data dumpen en opnieuw luisteren naar nieuwe data.
9. code test serial_receive
