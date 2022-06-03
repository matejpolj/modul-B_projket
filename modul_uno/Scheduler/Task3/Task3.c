#include "Task3.h"

#include "utils.h"
#include "ledNbutton.h"
#include "globals.h"

void Task3_Rele(void)
{
    /// v stanju polnjenja nastavimo ustrezne rele
    if (status == 4) {

        if (statusFill == 0) {
            releClr(REL1);
            releSet(REL2);
            releSet(REL3);
        } else if (statusFill == 1) {
            releSet(REL1);
            releClr(REL2);
            releSet(REL3);
        } else if (statusFill == 2) {
            releSet(REL1);
            releSet(REL2);
            releClr(REL3);
        } else {
            releSet(REL1);
            releSet(REL2);
            releSet(REL3);
        }
    } else  {
        releSet(REL1);
        releSet(REL2);
        releSet(REL3);
    }
}
