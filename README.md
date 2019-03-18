# Braille Board
Code for the refreshable braille display project - by Sam Hillcoat

### Files

##### ardunio-frompyserial.ino
Ardunio code file to be uploaded to board for use with Processing-Braille-Controller.py and serial-sender.py.
It recieves serial data from the PC and actuates the pins accordingly.
*Uses pins 2-7 and 13*

##### Processing-Braille-Controller.py
Python Processing code to create pin GUI for manulally controlling pins, for use with ardunio-fromserial.ino.
Requries Python, Processing, and python processing -- Runs on ubuntu with special python env.

##### serial-sender.py
Accesses data in *states.txt* file and sends data over serial to ardunio, for use with ardunio-fromserial.ino.
Change serial port to current arduino serial port in code.

##### manual-controller.ino
**TO-DO** Control pins directly from serial monitor or ardunio code

### To-Do:
1. manual control with out python code.
2. GUI Controller for windows laptop.
3. Text --> Braille character convertion code.
  
