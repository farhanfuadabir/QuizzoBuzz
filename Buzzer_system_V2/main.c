/*
 * Buzzer_system_V2.c
 *
 * Created: 8/10/2017 1:43:15 AM
 * Author : FUAD
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

// IN1		PA2
// OUT1		PA0
// OUT1b	PB4
// IOUT1	PA1

// IN2		PA5
// OUT2		PA3
// OUT2b	PB7
// IOUT2	PA4

// IN3		PC3
// OUT3		PC5
// OUT3b	PB5
// IOUT3	PC4

// IN4		PC2
// OUT4		PC0
// OUT4b	PB6
// IOUT4	PC1

// BUZZER	PB3

int main(void)
{
	DDRA |= (1 << PA0) | (1 << PA1) | (1 << PA3) | (1 << PA4);
	DDRC |= (1 << PC5) | (1 << PC4) | (1 << PC0) | (1 << PC1);
	DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7);
	DDRD |= (1 << PD3) | (1 << PD4);
	DDRA &= ~(1 << PA2);
	DDRA &= ~(1 << PA5);
	DDRC &= ~(1 << PC2);
	DDRC &= ~(1 << PC3);
	DDRB &= ~(1 << PB0);
	DDRD &= ~(1 << PD2);
	
	PORTA |= (1 << PA1) | (1 << PA4);
	PORTC |= (1 << PC4) | (1 << PC1);
	PORTB |= (1 << PB1);
	PORTD |= (1 << PD3);
	
	PORTA &= ~(1 << PA0);
	PORTA &= ~(1 << PA3);
	PORTC &= ~(1 << PC5);
	PORTC &= ~(1 << PC0);
	PORTB &= ~(1 << PB2);
	PORTD &= ~(1 << PD4);
	
	PORTB &= ~(1 << PB3);
	PORTB &= ~(1 << PB4);
	PORTB &= ~(1 << PB5);
	PORTB &= ~(1 << PB6);
	PORTB &= ~(1 << PB7);
	PORTD &= ~(1 << PD0);
	PORTD &= ~(1 << PD1);
    
	while (1) 
    {
		if ((PINA & (1 << PINA2)))
		{
			PORTA |= (1 << PA0);
			PORTA &= ~(1 << PA1);
			PORTD |= (1 << PD0);
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
				
			break;
		}
		
		else if ((PINA & (1 << PINA5)))
		{
			PORTA |= (1 << PA3);
			PORTA &= ~(1 << PA4);
			PORTB |= (1 << PB6);
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
			
			break;
		}
		
		else if ((PINC & (1 << PINC3)))
		{
			PORTC |= (1 << PC5);
			PORTC &= ~(1 << PC4);
			PORTB |= (1 << PB5);
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
			
			break;
		}
		
		else if ((PINC & (1 << PINC2)))
		{
			PORTC |= (1 << PC0);
			PORTC &= ~(1 << PC1);
			PORTB |= (1 << PB7);			
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
			
			break;
		}
		
		else if ((PIND & (1 << PIND2)))
		{
			PORTD |= (1 << PD4);
			PORTD &= ~(1 << PD3);
			PORTB |= (1 << PB4);
						
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
			
			break;
		}
		
		else if ((PINB & (1 << PINB0)))
		{
			PORTB |= (1 << PB2);
			PORTB &= ~(1 << PB1);
			PORTD |= (1 << PD1);
			
			PORTB |= (1 << PB3);
			_delay_ms(1500);
			PORTB &= ~(1 << PB3);
			
			break;
		}
    }
}

