#include "ledNbutton.h"
#include "utils.h"
#include "config.h"

void ledClr(int led_p) {
    /// pobrisi LED
    PORTB &= ~(1<<led_p);
}

void ledSet(int led_p) {
    /// postavi LED
    PORTB |= (1<<led_p);
}

void ledTog(int led_p) {
    /// togle LED
    PORTB ^= (1<<led_p);
}

int getButtonSta(int btn_p) {
    /// pridobi stanje izbrane tipke
    int state = (PINB & (1<<btn_p)) >> btn_p;
    return state;
}

int getButtonPrs(int btn_p) {
    /// pridobi pritisk izbrane tipke
    static int state_old = 0;

    int state = (PINB & (1<<btn_p)) >> btn_p;

    if (state_old != state) {
        state_old = state;
        if (state == 1) {
            return 1;
        }
    }
    return 0;

}

int adc_read(void) {
    /// izberemo ADC kanal in masko
    ADMUX = (ADMUX & 0xF0) | (ADCchannel & 0x0F);
    /// nastavimo single conversion mode
    ADCSRA |= (1<<ADSC);
    /// pocakamo rezultat
    while( ADCSRA & (1<<ADSC) );
    return ADC;
}

void releClr(int rele_p) {
    /// pobrisi (postavi v neg logiki) rele
    PORTC &= ~(1<<rele_p);
}

void releSet(int rele_p) {
    /// postavi (pobrisi v neg logiki) rele
    PORTC |= (1<<rele_p);
}
