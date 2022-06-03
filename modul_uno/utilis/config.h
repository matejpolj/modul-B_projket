#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <avr/io.h>

/// komanda: /mnt/a4b5d085-eea2-4a2e-847d-8e6738b9fd2c/arduino-1.8.13/hardware/tools/avr/bin/avrdude -C/mnt/a4b5d085-eea2-4a2e-847d-8e6738b9fd2c/arduino-1.8.13/hardware/tools/avr/etc/avrdude.conf -v -patmega2560 -cwiring -P/dev/ttyUSB1 -b115200 -D -U


// definiramo vse priključke za LED
#define LEDR PB2 //10
#define LEDG PB4 //12
#define LEDB PB3 //11
#define LEDsys  PB5//13

// definirajmo vse tipke
#define BUTL PB0 //8
#define BUTR PB1 //9

// definirajmo waterlevel meter
//#define d 1

// definiramo vse priključke za releje
#define REL1 PC1 //a1
#define REL2 PC2 //a2
#define REL3 PC3 //a3
#define REL4 PC5 //a5


// definirajmo vse za adc
#define ADCchannel 0
#endif // CONFIG_H_INCLUDED
