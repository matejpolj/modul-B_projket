#include "utils.h"
#include "config.h"
#include "lcd.h"
#include "SSD1306.h"
#include "ledNbutton.h"

void configureLEDs(void) {
    /// nastavimo LED kot izhode
    DDRB |= (1<<LEDB) | (1<<LEDG) | (1<<LEDR) | (1<<LEDsys);
};

void configureLCD(void) {
    /// prizgemo LCD
    lcd_begin();
    lcd_set_cursor(0, 0);
    lcd_print("Hello World!");
}

void coifigureButtons(void){
    /// nastavimo tipke kot vhodi
    DDRB &= ~(1<<BUTL) & ~(1<<BUTR);
}

void cofigureWaterLevel(void) {
    /// nastavimo refernco Vref=AVcc
    ADMUX |= (1<<REFS0);
    /// nastavimo prescaler na 128 in prizgemo ADC
    ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)|(1<<ADEN);
};

void configureReles(void) {
    /// nastavimo releje kot izhode
    DDRC |= (1<<REL1) | (1<<REL2) | (1<<REL3);
    /// nastavimo jih kot zaprto, da ne porabljajo energije
    releSet(REL1);
    releSet(REL2);
    releSet(REL3);
}

void configureOLED(void) {
    /// pozenemo OLED
    OLED_Init();
}
