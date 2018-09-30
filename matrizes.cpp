#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int Contar_chaves(const char* entrada){
    int i = 0,res = 0;
    while(entrada[i] != '\0'){
        if(entrada[i] == '}'){
            res++;
        }
        i++;
    }
    return res - 1;
}

int Numero(const char entrada){
    if(isdigit(entrada) || entrada == '-' || entrada == '.'){
        return 1;
    }
    else{
        return 0;
    }
}

int Contar_numeros(const char *entrada){
    int i = 0,o = 0;
    while(entrada[i] != '\0'){
        if(Numero(entrada[i])){
            while(Numero(entrada[i])){
                i++;
            }
            o++;
        }
        i++;
    }
    return o;
}

double *Guardar_numeros(const char* entrada){
    double* numeros;
    numeros = (double*)malloc(Contar_numeros(entrada)*sizeof(double));
    char* aux;
    aux = (char*)malloc(100*sizeof(char));
    int i =0,j,o = 0;
    while(entrada[i] != '\0'){
        j = 0;
        if(Numero(entrada[i])){
            while(Numero(entrada[i])){
                aux[j] = entrada[i];
                j++;
                i++;
            }
            aux[j] = '\0';
            numeros[o] = atof(aux);
            o++;
        }
        i++;
    }
    return numeros;
    free(numeros);
    free(aux);
}

int IsQuadrada(const char* matrix){
    int q_num = Contar_numeros(matrix);
    int q_chaves = Contar_chaves(matrix);
    if(sqrt(q_num) == q_chaves){
        return 1;
    }
    return 0;
}

void Calcular_ordem(const char* matrix, int &linhas, int &colunas){
    linhas = Contar_chaves(matrix);
    colunas = Contar_numeros(matrix)/linhas;
}

char* Gerar_representacao_matricial(const char *entrada){
    char* saida;
    //saida = (char*)malloc((strlen(entrada) - (2*Contar_chaves(entrada) + 2)) * sizeof(char));
    saida = (char*)malloc(1024 * sizeof(char));
    saida[0] = '\0';
    int i,i_saida = 0;
    int l,c;
    Calcular_ordem(entrada,l,c);
    int q_virgula = 0;
    for(i = 0; i < strlen(entrada); i++){
        if(entrada[i] != '{' && entrada[i] != '}'){
            saida[i_saida] = entrada[i];
            i_saida++;
        }
    }
    saida[i_saida] = '\0';
    for(i = 0; i < i_saida-1; i++){
       if(saida[i] == ','){
            saida[i] = ' ';
            q_virgula++;
            if(q_virgula % c == 0){
                saida[i] = '\n';
            }
        }
    }
    return saida;
    free(saida);
}

int Determinante(int i,int j,double** matrix){
    int det;
    if(i == j){
        if(i == 2){
            det = (matrix[0][0]*matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            return det;
        }
        else{
            det = 0;
            int i_aux,j_aux,c,l,j_aux2;
            double** matrix_copia;
            matrix_copia = (double**)malloc((i-1) * sizeof(double*));
            int index;
            for(index = 0; index < (i-1);index++){
                matrix_copia[index] = (double*)malloc((j-1) * sizeof(double*));
            }
            int fator = 1;
            for(j_aux2 = 0; j_aux2 < j; j_aux2++){ //olhando os elementos da primeira linha
                i_aux = 0;
                j_aux = 0;
                    for(l = 1; l < i; l++){
                        for(c = 0; c < j; c++){
                            if(c != j_aux2){ // copio o elemento se ele nao estiver na mesma coluna do elemento da primeira linha
                                matrix_copia[i_aux][j_aux] = matrix[l][c];
                                j_aux++; //povoa primeiro as colunas
                                if(j_aux == (j-1)){ // quando termina de povoar as colunas da copia que tem j-1colunas
                                    j_aux = 0; // poe a posição da coluna para zero de novo e incrementa a linha
                                    i_aux++; // para povoar as colunas da próxima linha
                                }
                            }
                        }
                    }
                det = det + (fator*(matrix[0][j_aux2]*Determinante(i-1,j-1,matrix_copia)));
                fator = -1*fator;
            }
            free(matrix_copia);
        }
    }
    else{
        return 0;
    }
    return det;
}

double* Cramer(int i, int j, double** matrix, double* vetor_independente, int &erro){
    int xi,i_aux,j_aux;
    double** matrix_aux;
    matrix_aux = (double**)malloc(i * sizeof(double*));
    int index;
    for(index = 0; index < i;index++){
        matrix_aux[index] = (double*)malloc(j * sizeof(double*));
    }
    double* raiz;
    raiz = (double*)malloc(i * sizeof(double));
    for(xi = 0; xi < i; xi++){
    index = 0;
        for(i_aux = 0; i_aux < i; i_aux++){
            for(j_aux = 0; j_aux < j; j_aux++){
                if(j_aux == xi){
                    matrix_aux[i_aux][j_aux] = vetor_independente[index];
                    index++;
                }
                else{
                    matrix_aux[i_aux][j_aux] = matrix[i_aux][j_aux];
                }
            }
        }
        if(Determinante(i,j,matrix) == 0){
            erro = 1;
        }
        else{
            raiz[xi] = Determinante(i,j,matrix_aux)/Determinante(i,j,matrix);
        }
    }
    return raiz;
    free(raiz);
}

double* Solucionar_triangular_inferior(int i, double **matrix, double *vetor_independente){
    int xi,i_aux;
    double S;
    double* raiz;
    raiz = (double*)malloc(i * sizeof(double));
    raiz[0] = vetor_independente[0]/matrix[0][0];
    for(i_aux = 1; i_aux < i; i_aux++){
        S = 0;
        for(xi = 0; xi < i_aux; xi++){
            S = S + matrix[i_aux][xi] * raiz[xi];
        }
        raiz[i_aux] = (vetor_independente[i_aux] - S)/matrix[i_aux][i_aux];
    }
    return raiz;
    free(raiz);
}

double* Solucionar_triangular_superior(int i, double** matrix, double* vetor_independente){
    int xi,i_aux;
    double S;
    double* raiz;
    raiz = (double*)malloc(i * sizeof(double));
    raiz[i-1] = vetor_independente[i-1]/matrix[i-1][i-1];
    for(i_aux = i - 2; i_aux >= 0; i_aux--){
        S = 0;
        for(xi = i_aux + 1; xi < i; xi++){
            S = S + matrix[i_aux][xi] * raiz[xi];
        }
        raiz[i_aux] = (vetor_independente[i_aux] - S)/matrix[i_aux][i_aux];
    }
    return raiz;
    free(raiz);
}

double* Gauss(int i, int j, double** matrix, double* vetor_independente){
    int xi,i_aux,j_aux;
    double m;
    double* raiz;
    raiz = (double*)malloc(i * sizeof(double));
    double** matrix_aux;
    matrix_aux = (double**)malloc(i * sizeof(double*));
    int index;
    for(index = 0; index < i;index++){
        matrix_aux[index] = (double*)malloc(j * sizeof(double*));
    }
    for(i_aux = 0; i_aux < i; i_aux++){
        for(j_aux = 0; j_aux < j; j_aux++){
            matrix_aux[i_aux][j_aux] = matrix[i_aux][j_aux];
        }
    }
    for(xi = 0; xi < i-1; xi++){
        for(i_aux = xi + 1; i_aux < i; i_aux++){
            m = -(matrix_aux[i_aux][xi]/(matrix_aux[xi][xi]));
            matrix_aux[i_aux][xi] = 0;
            for(j_aux = xi + 1; j_aux < j; j_aux++){
                matrix_aux[i_aux][j_aux] = matrix_aux[i_aux][j_aux] + m * matrix_aux[xi][j_aux];
            }
            vetor_independente[i_aux] = vetor_independente[i_aux] + m * vetor_independente[xi];
        }
    }
    raiz = Solucionar_triangular_superior(i,matrix_aux,vetor_independente);
    return raiz;
    free(matrix_aux);
    free(raiz);
}

void Copiar_matrix(int i, int j, double** entrada,double** &saida){
    int x,y;
    for(x = 0; x < i; x++){
        for(y = 0; y < j; y++){
            saida[x][y] = entrada[x][y];
        }
    }
}

bool Precisa_pivotar(int i, double** matrix, int i_atual, int j_atual){
    int x;
    for(x = i_atual + 1; x < i; x++){
        if(matrix[x][j_atual] > matrix[i_atual][j_atual]){
            return 1;
        }
    }
    return 0;
}

double Encontrar_maior(int i, double** matrix, int i_atual, int j_atual, double &maior, int &linha_do_maior){
    int x;
    maior = matrix[i_atual][j_atual];
    linha_do_maior = i_atual;
    for(x = i_atual + 1; x < i; x++){
        if(fabs(matrix[x][j_atual]) > maior){
            maior = matrix[x][j_atual];
            linha_do_maior = x;
        }
    }
}

void Gerar_identidade(int i, int j, double** matrix){
    int x,y;
    for(x = 0; x < i; x++){
        for(y = 0; y < j; y++){
            if(x == y){
                matrix[x][y] = 1;
            }
            else{
                matrix[x][y] = 0;
            }
        }
    }
}

void Trocar_linha(int i, int j, double** matrix, int linha1, int linha2){
    int y;
    double aux;
    for(y = 0; y < j; y++){
        aux = matrix[linha1][y];
        matrix[linha1][y] = matrix[linha2][y];
        matrix[linha2][y] = aux;
    }
}

int Determinante_triangular(int i, int j, double** matrix){
    int i2,j2;
    int det = 1;
    for(i2 = 0; i2 < i; i2++){
        for(j2 = 0; j2 < j; j2++){
            if(i2 == j2){
                det = det * matrix[i2][j2];
            }
        }
    }
    return det;
}

double* Gauss_com_pivoteamento(int i, int j, double** matrix, double* vetor_independente){
    int xi,i_aux,j_aux,linha_do_maior,posicao;
    double m,maior;
    double* raiz;
    double** matrix_aux;
    matrix_aux = (double**)malloc(i * sizeof(double*));
    int index;
    for(index = 0; index < i;index++){
        matrix_aux[index] = (double*)malloc(j * sizeof(double*));
    }
    Copiar_matrix(i,j,matrix,matrix_aux);
    for(xi = 0; xi < i-1; xi++){
        if(Precisa_pivotar(i,matrix_aux,xi,xi)){
            Encontrar_maior(i,matrix_aux,xi,xi,maior,linha_do_maior);
            Trocar_linha(i,j,matrix_aux,xi,linha_do_maior);
            posicao = vetor_independente[xi];
            vetor_independente[xi] = vetor_independente[linha_do_maior];
            vetor_independente[linha_do_maior] = posicao;
        }
        for(i_aux = xi + 1; i_aux < i; i_aux++){
            m = -(matrix_aux[i_aux][xi]/(matrix_aux[xi][xi]));
            matrix_aux[i_aux][xi] = 0;
            for(j_aux = xi + 1; j_aux < j; j_aux++){
                matrix_aux[i_aux][j_aux] = matrix_aux[i_aux][j_aux] + m * matrix_aux[xi][j_aux];
            }
            vetor_independente[i_aux] = vetor_independente[i_aux] + m * vetor_independente[xi];
        }
    }
    raiz = Solucionar_triangular_superior(i,matrix_aux,vetor_independente);
    return raiz;
    free(matrix_aux);
}

double* Gauss_jordan(int n, double** matrix, double* vetor){
    int xi,i_aux,j_aux,yi;
    double m;
    for(xi = 0; xi < n; xi++){
        for(i_aux = xi + 1; i_aux < n; i_aux++){
            matrix[xi][i_aux] = matrix[xi][i_aux]/matrix[xi][xi];
        }
        vetor[xi] = vetor[xi]/matrix[xi][xi];
        matrix[xi][xi] = 1;
        for(j_aux = 0; j_aux < n; j_aux++){
            if(j_aux != xi){
                for(yi = xi + 1; yi < n; yi++){
                    matrix[j_aux][yi] = matrix[j_aux][yi] - (matrix[j_aux][xi] * matrix[xi][yi]);
                }
                vetor[j_aux] = vetor[j_aux] - (matrix[j_aux][xi] * vetor[xi]);
                matrix[j_aux][xi] = 0;
            }
        }
    }
    return vetor;
}

void Inversa(int i, int j, double** matrix, double** &inversa){
    int xi,i_aux,j_aux,yi;
    double m;
    double** matrix_extendida;
    matrix_extendida = (double**)malloc(i*sizeof(double));
    int index;
    for(index = 0; index < i; index++){
        matrix_extendida[index] = (double*)malloc(2*j*sizeof(double));
    }
    for(i_aux = 0; i_aux < i; i_aux++){
        for(j_aux = 0; j_aux < 2*j; j_aux++){
            if(j_aux < j){
                matrix_extendida[i_aux][j_aux] = matrix[i_aux][j_aux];
            }
            else{
                matrix_extendida[i_aux][j_aux] = inversa[i_aux][j_aux-j];
            }
        }
    }
    for(xi = 0; xi < i; xi++){
        for(i_aux = xi + 1; i_aux < 2*j; i_aux++){
            matrix_extendida[xi][i_aux] = matrix_extendida[xi][i_aux]/matrix_extendida[xi][xi];
        }
        matrix_extendida[xi][xi] = 1;
        for(j_aux = 0; j_aux < j; j_aux++){
            if(j_aux != xi){
                for(yi = xi+1; yi < 2*j; yi++){
                    matrix_extendida[j_aux][yi] = matrix_extendida[j_aux][yi] - (matrix_extendida[j_aux][xi] * matrix_extendida[xi][yi]);
                }
                matrix_extendida[j_aux][xi] = 0;
            }
        }
    }
    for(xi = 0; xi < i; xi++){
        for(yi = j; yi < 2*j; yi++){
            inversa[xi][yi-j] = matrix_extendida[xi][yi];
        }
    }
}

void Transposta(int i, int j, double** matrix, double** &trasposta){
    int x,y;
    for(x = 0; x < i; x++){
        for(y = 0; y < j; y++){
            trasposta[x][y] = matrix[y][x];
        }
    }
}

void Transformar_triangular_superior(int i, int j, double** matrix){
    int xi,i_aux,j_aux;
    double m;
    for(xi = 0; xi < i-1; xi++){
        for(i_aux = xi + 1; i_aux < i; i_aux++){
            m = -(matrix[i_aux][xi]/(matrix[xi][xi]));
            matrix[i_aux][xi] = 0;
            for(j_aux = xi + 1; j_aux < j; j_aux++){
                matrix[i_aux][j_aux] = matrix[i_aux][j_aux] + m * matrix[xi][j_aux];
            }
        }
    }
}

void Gerar_LU(int i, int j, double**matrix, double** L, double** U){
    int xi,i_aux,j_aux;
    double m;
    Gerar_identidade(i,j,L);
    Copiar_matrix(i,j,matrix,U);
    Transformar_triangular_superior(i,j,U);
    for(xi = 0; xi < i-1; xi++){
        for(i_aux = xi + 1; i_aux < i; i_aux++){
            m = -(matrix[i_aux][xi]/(matrix[xi][xi])); 
            L[i_aux][xi] = -m;
        }
    }
}

double Maximo_no_vetor(double* v,int t){
    double max = 0;
    int i;
    i = 0;
    while(i < t){
        if(fabs(v[i]) > max){
            max = fabs(v[i]);
        }
        i++;
    }
    return max;
}

double Norma(double* v1,double* v0,int t){
    double* v3;
    v3 = (double*)malloc(t * sizeof(double));
    int i;
    for(i = 0; i < t; i++){
        v3[i] = fabs(v1[i] - v0[i]);
    }
    return Maximo_no_vetor(v3,t)/Maximo_no_vetor(v1,t);
}

double* Gauss_Jacob(int i, int j, double** matrix, double* vetor, double* chute0,int max_it, double precisao){
    int k,x,y;
    double S;
    double* chute1;
    double* aux;
    chute1 = (double*)malloc(i * sizeof(double));
    aux = (double*)malloc(i * sizeof(double));
    k = 0;
    do{
        for(x = 0; x < i; x++){
            S = 0;
            for(y = 0; y < j; y++){
                if(y != x){
                    aux[y] = chute0[y];
                    S = S + vetor[x] - (matrix[x][y] * chute0[y]);
                    std::cout<<S<<"\n\n";
                }
            }
            chute1[x] = S/matrix[x][x];
            chute0[x] = chute1[x];
        }
        k++;
    }while(k < max_it && Norma(chute1,aux,i) >= precisao);
    return chute1;
    free(chute1);
    free(aux);
}

void Gerar_LU_Doolittle(int n, double**  matriz, double** &L, double** &U){
    int i,j,l;
    double S;
    Gerar_identidade(n,n,L);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            U[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            S = 0;
            for(l = 0; l < i; l++){
                S = S + (L[i][l] * U[l][j]);
            }
            U[i][j] = (matriz[i][j] - S)/L[i][i];
        }
        for(j = i + 1; j < n; j++){
            S = 0;
            for(l = 0; l < i; l++){
                S = S + (L[j][l] * U[l][i]);
            }
            L[j][i] = (matriz[j][i] - S)/U[i][i];
        }
    }
}

double* Solucionar_Doolittle(int n, double** matriz, double* vetor_independente){
    double* saida;
    saida = (double*)malloc(n * sizeof(double));
    double* saida_parcial;
    saida_parcial = (double*)malloc(n * sizeof(double));
    double** L;
    L = (double**)malloc(n * sizeof(double*));
    int index;
    for(index = 0; index < n; index++){
        L[index] = (double*)malloc(n * sizeof(double*));
    }
    double** U;
    U = (double**)malloc(n * sizeof(double*));
    for(index = 0; index < n; index++){
        U[index] = (double*)malloc(n * sizeof(double*));
    }
    Gerar_LU_Doolittle(n,matriz,L,U);
    saida_parcial = Solucionar_triangular_inferior(n,L,vetor_independente);
    saida = Solucionar_triangular_superior(n,U,saida_parcial);
    return saida;
    free(saida);
    free(saida_parcial);
    free(L);
    free(U);
}
