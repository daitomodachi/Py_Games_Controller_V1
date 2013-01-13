//===============================================================================================
//	Includes, defines, and global variables
//===============================================================================================
#include "controller.h"

// config functions, do not mess with
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
    // Creates the variable to readin the commands from the python script
    char reading;
    
    // Creates the controller structure and initizle the corresponding values
    CONTROLLER PY_GAMES_CONTROLLER;
    CONTROLLER_INIT(&PY_GAMES_CONTROLLER);

    //	Set all of PORTC as outputs
    TRISC=0x00;

    //	Configure UART
    OpenUSART(USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE &USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_HIGH, 10);
    Delay1KTCYx(4);

    while(1)
    {
        //  Wait for the next branch of data to come in and store it to the reading variable
        while(!DataRdyUSART());
        reading=ReadUSART();

        // Checks to see if the current reading is equal to c, which means check to see if the controller is connected
        if(reading=='c')
        {
            //  Sends 1 to the python script
            sprintf(message,"1");
            putsUSART(message);
            Delay1KTCYx(4);
        }
        // Checks to see if reading is equal to j for joystick
        else if(reading=='j')
        {
             // Waits for the next data to be sent and stores it to reading
             while(!DataRdyUSART());
             reading=ReadUSART();

             // Checks to see if the next reading is equal to l, or left
             if(reading=='l')
             {
                 // Waits for the next data to come in and stores it to reading
                  while(!DataRdyUSART());
                  reading=ReadUSART();

                  //    Checks to see if x axis data is requested
                  if(reading=='x')
                  {
                      // Reads in the left joystick's x axis and sends it to the python script
                      int result=READJOYSTICKX(&PY_GAMES_CONTROLLER.LEFT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
                  //    Check to see if y axis data is requested
                  else if(reading=='y')
                  {
                      // Reads the left joystick's y axis and sends the results to the python script
                      int result=READJOYSTICKY(&PY_GAMES_CONTROLLER.LEFT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }


             }
             // Checks to see if reading is equal to r for right
             else if(reading=='r')
             {
                 // Waits for the next data to come in and stores the results to reading
                  while(!DataRdyUSART());
                  reading=ReadUSART();

                  //    Checks to see if x axis data is requested
                  if(reading=='x')
                  {
                      // Reads in the right joystick's x axis and sends the results to the python script
                      int result=READJOYSTICKX(&PY_GAMES_CONTROLLER.RIGHT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
                  //    Check to see if y axis data is requested
                  else if(reading=='y')
                  {
                      // Checks the right joystick's y axis and sends the results to the python script
                      int result=READJOYSTICKY(&PY_GAMES_CONTROLLER.RIGHT_JOYSTICK);
                      sprintf(message,"%d",result);
                      putsUSART(message);
                      Delay1KTCYx(4);
                  }
             }

        }
        // Checks to see if reading is equal to b for button
        else if(reading=='b')
        {
            // Waits for the next data to come in and stores the results to reading
            while(!DataRdyUSART());
            reading=ReadUSART();
            
            // Checks to see if reading is equal to y for yellow button
            if(reading=='y')
            {
                // Checks the status of the yellow button and sends it to the python script
                int result=ISBUTTONPRESSED(&PY_GAMES_CONTROLLER.YELLOW_BUTTON);
                sprintf(message,"%d",result);
                putsUSART(message);
                Delay1KTCYx(4);
            }
            
            // Checks to see if reading is equal to r for red button
            else if(reading=='r')
            {
                //  Checks the status of the red button and sends the results to the python script
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
