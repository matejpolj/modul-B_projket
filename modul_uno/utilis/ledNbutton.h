#ifndef LEDNBUTTON_H_INCLUDED
#define LEDNBUTTON_H_INCLUDED

void ledSet(int led_p);

void ledClr(int led_p);

void ledTog(int led_p);

int getButtonSta(int btn_p);

int getButtonPrs(int btn_p);

int adc_read(void);

void releClr(int rele_p);

void releSet(int rele_p);

#endif // LEDNBUTTON_H_INCLUDED
