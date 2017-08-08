PROJECTNAME = stepscape
DEVICE = attiny85
PROGRAMMER = usbtiny
F_CPU = 16000000
CC = avr-gcc
AVROBJCOPY = avr-objcopy

CFLAGS = -Wall -Os -mmcu=$(DEVICE) -DF_CPU=$(F_CPU) -std=gnu99
OBJFLAGS = -j .text -j .data -O ihex
AVRFLAGS = -p $(DEVICE) -c $(PROGRAMMER)

OBJECTS = $(wildcard *.c)
HEADERS = $(wildcard *.h)

TARGET = $(PROJECTNAME).hex

all:	$(TARGET)

microflash:	$(TARGET)
	~/git/micronucleus/commandline/micronucleus --run $(PROJECTNAME).hex

flash:	$(TARGET)
	avrdude $(AVRFLAGS) -U flash:w:$(TARGET)

clean:
	find ./ -type f \( -name '*.elf' -o -name '*.0' -o -name '*.hex' -o -name '*.o' \) -exec rm {} \;

%.hex: %.elf
	$(AVROBJCOPY) $(OBJFLAGS) $< $@

$(PROJECTNAME).elf: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

# From C source to .o object file
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# From assembler source to .o object file
%.o: %.S $(HEADERS)
	$(CC) $(CFLAGS) -x assembler-with-cpp -c $< -o $@
