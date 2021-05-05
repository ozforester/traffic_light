/*
Copyright (c) 2021 ozforester. All rights reserved.
Use of this source code is goverened by a MIT license
that can be found in the LICENSE file.
*/

// I went to check 3 LEDs for a next repo but connecting them to DC source looked too easy (:

#include <avr/io.h>
#include <util/delay.h>

#define INIT() { DDRB |= ((1 << PB0) | (1 << PB1) | (1 << PB2)); PORTB &= ~((1 << PB0) | (1 << PB1) | (1 << PB2)); }
#define GREEN_LIGHT() { PORTB |= (1 << PB2); _delay_ms(3000); PORTB ^= (1 << PB2); }
#define GREEN_BLINK() { for(uint8_t i=0; i<6; i++) { PORTB ^= (1 << PB2); _delay_ms(500); } }
#define YELLOW_LIGHT() { PORTB |= (1 << PB1); _delay_ms(1000) ; PORTB ^= (1 << PB1); }
#define RED_LIGHT() { PORTB |= (1 << PB0); _delay_ms(3000); PORTB &= ~(1 << PB0); }
#define REDYELL_LIGHT() { PORTB |= (1<<PB0 | 1<<PB1); _delay_ms(1000); PORTB &= ~(1<<PB0 | 1<<PB1); }

int main( void ){
  INIT();
  while(1){
    RED_LIGHT();
    REDYELL_LIGHT();
    GREEN_LIGHT();
    GREEN_BLINK();
    YELLOW_LIGHT();
  }
}
