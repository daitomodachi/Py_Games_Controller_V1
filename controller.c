//==============================================================================
//  Important Includes
//==============================================================================
#include "controller.h"

//==============================================================================
//  
//==============================================================================




//==============================================================================
//  Controller Configuration
//==============================================================================
void CONTROLLER_INIT(CONTROLLER * MY_CONTROLLER)
{
    //	Configure ADC
    TRISA=0xFF;
    ADCON2bits.ADFM = 1;
    ADCON1bits.VCFG1=0;
    ADCON1bits.VCFG0=0;
    ADCON2bits.ACQT0=1;
    ADCON2bits.ACQT1=0;
    ADCON2bits.ACQT2=1;
    ADCON2bits.ADCS0=0;
    ADCON2bits.ADCS1=1;
    ADCON2bits.ADCS2=0;
    ADCON0bits.ADON=1;

    //  Configure PORTB as inputs
    TRISB=0x0F;
    PORTB=0x0F;

    //  Used to tell what ADC channel the left joystick is connected to
    MY_CONTROLLER.LEFT_JOYSTICK.X_ADC_CHANNEL=0;
    MY_CONTROLLER.LEFT_JOYSTICK.Y_ADC_CHANNEL=1;

    //  Used to tell what ADC channel the right joystick is connected to
    MY_CONTROLLER.RIGHT_JOYSTICK.X_ADC_CHANNEL=2;
    MY_CONTROLLER.RIGHT_JOYSTICK.Y_ADC_CHANNEL=3;
	
    //	Used to set the pins the buttons are connected to
    MY_CONTROLLER.YELLOW_BUTTON.BUTTON_PIN=1;
    MY_CONTROLLER.RED_BUTTON.BUTTON_PIN=2;
    MY_CONTROLLER.BLUE_BUTTON.BUTTON_PIN=4;
    MY_CONTROLLER.GREEN_BUTTON.BUTTON_PIN=8;
    
	
}
//==============================================================================
//  
//==============================================================================




//==============================================================================
//  Read the Joystick X Direction
//==============================================================================
int READJOYSTICKX(JOYSTICK * MY_JOYSTICK)
{
    int result;
    //  Set to the ADC channel of the joystick's X direction
    ADCON0bits.CHS=MY_JOYSTICK.X_ADC_CHANNEL;

    //  Start the ADC conversion
    ADCON0bits.GO_NOT_DONE=1;

    //Wait for the ADC to finish
    while(ADCON0bits.GO_NOT_DONE==1);

    // Store ADC reading
    result=ADRESL;
    result += (int) ADRESH << 8;
    MY_JOYSTICK.X_ADC_READING=result;
      
    // Checks to see if the joystick is leaning towards the right
    if(MY_JOYSTICK.X_ADC_READING <= 1000 && MY_JOYSTICK.X_ADC_READING >= 0){return 1;}
    //  Checks to see if the joystick is leaning towards the left
    else if(MY_JOYSTICK.X_ADC_READING >= 3000 && MY_JOYSTICK.X_ADC_READING <= 4096){return 2;}
    //  Joystick in the neutral position
    else{return 0;}
}
//==============================================================================
// 
//==============================================================================




//==============================================================================
//  Read the Joystick X Direction
//==============================================================================
int READJOYSTICKY(JOYSTICK * MY_JOYSTICK)
{
    
    //  Set to the ADC channel of the joystick's X direction
    ADCON0bits.CHS=MY_JOYSTICK.Y_ADC_CHANNEL;

    //  Start the ADC conversion
    ADCON0bits.GO_NOT_DONE=1;

    //Wait for the ADC to finish
    while(ADCON0bits.GO_NOT_DONE==1);

    // Store ADC reading
    MY_JOYSTICK.Y_ADC_READING=ADRESL;
    MY_JOYSTICK.Y_ADC_READING+= (int) ADRESH << 8;

      
    // Checks to see if the joystick is leaning towards the up
    if(MY_JOYSTICK.Y_ADC_READING <= 1000 && MY_JOYSTICK.Y_ADC_READING >= 0){return 1;}
    //  Checks to see if the joystick is leaning towards the down
    else if(MY_JOYSTICK.Y_ADC_READING >= 3000 && MY_JOYSTICK.Y_ADC_READING<= 4096){return 2;}
    //  Joystick in the neutral position
    else{return 0;}
}
//==============================================================================
// 
//==============================================================================



//==============================================================================
//  Is Button Pressed
//==============================================================================
unsigned int ISBUTTONPRESSED(BUTTON * MY_BUTTON)
{
    //  Check to see what button is pressed based on the input
    switch(MY_BUTTON.BUTTON_PIN)
    {
        //  Case for the yellow button, which is connected to RB0
        case 1:
            if(PORTBbits.RB0==0)
            {
                MY_BUTTON.BUTTON_READING=1;
                return 1;
            }
            else
            {
                MY_BUTTON.BUTTON_READING=0;
                return 0;
            }
        //  Case for the red button, which is connected to RB1
        case 2:
            if(PORTBbits.RB1==0)
            {
                MY_BUTTON.BUTTON_READING=1;
                return 1;
            }
            else
            {
                MY_BUTTON.BUTTON_READING=0;
                return 0;
            }
        //  Case for the blue button which is connected to RB2
        case 4:
            if(PORTBbits.RB2==0)
            {
                MY_BUTTON.BUTTON_READING=1;
                return 1;
            }
            else
            {
                MY_BUTTON.BUTTON_READING=0;
                return 0;
            }
        //  Case for the blue button, which is connected to RB3
        case 8:
            if(PORTBbits.RB3==0)
            {
                MY_BUTTON.BUTTON_READING=1;
                return 1;
            }
            else
            {
                MY_BUTTON.BUTTON_READING=0;
                return 0;
            }
    }
}
