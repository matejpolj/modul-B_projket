#include "Task5.h"

#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"

/// statusne spremenljivke
uint8_t status = 0;
uint8_t statusFill = 0;
uint8_t level;
uint8_t sumlevel;

/// parametri polnjenja posameznih relejev
uint8_t lv1 = 0;
uint8_t lv2 = 0;
uint8_t lv3 = 0;

uint16_t time = 0;
uint8_t k = 75; /// koeficient časa glede na tick speed (skupaj traja 90 s polnjenje

void Task5_statusMaker(void)
{
    if ((status == 0)&&(flag == 1)) {
        /// prestavimo na naslednji status
        if (but & (1<<BUTR)) {
            status ++;
            flag = 0;
            sumlevel = 0;
        }
    } else if ((status == 1)&&(flag == 1)) {
        /// povečamo level
        if (but & (1<<BUTL)) {
            if (level < 100) level += 10;
            flag = 0;
        }

        if (but & (1<<BUTR)) {
            /// nastavimo vse statusne spremenljivke pred premikom
            status ++;
            lv1 = level/10;
            sumlevel = level;
            level = 0;
            flag = 0;
        }
    } else if ((status == 2)&&(flag == 1)) {
        if (but & (1<<BUTL)) {
            /// povačamo level do skupnega levela max 100
            if ((sumlevel + level) < 100) {
                level += 10;
            }
            flag = 0;
        }

        if (but & (1<<BUTR)) {
            /// nastavimo vse statusne spremenljivke pred premikom
            status++;
            sumlevel += level;
            lv2 = level/10;
            level = 0;
            flag = 0;
        }
    } else if ((status == 3)&&(flag == 1)) {
        /// enako kot pri 2
        if (but & (1<<BUTL)) {
            if ((sumlevel + level + 10) < 101) {
                level += 10;
            }
            flag = 0;
        }

        if (but & (1<<BUTR)) {
            status++;
            if (lv1 == 0) statusFill++;
            sumlevel += level;
            lv3 = level/10;
            level = 0;
            flag = 0;
        }
        //flag = 0;
    } else if (status == 4) {
        /// stanje polnjenja
        /// za vsak rele posebej polnimo zadevo in preverjamo, ce pretece dovolj casa
        if (statusFill == 0) {
            if (time >= (k*lv1)) {
                statusFill++;
                if (lv2 == 0) statusFill++;
                if (lv3 == 0) statusFill++;
                time = 0;
            }
        } else if (statusFill == 1) {
            if (time >= (k*lv2)) {
                statusFill++;
                if (lv3 == 0) statusFill++;
                time = 0;
            }
        } else if (statusFill == 2) {
            if (time >= (k*lv3)) {
                statusFill++;
                time = 0;
            }
        } else {
            /// pobrisemo parametre in resetiramo stanje
            statusFill = 0;
            status = 0;
            time = 0;
        }
        time++;
    }

    /// varovalo
    if (adc_level > 150) {
        status = 5;
    }
}

