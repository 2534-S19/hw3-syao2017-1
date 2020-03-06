#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{




    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;
    bool check = false;


    unsigned char history = 0x0000;

    // TODO: Declare the variables that main uses to interact with your state machine.


    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while(1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if (timer0Expired())
        {
            if (count0 >= 7)
                count0 = 0;
            else count0++;
        }


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired())
        {
          history = history << 1;
          history |= checkStatus_BoosterpackS1();
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        check = fsmBoosterpackButtonS1(history);


        // TODO: If a completed, debounced button press has occurred, increment count1.
        if(check == true)
        {
            if(count1 >= 7)
                count1 = 0;
            count1++;
        }


    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count)
{

    switch(count)
    {
        case 0:
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;

        case 1:
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;

        case 2:
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;

        case 3:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;

        case 4:
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Blue();
            turnOff_LaunchpadLED2Green();
            break;

        case 5:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Blue();
            turnOff_LaunchpadLED2Green();
            break;

        case 6:
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Green();
            break;

        case 7:
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Blue();
            turnOn_LaunchpadLED2Green();
            break;
    }

}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count)
{

    if (count == 0)//clear
    {
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
    }
    else if (count == 1)//red
    {
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDBlue();
    }
    else if (count == 2)//green
    {
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
    }
    else if (count == 3)//yellow
    {
        turnOff_BoosterpackLEDBlue();
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
    }
    else if (count == 4)//blue
    {
        turnOff_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDBlue();
    }
    else if (count == 5)//magenta
    {
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDBlue();
    }
    else if (count == 6)//cyan
    {
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    }
    else if (count == 7)//white
    {
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.

bool fsmBoosterpackButtonS1(unsigned char buttonhistory)
{
    typedef enum {release, RtoP, pushed, PtoR} position;
    static position pos = release;

    bool pressed = false;

    switch (pos){

    case release:
        if(buttonhistory &= BIT0)
            pos = RtoP;
        break;

    case RtoP:
        if(buttonhistory &= BIT0)
            pos = pushed;
        else
            pos = release;
        break;

    case pushed:
        if(buttonhistory &= BIT0)
            pos = PtoR;
        break;

    case PtoR:
        pressed = true;
        pos = release;
        break;

    }

    return pressed;
}
