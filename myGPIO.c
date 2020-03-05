/*
 * GPIO.c
 *
 *  Created on:
 *      Author:
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    GPIO_setAsInputPin(GPIO_PORT_P1 , GPIO_PIN1);
    // Launchpad S2
    GPIO_setAsInputPin(GPIO_PORT_P1 , GPIO_PIN4);
    // Boosterpack S1
    GPIO_setAsInputPin(GPIO_PORT_P5 , GPIO_PIN1);
    // Boosterpack S2
    GPIO_setAsInputPin(GPIO_PORT_P3 , GPIO_PIN5);
    // Launchpad LED1
    GPIO_setOutputLowOnPin(GPIO_PORT_P1 , GPIO_PIN0);
    // Launchpad LED2 Red
    GPIO_setAsOutputPin(GPIO_PORT_P2 , GPIO_PIN0);
    // Launchpad LED2 Green
    GPIO_setAsOutputPin(GPIO_PORT_P2 , GPIO_PIN1);
    // Launchpad LED2 Blue
    GPIO_setAsOutputPin(GPIO_PORT_P2 , GPIO_PIN2);
    // Boosterpack LED Red
    GPIO_setAsOutputPin(GPIO_PORT_P2 , GPIO_PIN6);
    // Boosterpack LED Green
    GPIO_setAsOutputPin(GPIO_PORT_P2 , GPIO_PIN4);
    // Boosterpack LED Blue
    GPIO_setAsOutputPin(GPIO_PORT_P5 , GPIO_PIN6);

    // Turn off all LEDs at the start.
    turnOff_LaunchpadLED2Red();
    turnOff_LaunchpadLED2Blue();
    turnOff_LaunchpadLED2Green();


}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1 , GPIO_PIN1);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P1 , GPIO_PIN4);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return GPIO_getInputPinValue(GPIO_PORT_P5 , GPIO_PIN1);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return GPIO_getInputPinValue(GPIO_PORT_P3 , GPIO_PIN5);
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT |= BIT0;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= ~BIT0;
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT |= BIT0;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT &= ~BIT0;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT |= BIT1;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= ~BIT1;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT |= BIT2;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= ~BIT2;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT |= BIT6;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT &= ~BIT6;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT |= BIT4;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT &= ~BIT4;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT |= BIT6;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT &= ~BIT6;
}
