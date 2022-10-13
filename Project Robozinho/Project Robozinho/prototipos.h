/* 
 * File:   prototipos.h
 * Author: tatah
 *
 * Created on 8 de Julho de 2022, 11:13
 */

#ifndef PROTOTIPOS_H
#define	PROTOTIPOS_H

//FUNÇÕES DO LCD
void delay(unsigned int tempo);
void Pulso(void);
void EnviarComandoLCD(unsigned char comando);
void PosicionarCursor(unsigned char linha, unsigned char coluna);
void EscreverCaracter(unsigned char texto);
void EscreverLCD(const unsigned char *caracter);
void LimparLCD(void);
void InicializarLCD(void);
void InicializarCaracterLCD(void);
//FUNÇÕES DO PROGRAMA
void inicializacao();
void delayUs(unsigned int tempo);
void erro();
void ligarDesligar(int estado);
int alteraAngulo(int angulo, int operacao);
void alterarValores(int angulo1, int angulo2);
void moveServos(int servo, int angulo);
void telaInicial();


#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* PROTOTIPOS_H */

