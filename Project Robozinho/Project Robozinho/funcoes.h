/* 
 * File:   funcoes.h
 * Author: tatah
 *
 * Created on 8 de Julho de 2022, 11:13
 */

#ifndef FUNCOES_H
#define	FUNCOES_H

//FUNÇÕES DO PROGRAMA:

// FUNÇÃO DE INICIALIZAÇÃO DO SISTEMA:
void inicializacao(){
    // LIMPA PORT's:
    PORTA = 0X00;
    PORTB = 0X00;
    PORTC = 0X00;
    PORTD = 0X00;
    PORTE = 0X00;

    LATA = 0X00;
    LATB = 0X00;
    LATC = 0X00;
    LATD = 0X00;
    LATE = 0X00;

    // CONFIGURAÇÃO DE I/O DOS PINOS DE CADA PORT's:
    TRISA = 0X00;
    TRISB = 0XFF;
    TRISC = 0X00;
    TRISD = 0X00;
    TRISE = 0X00;
    
    //CONFIGURAÇÃO DOS PULL-UPS INTERNOS:
    INTCON2bits.NOT_RBPU = 0;   // 1 - DESABIITA OS PULL-UPS DO PORTB
                                // 0 - HABILITA OS PULL-UPS DO PORTB

    //CONFIGURAÇÃO DO A/D:
    ADCON0 = 0B00000001;
    ADCON1 = 0B00001111;
    ADCON2 = 0B10110001;
}

// FUNÇÃO DE DELAY DE MICROSSEGUNDOS:
void delayUs(unsigned int tempo){
    while(tempo--)__delay_us(1);
}

// TABELA DE CÓDIGOS DE ERRO:
/*          
            1000 -> ERRO NA FUNÇÃO DE LIGAR / DESLIGAR                      (ESTADO INVÁLIDO)
            1001 -> ERRO NA FUNÇÃO DE SOMAR ANGULO                          (ÂNGULO INVÁLIDO)
            1010 -> ERRO NA FUNÇÃO DE SUBTRAIR ANGULO                       (ÂNGULO INVÁLIDO)
            1011 -> ERRO NA FUNÇÃO DE ALTERAR VALORES DO SERVO 1            (ÂNGULO INVÁLIDO)
            1100 -> ERRO NA FUNÇÃO DE ALTERAR VALORES DO SERVO 2            (ÂNGULO INVÁLIDO)
            1101 -> ERRO NA FUNÇÃO DE MOVER SERVO                           (ÂNGULO INVÁLIDO)
            1110 -> ERRO NAO IDENTIFICADO
*/

// FUNÇÃO DE ERRO:
void erro(){
    LimparLCD();
    PosicionarCursor(1,1);
    EscreverLCD("****** ERRO! ******");
    PosicionarCursor(2,1);
    EscreverLCD("  REINICIE AGORA");
    PosicionarCursor(4,1);
    EscreverLCD("COD DO ERRO:");
    PosicionarCursor(4,14);
    switch(codErro){
        case 1000:
            EscreverLCD("1000");
            break;
        case 1001:
            EscreverLCD("1001");
            break;
        case 1010:
            EscreverLCD("1010");
            break;
        case 1011:
            EscreverLCD("1011");
            break;
        case 1100:
            EscreverLCD("1100");
            break;
        case 1101:
            EscreverLCD("1101");
            break;
        case 1110:
            EscreverLCD("1110");
            break;
        case 1111:
            EscreverLCD("1111");
            break;
        default:
            EscreverLCD("* erro *");
            break;
    }
    while(1){
        if(!ON_OFF) break;
    }
        
}

// FUNÇÃO DE LIGAR / DESLIGAR:
void ligarDesligar(int estado){
    switch(estado){
        case 0:
            onOff = 1;
            LIGA = 1;
            break;
        case 1:
            onOff = 0;
            LimparLCD();
            displayLCD = 0;
            LIGA = 0;
            delay(5000);
            break;
        default:
            error = 1;
            codErro = 1000;
            break;
    }
}

// FUNÇÃO DE ALTERAR ÂNGUL0S:
int alteraAngulo(int angulo, int operacao){
    if(operacao){
        switch(angulo){
            case 60:
                break;
            case 0:
                angulo = 60;
                break;
            case -60:
                angulo = 0;
                break;
            default:
                error = 1;
                codErro = 1001;
                break;
        }
    }
    else{
        switch(angulo){
            case -60:
                break;
            case 0:
                angulo = -60;
                break;
            case 60:
                angulo = 0;
                break;
            default:
                error = 1;
                codErro = 1010;
                break;
        }
    }
    return angulo;
}

// FUNÇÃO DE ALTERAR VALORES NO LCD:
void alterarValores(int angulo1, int angulo2){
    switch(angulo1){
        case 60:
            PosicionarCursor(3,11);
            EscreverLCD(" 60");
            break;
        case -60:
            PosicionarCursor(3,12);
            EscreverLCD("-60");
            break;
        case 0:
            PosicionarCursor(3,11);
            EscreverLCD(" 0  ");
            break;
        default:
            if((angulo1 != 0 && angulo1 != 60 && angulo1 != -60) || (angulo2 != 0 && angulo2 != 60 && angulo2 != -60)){
                error = 1;
                codErro = 1011;
            }
            break;
    }

    switch(angulo2){
        case 60:
            PosicionarCursor(2,12);
            EscreverLCD(" 60 Graus");

            PosicionarCursor(4,11);
            EscreverLCD(" 60");
            break;
        case -60:
            PosicionarCursor(2,12);
            EscreverLCD("-60 Graus");

            PosicionarCursor(4,11);
            EscreverLCD(" -60");
            break;
        case 0:
            PosicionarCursor(2,12);
            EscreverLCD(" 0  Graus");

            PosicionarCursor(4,11);
            EscreverLCD(" 0  ");
        default:
            if((angulo1 != 0 && angulo1 != 60 && angulo1 != -60) || (angulo2 != 0 && angulo2 != 60 && angulo2 != -60)){
                error = 1;
                codErro = 1100;
            }
            break;
    }
}

// FUNÇÃO DE MOVER SERVOS:
void moveServos(int servo, int angulo){
    switch(angulo){
        case 0:
            if(servo == 1){
                SERVO1 = 1;
                delayUs(543);
                SERVO1 = 0;
            }
            if(servo == 2){
                SERVO2 = 1;
                 delayUs(543);
                SERVO2 = 0;
            }
            break;
        case 60:
            if(servo == 1){
                SERVO1 = 1;
                delayUs(665);
                SERVO1 = 0;
            }
            if(servo == 2){
                SERVO2 = 1;
                delayUs(665);
                SERVO2 = 0;
            }
            break;
        case -60:
            if(servo == 1){
                SERVO1 = 1;
                delayUs(422);
                SERVO1 = 0;
            }
            if(servo == 2){
                SERVO2 = 1;
                delayUs(422);
                SERVO2 = 0;
            }
            break;
        default:
            error = 1;
            codErro = 1101;
            break;
    }
}

// FUNÇÃO DE TELA INICIAL:
void telaInicial(){
    PosicionarCursor(1,1);
    EscreverLCD("*****   ROBO   *****");
    PosicionarCursor(2,1);
    EscreverLCD("INCLINACAO:");
    PosicionarCursor(3,1);
    EscreverLCD("POSICAO X:");
    PosicionarCursor(4,1);
    EscreverLCD("POSICAO Y:");
}



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FUNCOES_H */

