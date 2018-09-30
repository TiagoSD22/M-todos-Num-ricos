#ifndef MATRIZES_H
#define MATRIZES_H

#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int Contar_chaves(const char* entrada);

int Numero(const char entrada);

int Contar_numeros(const char *entrada);

double* Guardar_numeros(const char* entrada);

int IsQuadrada(const char* matrix);

void Calcular_ordem(const char* matrix, int &linhas, int &colunas);

char* Gerar_representacao_matricial(const char *entrada);

int Determinante(int i,int j,double** matrix);

double* Cramer(int i, int j, double** matrix, double* vetor_independente, int &erro);

double* Solucionar_triangular_superior(int i, double** matrix, double* vetor_independente);

double* Solucionar_triangular_inferior(int i, double **matrix, double *vetor_independente);

double* Gauss(int i, int j, double** matrix, double* vetor_independente);

void Copiar_matrix(int i, int j, double** entrada,double** &saida);

bool Precisa_pivotar(int i, double** matrix, int i_atual, int j_atual);

double Encontrar_maior(int i, double** matrix, int i_atual, int j_atual, double &maior, int &linha_do_maior);

void Gerar_identidade(int i, int j, double** matrix);

void Transformar_triangular_superior(int i, int j, double** matrix);

void Trocar_linha(int i, int j, double** matrix, int linha1, int linha2);

int Determinante_triangular(int i, int j, double** matrix);

double* Gauss_com_pivoteamento(int i, int j, double** matrix, double* vetor_independente);

double* Gauss_jordan(int n, double** matrix, double* vetor);

void Inversa(int i, int j, double** matrix, double** &inversa);

void Transposta(int i, int j, double** matrix, double** &trasposta);

void Gerar_LU(int i, int j, double**matrix, double** L, double** U);

double* Gauss_Jacob(int i, int j, double** matrix, double* vetor, double* chute0,int max_it, double precisao);

void Gerar_LU_Doolittle(int n, double**  matriz, double** &L, double** &U);

double* Solucionar_Doolittle(int n, double** matriz, double* vetor_independente);

#endif // MATRIZES_H
