#include "Task4.h"

#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"

uint16_t adc_level;

void Task4_adc(void)
{
    adc_level = adc_read(); /// samo preberemo adc, že to dovolj traja
}
