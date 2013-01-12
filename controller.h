#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <p18f4553.h>
#include <stdio.h>
#include <stdlib.h>
#include <usart.h>
#include <delays.h>
#include <delays.h>
#include <portb.h>
//===============================================================================================
//	Joystick Structure
//===============================================================================================
typedef struct
{
	int X_ADC_CHANNEL;			//	ADC channel for the horizontal component of the joystick
	int Y_ADC_CHANNEL;			//	ADC channel for the vertical component of the joystick
	int	X_ADC_READING;				//	Stores the ADC reading for the horizontal component
	int	Y_ADC_READING;				//	Stores the ADC reading for the vertical component
}JOYSTICK;
//===============================================================================================
//
//===============================================================================================




//===============================================================================================
//	Button Structure
//===============================================================================================
typedef struct
{
	unsigned int BUTTON_PIN;		//	Pin which the button is connected to
	unsigned int BUTTON_READING;		//	Digital reading of the button.
}BUTTON;
//===============================================================================================
//
//===============================================================================================




//===============================================================================================
//	Controller Structure
//===============================================================================================
typedef struct
{
	JOYSTICK LEFT_JOYSTICK;				//	Left Joystick
	JOYSTICK RIGHT_JOYSTICK;			//	Right Joystick
	BUTTON	YELLOW_BUTTON;				//	Yellow Button
	BUTTON	RED_BUTTON;                             //	Red Button
	BUTTON	GREEN_BUTTON;				//	Green Button
	BUTTON	BLUE_BUTTON;				//	Blue Button
}CONTROLLER;
//===============================================================================================
//
//===============================================================================================




void CONTROLLER_INIT(CONTROLLER * MY_CONTROLLER);
int READJOYSTICKX(JOYSTICK * MY_JOYSTICK);
int READJOYSTICKY(JOYSTICK * MY_JOYSTICK);
unsigned int ISBUTTONPRESSED(BUTTON * MY_BUTTON);
#endif