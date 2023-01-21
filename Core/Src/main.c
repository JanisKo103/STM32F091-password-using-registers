#include "stm32f0xx.h"

// Assign numbers to button names/pins
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7
#define PB8 8
#define PB9 9
#define PB10 10
#define PB11 11
#define PB12 12
#define PB13 13

// Initialize GPIOA and GPIOB clock signal
void ClockConfig()
{
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
}

// Configure the IO pins
void PinConfig()
{
    // Initialize PA4 and PA5 as output
    GPIOA->MODER |= (1 << 8);
    GPIOA->MODER |= (1 << 10);

    // Initialize PB4-PB13 as inputs
    for(int i=4; i<=13; i++)
    GPIOB->MODER &= ~(1 << (i*2));
}


int main(void)
{
	// Configure clock signals and IO pins
	ClockConfig();
	PinConfig();

    const int correct_order[10] = {PB4, PB4, PB6, PB7, PB8, PB9, PB10, PB11, PB13, PB13};// Array with the correct button order
    int button_order[10] = {0}; // Array to keep track of the buttons pressed
    int i = 0; // Variable to keep track how many times the buttons are pressed
    int correct = 1; // This variable stores the result of "correct_order" and "button_order" comparison

    while (1)
    {
        while (i < 10)
        {
            // Check if any of the buttons are pressed and if so than store info which button was pressed
            for (int j = 4; j <= 13; j++)
            {
                if ((GPIOB->IDR & (1 << j)) == 0)
                {
                	button_order[i] = j;
                	i++;

                	// Wait until the button is released before continue
                	while ((GPIOB->IDR & (1 << j)) == 0)
                	{
                		__NOP();
                	}
                	// Add a small delay to filter unwanted noise while the button is being released
                	for (int k = 0; k<200000; k++)
                	{
                		__NOP();
                	}

                    break;
                }
            }
        }

        if (i == 10)
        {
            correct = 1; // if the order is correct, this value stays "1"

            // Compare the "button_order" array to the "correct_order" array
            for (int j = 0; j < 10; j++)
            {
                if (button_order[j] != correct_order[j])
                {
                    correct = 0;
                    break;
                }
            }

            // Turn on an LED depending on the result
            if (correct)
            {
                GPIOA->BSRR = (1 << 4);
            }
            else
            {
                GPIOA->BSRR = (1 << 5);
            }

            // Reset the button press tracking variables
            i = 0;
            for (int j = 0; j < 10; j++)
            {
                button_order[j] = 0;
            }
        }

        // Display the result for few seconds
        for (int j = 0; j < 2000000; j++)
        {
        	__NOP();
        }

        // Reset LEDs before the next password input attempt
        GPIOA->BRR = (1 << 4);
        GPIOA->BRR = (1 << 5);
    }

    return 0;
}


