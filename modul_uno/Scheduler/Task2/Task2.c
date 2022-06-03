#include "Task2.h"

#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"
#include "SSD1306.h"

void Task2_OLED(void)
{
    /// pobrisi oled
    if (status == 0) {
        OLED_Clear();
    } else if (status < 4) {
        /// prikazi grafe s stanji polnjenja
        OLED_VerticalGraph(status - 1, level);
        OLED_VerticalGraph(3, sumlevel);
    }

}
