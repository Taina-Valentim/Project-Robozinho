/******************************************************************************
            PROGRAMAÇÃO EM XC8 - MICROCONTROLADOR MICROCHIP PIC18F4620
                SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL - SENAI BRAGANÇA PAULISTA
PROFESSOR: WERLEY GODINHO
ALUNO: GABRIEL ESTEVAM DA COSTA E TAINÁ VALENTIM DE LIMA
DATA: 12/08/2022
 *************************************************************************************************************************/


/*************************************************************************************************************************
                                DESCRIÇÃO DO PROJETO

ESTE SOFTWARE ESTÁ PREPARADO PARA CONTROLAR DOIS SERVOS MOTORES E EXIBIR A POSIÇÃO X E Y EM UM DISPLAY LCD
 *************************************************************************************************************************/
// INCLUSÃO DOS ARQUIVOS HEADER DE CONFIGURAÇÕES, DEFINIÇÕES, PROTÓTIPOS, GLOBAIS, LCD E FUNÇÕES:
#include "../Bibliotecas/configuracao.h"
#include "definicoes.h"
#include "prototipos.h"
#include "globais.h"
#include "../Bibliotecas/LCD.h"
#include "funcoes.h"
/************************************************************************************************************************/

// FUNÇÃO PRINCIPAL:

void main(void) {
    // INICIALIZAÇÃO DO SISTEMA:
        inicializacao();
        
    // LOOP DO SISTEMA:
    while(1){
        if(!ON_OFF) ligarDesligar(onOff);
        if(onOff){
            // INICIALIZAÇÃO DO LCD:
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
            // VERIFICAÇÕES CONSTANTES DE LIGA / DESLIGA E ERRO
            if(!ON_OFF) ligarDesligar(onOff);
            if (error) erro();
            
            // VERIFICA SE NENHUMA TECLA ESTÁ SENDO PRESSIONADA PARA MOSTRAR A TELA INICIAL E ATUALIZAR OS VALORES DOS ÂNGULOS
            if(MAIS1 && MENOS1 && MAIS2 && MENOS2){
                telaInicial();
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOTÃO SERVO 2 + ESTÁ SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MAIS2){
                angulo2 = alteraAngulo(angulo2, 1);
                moveServos(2, angulo2);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOTÃO SERVO 2 - ESTÁ SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MENOS2){
                angulo2 = alteraAngulo(angulo2, 0);
                moveServos(2, angulo2);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOTÃO SERVO 1 + ESTÁ SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MAIS1){
                angulo1 = alteraAngulo(angulo1, 1);
                moveServos(1, angulo1);
                alterarValores(angulo1, angulo2);
            }
            
            // VERIFICA SE O BOTÃO SERVO 1 - ESTÁ SENDO PRESSIONADO PARA MOVER O SERVO
            if (!MENOS1){
                angulo1 = alteraAngulo(angulo1, 0);
                moveServos(1, angulo1);
                alterarValores(angulo1, angulo2);
            }
        }
    }
}
