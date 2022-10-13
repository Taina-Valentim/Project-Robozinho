/* 
 * File:   configuracao.h
 * Author: ALUNO
 *
 * Created on 3 de Junho de 2022, 13:28
 */

#ifndef CONFIGURACAO_H
#define	CONFIGURACAO_H
// INCLUSÃO DO ARQUIVO HEADER COM AS FUNÇÕES PADRÕES DO COMPILADOR MPLAB XC8:
#include <xc.h>
/************************************************************************************************************************/
// DEFINIÇÃO DA FREQUÊNCIA DE CLOCK UTILIZADA:
#define _XTAL_FREQ 20000000
/************************************************************************************************************************/
// CONFIGURAÇÕES PARA GRAVAÇÃO
#pragma config WDT = OFF
#pragma config WDTPS = 512
#pragma config OSC = HSPLL
#pragma config LVP = ON
#pragma config PWRT = ON
#pragma config BORV = 0
#pragma config DEBUG = ON 

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONFIGURACAO_H */

