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
	SET_BIT(DDRB, PIN_LED);
	while(1)
	{
		SET_BIT(PORTB, PIN_LED);
		_delay_ms(2000);
		CLEAR_BIT(PORTB, PIN_LED);
		_delay_ms(2000);
	}
}
