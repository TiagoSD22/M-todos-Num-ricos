#include<string.h>
#include<cmath>
#include<ctype.h>
#include<stdlib.h>
#include"parser.h"

#define MY_PHI 1.61803398874989484820458683436563811
#define MY_L 0.1100010000000000000000010

double Soma(double x,double y){return x + y;}

double Sub(double x,double y){return x - y;}

double Mult(double x,double y){return x * y;}

double Div(double x,double y){return x/y;}

double Log(double x,double y){ return log(x)/log(y);}

double Raiz_n(double x, double y){
    double r;
    double A(x);
    double dx;
    double eps(10e-6);
    double n(y);
    r = A * 0.5;
    dx = (A/pow(r,n-1)-r)/n;
    while(dx >= eps || dx <= -eps){
        r = r + dx;
        dx = (A/pow(r,n-1)-r)/n;
    }
   return r;
}

double Char2double(const char *entrada) {
    double saida = 0;
    int n_digit = 0;
    int decimal = 0;
    while(*entrada != '\0') {
        if(*entrada == '.'){
            decimal++;
            entrada++;
            n_digit++;
        }
        if(decimal == 0){
            saida = saida*10 +(*entrada - '0');
            entrada++;
        }
        else{
            saida = saida + ((*entrada - '0')/pow(10,n_digit));
            entrada++;
            n_digit++;
        }
    }
    return saida;
}

int IsNumero(char entrada){
    if(isdigit(entrada) || entrada == '.' || entrada == 'e' || entrada == 'P' || entrada == 'F' || entrada == 'L'){
        return 1;
    }
    else{
        return 0;
    }
}

int IsOperador(char entrada){
    char op[8] = {'+','-','*','/','^','@','#','$'};
    int i = 0;
    for(i = 0; i < 8; i++){
        if(entrada == op[i]){
            return 1;
        }
    }
    return 0;
}

int IsLiteral(char entrada){
    if(isalpha(entrada) && entrada != 'e' && entrada != 'P' && entrada != 'F' && entrada != 'L'){
        return 1;
    }
    else{
        return 0;
    }
}

int IsDelimitador(char entrada){
    if(entrada == '(' || entrada == ')'){
        return 1;
    }
    else{
        return 0;
    }
}

void Identificar_literais(const char* entrada,int &qt_lit){
    int i = 0,j = 0;
    while(entrada[i] != '\0'){
        if(IsLiteral(entrada[i])){
            j++;
        }
        i++;
    }
    qt_lit = j;
}

void Identificar_todos_numeros(const char *entrada, double* &saida, int &qt_num){
    int i = 0,j,o = 0;
    char* aux;
    aux = (char*)malloc(50*sizeof(char));
    while(entrada[i] != '\0'){
        j = 0;
        if(IsNumero(entrada[i]) && entrada[i] != 'e' && entrada[i] != 'P' && entrada[i] != 'F' && entrada[i] != 'L'){
            while(IsNumero(entrada[i])){
                aux[j] = entrada[i];
                j++;
                i++;
            }
            aux[j] = '\0';
            saida[o] = Char2double(aux);
            o++;
        }
        if(entrada[i] == 'e'){
            saida[o] = M_E;
            o++;
        }
        if(entrada[i] == 'P'){
            saida[o] = M_PI;
            o++;
        }
        if(entrada[i] == 'F'){
            saida[o] = MY_PHI;
            o++;
        }
        if(entrada[i] == 'L'){
            saida[o] = MY_L;
            o++;
        }
        i++;
   }
   qt_num = o;
   free(aux);
}

void Identificar_numero(const char* entrada,double &saida){
    int i = 0,j,achou = 0;
    char* aux;
    aux = (char*)malloc(50*sizeof(char));
    while(entrada[i] != '\0' && achou != 1){
        j = 0;
        if(IsNumero(entrada[i])){
            while(IsNumero(entrada[i])){
                aux[j] = entrada[i];
                j++;
                i++;
            }
            aux[j] = '\0';
            saida = Char2double(aux);
            achou = 1;
        }
        i++;
    }
    free(aux);
}

void Identificar_todos_operadores(const char* entrada,char* &saida,int &qt_op){
    int i = 0,j = 0;
    while(entrada[i] != '\0'){
        if(IsOperador(entrada[i])){
            saida[j] = entrada[i];
            j++;
        }
        i++;
    }
    qt_op = j;
}

void Identificar_operador(const char *entrada, int* &op){
    int i = 0,j = 0;
    while(entrada[i] != '\0'){
        if(IsOperador(entrada[i])){
            if(entrada[i] == '+'){
                op[j] = 1;
            }
            else{
                if(entrada[i] == '-'){
                    op[j] = 2;
                }
                else{
                    if(entrada[i] == '*'){
                        op[j] = 3;
                    }
                    else{
                        if(entrada[i] == '/'){
                            op[j] = 4;
                        }
                        else{
                            if(entrada[i] == '^'){
                                op[j] = 5;
                            }
                            else{
                                if(entrada[i] == '@'){
                                    op[j] = 6;
                                }
                                else{
                                    if(entrada[i] == '#'){
                                        op[j] = 7;
                                    }
                                    else{
                                        if(entrada[i] == '$'){
                                            op[j] = 8;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            j++;
        }
        i++;
    }
}

int Identificar_op(char entrada){
   if(entrada == '+'){
        return 1;
   }
   else{
        if(entrada == '-'){
            return 2;
        }
        else{
            if(entrada == '*'){
                return 3;
            }
            else{
                if(entrada == '/'){
                    return 4;
                }
                else{
                    if(entrada == '^'){
                        return 5;
                    }
                    else{
                        if(entrada == '@'){
                            return 6;
                        }
                        else{
                            if(entrada == '#'){
                                return 7;
                            }
                            else{
                                if(entrada == '$'){
                                    return 8;
                                }
                            }
                        }
                    }
                }
            }
        }
   }
}

double Operar(double x, int op, double y){
    if(op == 1){
        return Soma(x,y);
    }
    else{
        if(op == 2){
            return Sub(x,y);
        }
        else{
            if(op == 3){
                return Mult(x,y);
            }
            else{
                if(op == 4){
                    return Div(x,y);
                }
                else{
                    if(op == 5){
                        return pow(x,y);
                    }
                    else{
                        if(op == 6){
                            return Log(x,y);
                        }
                        else{
                            if(op == 7){
                                if(y == 1){
                                    return sin(x);
                                }
                                if(y == 2){
                                    return cos(x);
                                }
                                if(y == 3){
                                    return tan(x);
                                }
                                if(y == 4){
                                    return asin(x) * 180/M_PI;
                                }
                                if(y == 5){
                                    return acos(x) * 180/M_PI;
                                }
                                if(y == 6){
                                    return atan(x) * 180/M_PI;
                                }
                                if(y == 7){
                                    return sinh(x);
                                }
                                if(y == 8){
                                    return cosh(x);
                                }
                                if(y == 9){
                                    return tanh(x);
                                }
                            }
                            else{
                                if(op == 8){
                                    return Raiz_n(x,y);
                                }
                            }
                        }
                   }
                }
            }
        }
    }
}

void Contar_delimitadores(const char* entrada, int &qt_del){
    int i = 0,qt;
    while(entrada[i] != '\0'){
        if(IsDelimitador(entrada[i])){
            qt++;
        }
        i++;
    }
    qt_del = qt;
}

void Identificar_ordem(const char* entrada, int* &saida){
    int i = 0,j = 0;
    while(entrada[i] != '\0'){
        if(IsNumero(entrada[i])){
            while(IsNumero(entrada[i])){
                saida[j] = 1;
                i++;
            }
        j++;
        }
        if(IsOperador(entrada[i])){
            saida[j] = 2;
            j++;
        }
        if(IsLiteral(entrada[i])){
            saida[j] = 3;
            j++;
        }
        if(IsDelimitador(entrada[i])){
            saida[j] = 4;
            j++;
        }
        i++;
    }
}

void Identificar_ordem_redundante(const char* entrada,int* saida){
    int i = 0,j = 0;
    while(entrada[i] != '\0'){
        if(IsNumero(entrada[i])){
            saida[j] = 1;
            j++;
        }
        if(IsOperador(entrada[i])){
            saida[j] = 2;
            j++;
        }
        if(IsLiteral(entrada[i])){
            saida[j] = 3;
            j++;
        }
        if(IsDelimitador(entrada[i])){
            saida[j] = 4;
            j++;
        }
        i++;
    }
}

void Calcular_tamanho_real(const char *entrada, int &tamanho){
    char* saida;
    double* saida2;
    saida = (char*)malloc(50*sizeof(char));
    saida2 = (double*)malloc(50*sizeof(double));
    int qt_num,qt_op,qt_lit,qt_del;
    Identificar_todos_numeros(entrada,saida2,qt_num);
    Identificar_todos_operadores(entrada,saida,qt_op);
    Identificar_literais(entrada,qt_lit);
    Contar_delimitadores(entrada,qt_del);
    tamanho = qt_num + qt_op + qt_lit + qt_del;
    free(saida);
    free(saida2);
}

int Funcao_Simples(const char* entrada){
    int i = 0,c = 0;
    int* ordem;
    ordem = (int*)malloc(50*sizeof(int));
    Identificar_ordem(entrada,ordem);
    while(ordem[i] != NULL && c < 2){
        if(ordem[i] == 3){
            c++;
        }
        i++;
    }
    if(c < 2){
        return 1;
    }
    else{
        return 0;
    }
    free(ordem);
}

int Apresenta_restricao(const char* entrada){
    int i = 0;
    while(entrada[i] != '\0'){
        if(IsDelimitador(entrada[i])){
            return 1;
        }
        i++;
    }
    return 0;
}

void Copiar_string(char* saida, const char* entrada, int inicio, int fim){
    int i,j = 0;
    for(i = inicio; i <= fim; i++){
        saida[j] = entrada[i];
        j++;
    }
    saida[j] = '\0';
}

void Trocar_sinais(char* entrada){
    int i = 0;
    while(entrada[i] != '\0'){
        if(IsOperador(entrada[i])){
            if(Identificar_op(entrada[i]) == 1){
                entrada[i] = '-';
            }
            else if(Identificar_op(entrada[i]) == 2){
                entrada[i] = '+';
            }
        }
        i++;
    }
}

bool Sintaxe_correta(const char* entrada, char* &m_erro){
    int i = 0;
    int parenteses_abertura = 0,parenteses_fechamento = 0;
    m_erro[0] = '\0';
    while(entrada[i] != '\0'){
        if(entrada[i] == '('){
            parenteses_abertura++;
        }
        if(entrada[i] == ')'){
            parenteses_fechamento++;
        }
        if(entrada[i] == ' '){
            strcat(m_erro,"Erro de sintaxe! Voce nao deve usar espacos! Consulte a aba Ajuda?");
            return 0;
        }
        if(!IsNumero(entrada[i]) && !IsLiteral(entrada[i]) && !IsOperador(entrada[i]) && !IsDelimitador(entrada[i]) && entrada[i] != '\n' && entrada[i] != ' '){
            strcat(m_erro,"Erro de sintaxe! Simbolo ");
            m_erro[strlen(m_erro)] = entrada[i];
            m_erro[strlen(m_erro)] = '\0';
            strcat(m_erro," nao definido! Consulte a aba Ajuda?");
            return 0;
        }
        /*if(IsOperador(entrada[i])){
            if((!IsNumero(entrada[i-1]) && !IsLiteral(entrada[i-1]) && entrada[i-1] != ')') ||
            ((!IsNumero(entrada[i+1]) && !IsLiteral(entrada[i+1]) && entrada[i+1] != '('))){
                strcat(m_erro,"Erro de sintaxe! Voce esqueceu um dos termos no operador ");
                m_erro[strlen(m_erro)] = entrada[i];
                strcat(m_erro," !");
                return 0;
            }
        }*/
        i++;
    }
    if(parenteses_abertura > parenteses_fechamento){
        strcat(m_erro,"Erro de sintaxe! Voce se esqueceu de fechar algum par de parenteses!");
        return 0;
    }
    else if(parenteses_abertura < parenteses_fechamento){
        strcat(m_erro,"Erro de sintaxe! Falta(m) algum(ns) parentese(s) de abertura!");
        return 0;
    }
    return 1;
}

double Parser(const char* entrada,double x){
    double saida;
    int* ordem;
    int* ordem_r;
    int* operadores;
    double* numeros;
    int q_num;
    int i_nums = 0,i_ops = 0;
    int i,j;
    char* aux;
    char* aux2;
    char* aux3;
    double saida_parcial,saida_parcial2,saida_parcial3,saida_parcial4;
    aux = (char*)malloc(50*sizeof(char));
    aux2 = (char*)malloc(50*sizeof(char));
    aux3 = (char*)malloc(50*sizeof(char));
    numeros = (double*)malloc(50*sizeof(double));
    ordem = (int*)malloc(50*sizeof(int));
    ordem_r = (int*)malloc((50*sizeof(int)));
    operadores = (int*)malloc(50*sizeof(int));
    Identificar_ordem(entrada,ordem);
    Identificar_ordem_redundante(entrada,ordem_r);
    Identificar_todos_numeros(entrada,numeros,q_num);
    Identificar_operador(entrada,operadores);
    Calcular_tamanho_real(entrada,i);
    if(Apresenta_restricao(entrada)){
        j = 0;
        int ini,fim;
        int abriu = 0,fechou = 0,terminou = 0;
        while(terminou == 0){
            if(entrada[j] == '('){
                abriu++;
                ini = j;
                while(abriu != fechou){
                    if(entrada[j+1] == '('){
                        abriu++;
                    }
                    if(entrada[j+1] == ')'){
                        fechou++;
                    }
                    j++;
                }
                fim = j-1;
                terminou = 1;
            }
            j++;
        }
        Copiar_string(aux,entrada,0,ini-2);
        Copiar_string(aux2,entrada,ini+1,fim);
        Copiar_string(aux3,entrada,fim+3,strlen(entrada));
        saida_parcial = Parser(aux,x);
        saida_parcial2 = Parser(aux2,x);
        saida_parcial3 = Parser(aux3,x);
        if(Identificar_op(entrada[ini-1]) != 0){
            saida_parcial4 = Operar(saida_parcial,Identificar_op(entrada[ini-1]),saida_parcial2);
            saida = Operar(saida_parcial4,Identificar_op(entrada[fim+2]),saida_parcial3);
        }
        else{
            saida = Operar(saida_parcial2,Identificar_op(entrada[fim+2]),saida_parcial3);
        }
    }
    else{
    if(Funcao_Simples(entrada)){
        if(ordem[0] == 1){
            saida = Operar(numeros[i_nums],operadores[i_ops],x);
        }
        if(ordem[0] == 3){
            saida = Operar(x,operadores[i_nums],numeros[i_ops]);
        }
        i_nums++;
        i_ops++;
        j = 4;
        while(j < i){
            if(ordem[j] == 3){
                saida = Operar(saida,operadores[i_ops],x);
                i_ops++;
            }
            if(ordem[j] == 1){
                saida = Operar(saida,operadores[i_ops],numeros[i_nums]);
                i_nums++;
                i_ops++;
            }
            j = j + 2;
        }
    }
    else{
        int ocorrencia = 0;
        i = 0;
        while(ocorrencia < 2){
            if(IsLiteral(entrada[i])){
                ocorrencia++;
            }
            i++;
        }
        while(ordem_r[i-1] != 2){
            i--;
        }
        int op = Identificar_op(entrada[i-1]);
        Copiar_string(aux,entrada,0,i-2);
        Copiar_string(aux2,entrada,i,strlen(entrada));
        saida_parcial = Parser(aux,x);
        if(op == 2){
            Trocar_sinais(aux2);
        }
        saida_parcial2 = Parser(aux2,x);
        saida = Operar(saida_parcial,op,saida_parcial2);
    }
    }
    free(ordem);
    free(ordem_r);
    free(numeros);
    free(operadores);
    free(aux);
    free(aux2);
    free(aux3);
    return saida;
}

double Fun(const char* entrada,double x){
    return Parser(entrada,x);
}

double Derivar(const char* funcao, double x){
    const double delta = 1.0e-7;
    return (Parser(funcao,x+delta) - Parser(funcao,x)) / delta;
}
