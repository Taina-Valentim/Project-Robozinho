/* 
 * File:   LCD.h
 * Author: tatah
 *
 * Created on 6 de Agosto de 2022, 23:17
 */

/*
    DEFINES PARA USAR ESSA BIBLIOTECA:
    
    #define displayLCD PORTD
    #define RS PORTEbits.RE0
    #define EN PORTEbits.RE2
    #define escrever 0

*/

#ifndef LCD_H
#define	LCD_H

// FUN플O DELAY:
void delay(unsigned int tempo){
    while(tempo--)__delay_ms(1);
}

// FUN플O PULSO:
void Pulso(void){
    EN = 1;
    delay(10);
    EN = 0;
    delay(10);
    
}

// FUN플O DE ENVIAR COMANDO PARA O LCD:
void EnviarComandoLCD(unsigned char comando){
    RS = escrever;
    displayLCD = comando;
    Pulso();
}

// FUN플O DE POSICIONAR O CURSOR NO LCD:
void PosicionarCursor(unsigned char linha, unsigned char coluna){
    unsigned char posicao = 0;
    
    switch(linha){
        case 1: posicao = 0X80;
        break;
        
        case 2: posicao = 0XC0;
        break;
        
        case 3: posicao = 0X94;
        break;
        
        case 4: posicao = 0XD4;
        break;
        
        default: break;
    }
    posicao += (coluna - 1);
    
    EnviarComandoLCD(posicao);
}

// FUN플O DE ESCEVER CARACTERE NO LCD:
void EscreverCaracter(unsigned char texto){
    RS = 1;
    displayLCD = texto;
    delay(10);;
    Pulso();
}

// FUN플O DE ESCEVER NO LCD:
void EscreverLCD(const unsigned char *caracter){
    if(onOff){
        for(unsigned int i = 0; caracter[i] != '\0'; i++){
            EscreverCaracter(caracter[i]);
            delay(10);;
        }
    } 
}

// FUN플O DE LIMPAR O LCD:
void LimparLCD(void){
    EnviarComandoLCD(0X01);
}

// FUN플O DE INICIALIZAR LCD:
void InicializarLCD(void){
    delay(10);;
    unsigned char comando[5] = {0X38, 0X0C, 0X06, 0X01};
    
    for(unsigned char i = 0; i < 5 ; i++){
        delay(10);;
        EnviarComandoLCD(comando[i]);
    }

}



#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

