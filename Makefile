# Copyright (c) 2021 ozforester. All rights reserved.
# Use of this source code is goverened by a MIT license
# that can be found in the LICENSE file.


TARGET	 = streetlighter
SOURCES := $(wildcard *.c)
OBJECTS  = $(SOURCES:.c=.o)
HEX = $(SOURCES:.c=.hex)
F_CPU = 4000000L

all:
	avr-gcc -DF_CPU=${F_CPU} -Wall -Os -mmcu=atmega8 -o ${TARGET}.o ${TARGET}.c
	avr-ld -o ${TARGET}.elf ${TARGET}.o
	avr-objcopy -O ihex ${TARGET}.elf ${TARGET}.hex
	avr-size ${TARGET}.elf
	avr-size ${TARGET}.hex

flash:
	avrdude -c usbasp -p m8 -B 1 -U flash:w:${TARGET}.hex

clean:
	rm -f $(OBJECTS) $(TARGET) $(TARGET).elf $(TARGET).hex