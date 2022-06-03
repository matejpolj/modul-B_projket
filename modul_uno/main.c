/**
    /mnt/a4b5d085-eea2-4a2e-847d-8e6738b9fd2c/arduino-1.8.13/hardware/tools/avr/bin/avrdude -C/mnt/a4b5d085-eea2-4a2e-847d-8e6738b9fd2c/arduino-1.8.13/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:/tmp/arduino_build_907704/Blink.ino.hex:i
**/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "OS/OS.h"
#include "Task0/Task0.h"
#include "Task1/Task1.h"
#include "Task2/Task2.h"
#include "Task3/Task3.h"
#include "Task4/Task4.h"
#include "Task5/Task5.h"
#include "utils.h"
#include "globals.h"

/* Timer interrupt. The OS_TaskTimer() shall be here. */
ISR (TIMER1_OVF_vect)
{
    TCNT1 = 65223; /// 20 ms
    OS_TaskTimer();
}

/* Main function. */
int16_t main(void)
{
    /// nastavimo vse periferne enote
    configureLEDs();
    configureLCD();
    coifigureButtons();
    cofigureWaterLevel();
    configureReles();
    configureOLED();

    TCNT1 = 65223;   /// 20 ms

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  /// casovnik s 1024 prescalerjem
	TIMSK1 = (1 << TOIE1) ;   /// omogoci timer1 overflow interrupt(TOIE1)
	sei();        /// omogoci globalne interpte

    /// nastavimo vse taske
    OS_TaskCreate(&Task0_LED_n_BUT, 1, BLOCKED);
    OS_TaskCreate(&Task1_LCD, 6, BLOCKED);
    OS_TaskCreate(&Task2_OLED, 6, BLOCKED);
    OS_TaskCreate(&Task3_Rele, 6, BLOCKED);
    OS_TaskCreate(&Task4_adc, 6, BLOCKED);
    OS_TaskCreate(&Task5_statusMaker, 6, BLOCKED);

    /* The infinte loop, only the OS_TaskExecution() function shall be here. */
    while (1)
    {
        OS_TaskExecution();
    }
    return 0;
}

