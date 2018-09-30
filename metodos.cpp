#include<cmath>
#include"metodos.h"
#include"parser.h"
#include<stdio.h>

double Bissecao(const char* entrada,double a, double b, double precisao, double precisao2, int max_it, int &it,int &erro,int opcao){
    double x,Fx,Fa,Fb;
    int k = 0;
    FILE* relatorio = fopen("Relatorio.txt","a");
    if(fabs(Fun(entrada,a)) < precisao2 || fabs(Fun(entrada,b)) < precisao2){
        if(fabs(Fun(entrada,a)) < precisao2){
            return a;
        }
        else{
            return b;
        }
    }
    else{
        if(Fun(entrada,a) * Fun(entrada,b) < 0){
            if(opcao == 1){
                fprintf(relatorio,"Método da Bisseção:\n\nEquação: %s a = %f b = %f Epsilon 1 =  %f Epsilon2 = %f\n\n",entrada,a,b,precisao,precisao2);
            }
            erro = 0;
            do{
                Fa = Fun(entrada,a);
                Fb = Fun(entrada,b);
                x = (a+b)/2;
                Fx = Fun(entrada,x);
                if(Fa * Fx < 0){
                    b = x;
                }
                else if(Fx * Fb < 0){
                    a = x;
                }
                if(opcao == 1){
                    fprintf(relatorio,"A raiz na iteracao %d: %.13f, para a= %.13f,b = %.13f,Fx = %.13f e |b - a| = %.13f\n",k,x,a,b,Fx,fabs(b-a));
                }
                k++;
            }while(fabs(b-a) >= precisao && fabs(Fx) >= precisao2 && k < max_it);
        }
        else{
            erro = 1;
        }
    }
    if(opcao == 1){
        fprintf(relatorio,"Após %d iterações eu cheguei a seguinte raíz: %.20f\n\n",k,x);
        fprintf(relatorio,"*************************************************************************************************************************************\n\n");
    }
    fclose(relatorio);
    it = k;
    return x;
}

double Posicao_Falsa(const char* entrada, double a, double b, double precisao, double precisao2, int max_it, int &it, int &erro, int opcao){
    double x,Fx,Fa,Fb;
    int k = 0;
    FILE* relatorio = fopen("Relatorio.txt","a");
    if(fabs(Fun(entrada,a)) < precisao || fabs(Fun(entrada,b)) < precisao){
        if(fabs(Fun(entrada,a)) < precisao){
            return a;
        }
        else{
            return b;
        }
    }
    else{
        if(Fun(entrada,a) * Fun(entrada,b) < 0){
            if(opcao == 1){
                fprintf(relatorio,"Método da Posição Falsa:\n\nEquação: %s a = %f b = %f Epsilon 1 = %f Epsilon 2 = %f\n\n",entrada,a,b,precisao,precisao2);
            }
            erro = 0;
            do{
                Fa = Fun(entrada,a);
                Fb = Fun(entrada,b);
                x = (a*Fb - b*Fa)/(Fb - Fa);
                Fx = Fun(entrada,x);
                if(Fa * Fx < 0){
                    b = x;
                }
                else if(Fx * Fb < 0){
                    a = x;
                }
                if(opcao == 1){
                    fprintf(relatorio,"A raiz na iteracao %d: %.13f, para a= %.13f,b = %.13f,Fx = %.13f e |b - a| = %.13f\n",k,x,a,b,Fx,fabs(b-a));
                }
                k++;
            }while(fabs(b-a) >= precisao && fabs(Fx) >= precisao2 && k < max_it);
        }
        else{
            erro = 1;
        }
    }
    if(opcao == 1){
        fprintf(relatorio,"Após %d iterações eu cheguei a seguinte raíz: %.20f\n\n",k,x);
        fprintf(relatorio,"*************************************************************************************************************************************\n\n");
    }
    fclose(relatorio);
    it = k;
    return x;
}

double Newton_Raphson(const char* funcao, double x0, double precisao, double precisao2, int max_it, int &it, int &opcao, double p){
    int k = 0;
    double x1,Fx,aux;
    FILE* relatorio = fopen("Relatorio.txt","a");
    if(fabs(Fun(funcao,x0)) < precisao){
        if(opcao == 1){
            fprintf(relatorio,"Metodo de Newton-Raphson: \n\nEquação: %s x0 = %f Epsilon 1 = %f Epsilon 2 = %f Multiplicidade = %f\n\n",funcao,x0,precisao,precisao2,p);
            fprintf(relatorio,"Raiz: %f\n\n",x0);
        }
        return x0;
    }
    else{
        if(opcao == 1){
            fprintf(relatorio,"Metodo de Newton-Raphson: \n\nEquação: %s x0 = %f Epsilon 1 = %f Epsilon 2 = %f Multiplicidade = %f\n\n",funcao,x0,precisao,precisao2,p);
            fprintf(relatorio,"A raiz na iteracao %d: %.13f, para Fx = %.13f\n",k,x0,Fun(funcao,x0));
        }
        do{
            aux = x0;
            x1 = x0 - (p*Fun(funcao,x0)/Derivar(funcao,x0));
            Fx = Fun(funcao,x1);
            x0 = x1;
            k++;
            if(opcao == 1){
                fprintf(relatorio,"A raiz na iteracao %d: %.13f, para Fx = %.13f e |x%d - x%d| = %.13f\n",k,x1,Fx,k,k-1,fabs(x1-aux));
            }
        }while(fabs(x1 - aux) >= precisao && fabs(Fx) >= precisao2 && k < max_it);
        if(opcao == 1){
            fprintf(relatorio,"Após %d iterações eu cheguei a seguinte raíz: %.20f\n\n",k+1,x1);
            fprintf(relatorio,"*************************************************************************************************************************************\n\n");
        }
    }
    fclose(relatorio);
    it = k;
    return x1;
}

double Secante(const char *funcao, double x0, double x1, double precisao, double precisao2, int max_it, int &it, int &opcao, double p){
    int k = 0;
    double x2,Fx,aux;
    FILE* relatorio = fopen("Relatorio.txt","a");
    if(fabs(Fun(funcao,x0)) < precisao || fabs(Fun(funcao,x1)) < precisao){
        fprintf(relatorio,"Metodo da Secante: \n\nEquação: %s x0 = %f x1 = %f Epsilon 1 = %f Epsilon 2 = %f Multiplicidade = %f\n\n",funcao,x0,x1,precisao,precisao2,p);
        if(fabs(Fun(funcao,x0)) < precisao){
            fprintf(relatorio,"Raiz: %f\n\n",x0);
            return x0;
        }
        else{
            fprintf(relatorio,"Raiz: %f\n\n",x1);
            return x1;
        }
    }
    else{
        fprintf(relatorio,"Metodo da Secante: \n\nEquação: %s x0 = %f x1 = %f Epsilon 1 = %f Epsilon 2 = %f Multiplicidade = %f\n\n",funcao,x0,x1,precisao,precisao2,p);
        do{
            aux = x1;
            x2 = x1 - p*(Fun(funcao,x1)/(Fun(funcao,x1) - Fun(funcao,x0))) * (x1 - x0);
            Fx = Fun(funcao,x2);
            x0 = x1;
            x1 = x2;
            k++;
            if(opcao == 1){
                fprintf(relatorio,"A raiz na iteracao %d: %.13f, para Fx = %.13f e |x%d - x%d| = %.13f\n",k-1,x2,Fx,k,k-1,fabs(x2-aux));
            }
        }while(fabs(x2 - aux) >= precisao && fabs(Fx) >= precisao2 && k < max_it);
        if(opcao == 1){
            fprintf(relatorio,"Após %d iterações eu cheguei a seguinte raiz: %.20f\n\n",k,x2);
            fprintf(relatorio,"*************************************************************************************************************************************\n\n");
        }
    }
    fclose(relatorio);
    it = k;
    return x2;
}

double Ponto_Fixo(const char* funcao, double x0, double precisao, double precisao2, int max_it, int &it, int &erro, int &opcao){
    int k = 0;
    double x1,Fx,aux;
    FILE* relatorio = fopen("Relatorio.txt","a");
    if(fabs(Derivar(funcao,x0)) < 1){
        erro = 0;
        if(fabs(Fun(funcao,x0)) < precisao){
            if(opcao == 1){
                fprintf(relatorio,"Metodo do Ponto Fixo: \n\nEquação: %s x0 = %f Epsilon 1 = %f Epsilon 2 = %f\n\n",funcao,x0,precisao,precisao2);
                fprintf(relatorio,"Raiz: %f\n\n",x0);
            }
            return x0;
        }
        else{
            if(opcao == 1){
                fprintf(relatorio,"Metodo do Ponto Fixo: \n\nEquação: %s x0 = %f Epsilon 1 = %f Epsilon 2 = %f\n\n",funcao,x0,precisao,precisao2);
                fprintf(relatorio,"A raiz na iteracao %d: %.13f, para Fx = %.13f\n",k,x0,Fun(funcao,x0));
            }
            do{
                aux = x0;
                x1 = Fun(funcao,x0);
                Fx = Fun(funcao,x1);
                x0 = x1;
                k++;
                if(opcao == 1){
                    fprintf(relatorio,"A raiz na iteracao %d: %.13f, para Fx = %.13f e |x%d - x%d| = %.13f\n",k,x1,Fx,k,k-1,fabs(x1-aux));
                }
            }while(fabs(x1 - aux) >= precisao && fabs(Fx) >= precisao2 && k < max_it);
            if(opcao == 1){
                fprintf(relatorio,"Após %d iterações eu cheguei a seguinte raiz: %.20f\n\n",k+1,x1);
                fprintf(relatorio,"*************************************************************************************************************************************\n\n");
            }
        }
        fclose(relatorio);
        it = k;
        return x1;
    }
    else{
        erro = 1;
    }
}
