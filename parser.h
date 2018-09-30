#ifndef PARSER_H
#define PARSER_H

#include<string.h>
#include<cmath>
#include<ctype.h>
#include<stdlib.h>

#define MY_PHI 1.61803398874989484820458683436563811
#define MY_L 0.1100010000000000000000010

double Soma(double x,double y);

double Sub(double x,double y);

double Mult(double x,double y);

double Div(double x,double y);

double Log(double x,double y);

double Raiz_n(double num, double n_);

double Char2double(const char* entrada) ;

int IsNumero(char entrada);

int IsOperador(char entrada);

int IsLiteral(char entrada);

int IsDelimitador(char entrada);

void Identificar_literais(const char *entrada, int &qt_lit);

void Identificar_todos_numeros(const char* entrada,double* &saida,int &qt_num);

void Identificar_numero(const char *entrada, double &saida);

void Identificar_todos_operadores(const char* entrada,char* &saida,int &qt_op);

void Identificar_operador(const char* entrada,int* &op);

int Identificar_op(char entrada);

double Operar(double x, int op, double y);

void Contar_delimitadores(const char* entrada, int &qt_del);

void Identificar_ordem(const char *entrada, int* &saida);

void Identificar_ordem_redundante(const char* entrada,int* saida);

void Calcular_tamanho_real(const char* entrada, int &tamanho);

int Funcao_Simples(const char* entrada);

int Apresenta_restricao(const char* entrada);

void Copiar_string(char *saida, const char* entrada, int inicio, int fim);

void Trocar_sinais(char* entrada);

bool Sintaxe_correta(const char* entrada, char* &m_erro);

double Parser(const char *entrada, double x);

double Fun(const char* entrada,double x);

double Derivar(const char* funcao, double x);

#endif // PARSER_H
