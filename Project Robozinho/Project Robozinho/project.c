/******************************************************************************
            PROGRAMA��O EM XC8 - MICROCONTROLADOR MICROCHIP PIC18F4620
                SERVI�O NACIONAL DE APRENDIZAGEM INDUSTRIAL - SENAI BRAGAN�A PAULISTA
PROFESSOR: WERLEY GODINHO
ALUNO: GABRIEL ESTEVAM DA COSTA E TAIN� VALENTIM DE LIMA
DATA: 12/08/2022
 *************************************************************************************************************************/


/*************************************************************************************************************************
                                DESCRI��O DO PROJETO

ESTE SOFTWARE EST� PREPARADO PARA CONTROLAR DOIS SERVOS MOTORES E EXIBIR A POSI��O X E Y EM UM DISPLAY LCD
 *************************************************************************************************************************/
// INCLUS�O DOS ARQUIVOS HEADER DE CONFIGURA��ES, DEFINI��ES, PROT�TIPOS, GLOBAIS, LCD E FUN��ES:
#include "../Bibliotecas/configuracao.h"
#include "definicoes.h"
#include "prototipos.h"
#include "globais.h"
#include "../Bibliotecas/LCD.h"
#include "funcoes.h"
/************************************************************************************************************************/

// FUN��O PRINCIPAL:

void main(void) {
    // INICIALIZA��O DO SISTEMA:
        inicializacao();
        
    // LOOP DO SISTEMA:
    while(1){
        if(!ON_OFF) ligarDesligar(onOff);
        if(onOff){
            // INICIALIZA��O DO LCD:
            InicializarLCD();
            LimparLCD();
            
            // BOAS-VINDAS DO SISTEMA
            PosicionarCursor(1,1);
            EscreverLCD("*****  SENAI  *****");
            PosicionarCursor(2,2);
            EscreverLCD("BRAGANCA PAULISTA");
            PosicionarCursor(3,1);
            EscreverLCD("PROJETO DE ROBOTICA");
            PosicionarCursor(4,3);
            EscreverLCD("GABRIEL E TAINA");
            delay(5000);
            LimparLCD();
        }
        while(onOff){
            // VERIFICA��ES CONSTANTES DE LIGA / DESLIGA E ERRO
            if(!ON_OFF) ligarDesligar(onOff);
            if (error) erro();
            
            // VERIFICA SE NENHUMA TECLA EST� SENDO PRESSIONADA PARA MOSTRAR A TELA INICIAL E ATUALIZAR OS VALORES DOS �NGULOS
            if(MAIS1 && MENOS1 && MAIS2 && MENOS2){
                telaInicial();
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOT�O SERVO 2 + EST� SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MAIS2){
                angulo2 = alteraAngulo(angulo2, 1);
                moveServos(2, angulo2);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOT�O SERVO 2 - EST� SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MENOS2){
                angulo2 = alteraAngulo(angulo2, 0);
                moveServos(2, angulo2);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOT�O SERVO 1 + EST� SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MAIS1){
                angulo1 = alteraAngulo(angulo1, 1);
                moveServos(1, angulo1);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOT�O SERVO 1 - EST� SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MENOS1){
                angulo1 = alteraAngulo(angulo1, 0);
                moveServos(1, angulo1);
                alterarValores(angulo1, angulo2);
            }
        }
    }
}
