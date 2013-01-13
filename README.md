Py_Games_Controller V1
======================

Open source controller for Python especially for pygames library

Schematic
======================
The schematic for the project can be found here (http://py-games-controller.googlecode.com/files/Pygames%20Controller%20Schematic.pdf)

Installation
======================
This installation is for windows. I will look into installing it for Linuix in the future
* Python Installation:
	* Install Python 2.7 (http://www.python.org/download/releases/2.7/)
	* Install the serial library (http://pypi.python.org/pypi/pyserial)
	* Take the pygamescontroller.py file, and place in the same directory as your main python file
	* On the top of your main python script, type the following command 
            import pygamescontroller
* Firmware Installation:
	* Create a new project in MPLab X. For help creating the project, see this tutorial
     (http://coolcapengineer.wordpress.com/2012/12/20/tutorials-beginners-guide-to-pic18-microcontrollers/)
	* Place your main.c, controller.c, and controller.h files inside your project directory
	* In MPLab X, right click on your project's header folder, select "add exisiting files" and select 
     your controller.h file
  * In MPLab X, right click on your project's source folder, select "add exisiting files" and select 
     your controller.c and main.c
  * After you created the controller circuit, connected your FTDI breakout board, and your PICKIT3 programmer
     click on Build Project
  * After selecting build project, then click on program project
 
Functions
======================
* controller(com port, baudrate): creates the controller object. Specify com port using single quotation marks. Specify baudrate as anumber
	* Example: my_controller=controller('COM21',115200)
* iscontrollerconnected(): Checks to see if the controller is connected to the python script.Returns true if the controller is connected. Returns false if controller is not connected
* checkleftjoystickx(): Returns 1 if the left joystick is pointing right, returns 0 if the left joystick is in neutral position, and returns 2 if the left joystick is pointing left
* checkleftjoysticky(): Returns 1 if the left joystick is pointing up, returns 0 if the left joystick is in neutral position, and returns 2 if the left joystick is pointing down
* checkrightjoystickx(): Returns 1 if the right joystick is pointing right, returns 0 if the right joystick is in neutral position, and returns 2 if the right joystick is pointing left
* checkrightjoysticky(): Returns 1 if the right joystick is pointing up, returns 0 if the right joystick is in neutral position, and returns 2 if the right joystick is pointing down
* checkyellowbutton(): Returns 1 if the yellow button is pressed, and 0 if the yellow button is not pressed
* checkredbutton(): Returns 1 if the red button is pressed, and 0 if the red button is not pressed
