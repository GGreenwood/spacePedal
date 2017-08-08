#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define GET_BIT(TGT, PIN)    ((TGT) & (1 << (PIN)))
#define SET_BIT(TGT, PIN)    do { TGT |=  (1 << (PIN)); } while(0)
#define CLEAR_BIT(TGT, PIN)  do { TGT &= ~(1 << (PIN)); } while(0)
#define TOGGLE_BIT(TGT, PIN) do { TGT ^= (1 << (PIN)); } while(0)

#define PIN_LED	PB1
#define PIN_SWITCH	PB2

int main(void)
{
	SET_BIT(DDRB, PIN_LED);		// Set LED pin as output
	CLEAR_BIT(DDRB, PIN_SWITCH);	// Set switch pin as input

	while(1)
	{
		if(GET_BIT(PINB, PIN_SWITCH)) {
			CLEAR_BIT(PORTB, PIN_LED);
		} else {
			SET_BIT(PORTB, PIN_LED);
		}
	}
}
