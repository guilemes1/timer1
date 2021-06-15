/*
 * File:   delay.c
 * Author: 20185189
 *
 * Created on 3 de Fevereiro de 2021, 17:46
 */

#include <xc.h>
#include "delay.h"

void delay (unsigned int t)
{
    while( t )
    {
        --t;
        __delay_ms(1);
    }
}
