#include "Task0.h"
#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"
#include "config.h"

uint8_t but;
uint8_t flag;

void Task0_LED_n_BUT(void)
{
    /// pridobi pritisk tipk
    but = getButtonPrs(BUTR);
    but |= (getButtonPrs(BUTL) << 1);
    flag = 1;

    /// pobrišemo ledice
    ledClr(LEDR);
    ledClr(LEDB);
    ledClr(LEDG);
    ledTog(LEDsys);

    if (status == 0) {
        ledSet(LEDG); /// stanje pripravljenosti
    } else if (status < 4) {
        ledSet(LEDB); /// priprava na polnjenje
    } else if (status == 4) {
        ledSet(LEDG); /// polnjenje
    } else {
        ledSet(LEDR); /// napaka
    }

}
