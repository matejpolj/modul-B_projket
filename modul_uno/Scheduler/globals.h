#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include <stdint.h>

/// medfunkcijske spremenljivke za komunikacijo

extern uint8_t but; /// stanje tipk
extern uint8_t status; /// trenutni status
extern uint8_t level; /// nivo trenutne izbire
extern uint8_t sumlevel; /// skupni nivo
extern uint8_t statusFill; /// status polnjenja
extern uint16_t adc_level; /// level za adc varovalo
extern uint8_t flag; /// varovalo za uporabo tipk


#endif // GLOBALS_H_INCLUDED
