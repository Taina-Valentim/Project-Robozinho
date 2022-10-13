/* 
 * File:   definicoes.h
 * Author: tatah
 *
 * Created on 8 de Julho de 2022, 11:11
 */

#ifndef DEFINICOES_H
#define	DEFINICOES_H

// DEFINI��O DAS ENTRADAS DO PROGRAMA:
#define MAIS1 PORTBbits.RB0
#define MENOS1 PORTBbits.RB1
#define MAIS2 PORTBbits.RB2
#define MENOS2 PORTBbits.RB3
#define ON_OFF PORTBbits.RB4
/************************************************************************************************************************/
// DEFINI��O DAS SA�DAS DO PROGRAMA:
#define displayLCD PORTD
#define RS PORTEbits.RE0
#define EN PORTEbits.RE2
#define escrever 0
#define SERVO1 PORTCbits.RC0
#define SERVO2 PORTCbits.RC1
#define LIGA PORTCbits.RC2

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* DEFINICOES_H */

