/*
 * File:   timers.c
 * Author: 20185189
 *
 * Created on 11 de Junho de 2021, 16:03
 * 
 * ciclo de máquina: 1us
 * 
 * estouro: TMR1 * preescaler * ciclo de máquina
 */


#include <xc.h>

unsigned int contador;
unsigned long tlseg;

void timer_init (void)
{
    INTCONbits.GIE = 0;    //Desliga disjuntor geral
    INTCONbits.PEIE = 1;   
    PIE1bits.TMR1IE = 1;   //ENEBLE T1
    
    // REGISTRADOR DE BLOCOS DO DIAGRAMA
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1SYNC = 0;
    T1CONbits.TMR1GE = 0;
    T1CONbits.TMR1ON = 1;   //Habilita o timer 1   
    
    TMR1L = 0xFF;
    TMR1H = 65280 - 100;
    
    contador = 0;
    tlseg = 10000;
    
    INTCONbits.GIE = 1;
}

void __interrupt() denilson(void)
{
    if( PIR1bits.TMR1IF )       //SE HOUVER O ESTOURO
    {
        PIR1bits.TMR1IF = 0;    //LIMPA A FLAG VIA SOFTWARE
        TMR1L = 0xFF;
        TMR1H = 65280 - 100;
        --tlseg;
        if(tlseg == 0)
        {
            tlseg = 10000;
            ++contador;
        }    
    }    
        
}