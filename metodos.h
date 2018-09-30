#ifndef BISSECAO_H
#define BISSECAO_H

double Bissecao(const char* entrada, double a, double b, double precisao, double precisao2, int max_it, int &it, int &erro, int opcao);
double Posicao_Falsa(const char *entrada, double a, double b, double precisao, double precisao2, int max_it, int &it, int &erro, int opcao);
double Newton_Raphson(const char* funcao, double x0, double precisao, double precisao2, int max_it, int &it, int &opcao, double p);
double Secante(const char* funcao, double x0, double x1, double precisao, double precisao2, int max_it,int &it,int &opcao, double p);
double Ponto_Fixo(const char* funcao, double x0, double precisao, double precisao2, int max_it,int &it,int &erro,int &opcao);

#endif // BISSECAO_H
