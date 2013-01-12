#==================================================================================================
#	Imports
#==================================================================================================
import serial	#Import the serial library from python
#==================================================================================================
#	
#==================================================================================================




#==================================================================================================
#	Controller Class
#==================================================================================================
class controller:
    def __init__(self,com_port,baudrate):                           
        self.controller_port=com_port
        self.controller_baudrate=baudrate
    def iscontrollerconnected(self):
        try:
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("c")
            while 1:
                ping_back_value=controller.read()
                if ping_back_value=="1":
                    controller.close()
                    return True
                else:
                    controller.close()
                    return False
        except:
            return False
    def checkleftjoystickx(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("j")
            controller.write("l")
            controller.write("x")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
    def checkleftjoysticky(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("j")
            controller.write("l")
            controller.write("y")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
    def checkrightjoystickx(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("j")
            controller.write("r")
            controller.write("x")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
    def checkrightjoysticky(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("j")
            controller.write("r")
            controller.write("y")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
    def checkyellowbutton(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("b")
            controller.write("y")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
    def checkredbutton(self):
        if self.iscontrollerconnected():
            controller=serial.Serial(self.controller_port,self.controller_baudrate,timeout=1)
            controller.write("b")
            controller.write("r")
            while 1:
                reading=controller.read()
                controller.close()
                return reading
        else:
            return -1
       
#==================================================================================================
#	
#==================================================================================================

py_games_controller=controller('COM21',115200)
print py_games_controller.checkredbutton()
