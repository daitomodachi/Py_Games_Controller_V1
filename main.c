//===============================================================================================
//	Includes, defines, and global variables
//===============================================================================================
#include "controller.h"
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config PBADEN = OFF
#pragma config LVP = OFF
#pragma config PWRT = ON
#pragma config DEBUG=OFF
char message[100];
//===============================================================================================
//
//===============================================================================================




//===============================================================================================
//  Main loop
//===============================================================================================
void main(void)
{
    char reading;
    CONTROLLER PY_GAMES_CONTROLLER;
    CONTROLLER_INIT(&PY_GAMES_CONTROLLER);

    //	Set all of PORTC as outputs
    TRISC=0x00;

    //	Configure UART
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE &USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 10);
    Delay1KTCYx(4);

    while(1)
    {
        while(!DataRdyUSART());
        reading=ReadUSART();

        // Checks to see if the current reading is equal to c, which means check to see if the controller is connected
        if(reading=='c')
        {
            sprintf(message,"1");
            putsUSART(message);
            Delay1KTCYx(4);
        }
        else if(reading=='j')
        {
             // Waits for the next data to be sent
             while(!DataRdyUSART());
             reading=ReadUSART();

             // Checks to see if the next reading is equal to l, or left
             if(reading=='l')
             {
                 // Waits for the next data to come in
                  while(!DataRdyUSART());
                  reading=ReadUSART();

                  //    Checks to see if x axis data is requested
                  if(reading=='x')
                  {
                      int result=READJOYSTICKX(&PY_GAMES_CONTROLLER.LEFT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
                  //    Check to see if y axis data is requested
                  else if(reading=='y')
                  {
                      int result=READJOYSTICKY(&PY_GAMES_CONTROLLER.LEFT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }


             }
             else if(reading=='r')
             {
                 // Waits for the next data to come in
                  while(!DataRdyUSART());
                  reading=ReadUSART();

                  //    Checks to see if x axis data is requested
                  if(reading=='x')
                  {
                      int result=READJOYSTICKX(&PY_GAMES_CONTROLLER.RIGHT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
                  //    Check to see if y axis data is requested
                  else if(reading=='y')
                  {
                      int result=READJOYSTICKY(&PY_GAMES_CONTROLLER.RIGHT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
             }

        }
        else if(reading=='b')
        {
            // Waits for the next data to come in
            while(!DataRdyUSART());
            reading=ReadUSART();

            if(reading=='y')
            {
                int result=ISBUTTONPRESSED(&PY_GAMES_CONTROLLER.YELLOW_BUTTON);
                sprintf(message,"%d",result);
                putsUSART(message);
                Delay1KTCYx(4);
            }
            else if(reading=='r')
            {
                int result=ISBUTTONPRESSED(&PY_GAMES_CONTROLLER.RED_BUTTON);
                sprintf(message,"%d",result);
                putsUSART(message);
                Delay1KTCYx(4);
            }
        }







    }


}
//===============================================================================================
//
//===============================================================================================
