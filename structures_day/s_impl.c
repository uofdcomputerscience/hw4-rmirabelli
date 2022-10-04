#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s_impl.h"

void printWavePoint(WavePoint *wp) {
    printf("f %d, a %f s %d\n", wp->frequency.iValue, wp->amplitude.fValue, wp->shape);
    wp->frequency.iValue = 99;
}

