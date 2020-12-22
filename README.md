# wireless_telegram
DWZ GPX from groene energie based in Arnhem.

A Dwz GPX idea.

serial_read is de lezende en versturende kant van de set.
serial_receive is de ontvangende kant van de set.

project in progress

ToDo: 
1. receive telegram from rj12 connection (was broken in one of the last revisions).
2. store received chars in dynamic 32byte data sets (structs might be the solution).
3. progam radio.write to send the data sets in the correct order.
4. code test serial_read.
5. program serial_receive to receive the data from serial_read in the correct order.
6. combine the received data or send it along to the serial out.
7. send the received data throug serial to the rj12 connector.
8. dump the data and listen for new data.
9. code test serial_receive.
