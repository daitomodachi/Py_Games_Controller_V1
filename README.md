Py_Games_Controller_V1
======================

Open source controller for Python especially for pygames library

Installation
======================
This installation is for windows. I will look into installing it for Linuix in the future
Python Installation:
  1) Install Python 2.7 (http://www.python.org/download/releases/2.7/)
  2) Install the serial library (http://pypi.python.org/pypi/pyserial)
  3) Take the pygamescontroller.py file, and place in the same directoy as your main python file
  4) On the top of your main python script, type the following command 
            import pygamescontroller
MPlab X Installation:
  1) Create a new project in MPLab X. For help creating the project, see this tutorial
     (http://coolcapengineer.wordpress.com/2012/12/20/tutorials-beginners-guide-to-pic18-microcontrollers/)
  2) Place your main.c, controller.c, and controller.h files inside your project directory
  3) In MPLab X, right click on your project's header folder, select "add exisiting files" and select 
     your controller.h file
  4) In MPLab X, right click on your project's source folder, select "add exisiting files" and select 
     your controller.c and main.c
  5) After you created the controller circuit, connected your FTDI breakout board, and your PICKIT3 programmer
     click on Build Project
  6) After selecting build project, then click on program project
