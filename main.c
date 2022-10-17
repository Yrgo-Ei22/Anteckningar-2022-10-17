/********************************************************************************
* error_code1: Enkel GPIO-implementering inneh�llande ett flertal fel, som
*              skall korrigeras av den studerande. Koden �r h�r korrigerad.
********************************************************************************/
#include "gpio.h"

/********************************************************************************
* main: Initierar mikrodatorns I/O-portar vid start. Programmet exekverar sedan
*       kontinuerligt s� l�nge matningssp�nning tillf�rs. Vid nedtryckning av
*       tryckknappen blinkar lysdioderna i en sekvens var 100:e millisekund,
*       annars blinkar de kollektivt var 500:e millisekund.
********************************************************************************/
int main(void)
{
    setup();

    while (true) 
    {
       if (BUTTON1_IS_PRESSED)
       {
          leds_blink_sequence(100);
       }
       else
       {
          leds_blink_collectively(500);
       }

    }

    return 0;
}

// PIN 0 - 7 => I/O-port D (PORTD0 - PORTD7)
// PIN 8 - 13 => I/O-port B (PORTB0 - PORTB5).
// PIN A0 - A5 => I/O-port C (PORTC0 - PORTC5).

// DDRB => v�ljer datariktning, 1 = utport, 0 = input.
// PORTB => skriver utsignaler och aktiverar pullup-resistorer f�r inportar.
// PINB => l�ser av insignaler.

