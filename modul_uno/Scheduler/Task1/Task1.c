#include "Task1.h"

#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"
#include "lcd.h"
#include <stdio.h>


void Task1_LCD(void)
{
    lcd_set_cursor(0,0);
    lcd_print("                ");
    lcd_set_cursor(0,1);
    lcd_print("                ");

    if (status == 0) {
        lcd_set_cursor(0,0);
        lcd_print("Za zac prit 2");
    } else if (status == 1) {
        lcd_set_cursor(0,0);
        lcd_print("Za level 1 ->1");
        lcd_set_cursor(0,1);
        lcd_print("Za nad. ->2");
    } else if (status == 2) {
        lcd_set_cursor(0,0);
        lcd_print("Za level 2 ->1");
        lcd_set_cursor(0,1);
        lcd_print("Za nad. ->2");
    } else if (status == 3) {
        lcd_set_cursor(0,0);
        lcd_print("Za level 3 ->1");
        lcd_set_cursor(0,1);
        lcd_print("Za nad. ->2");
    } else if (status == 4) {
        lcd_set_cursor(0,0);
        lcd_print("                ");
        lcd_set_cursor(0,0);
        lcd_print("Polnjenje...");
    } else if (status == 5) {
        lcd_set_cursor(0,0);
        lcd_print("Izliv tekocine!!");
    } else {
        lcd_set_cursor(0,0);
        lcd_print("NAPAKA!");
    }
}
