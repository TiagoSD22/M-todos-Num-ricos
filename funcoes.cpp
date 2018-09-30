#include<stdlib.h>
#include<ctype.h>
#include<cmath>
#include<string.h>
#include"funcoes.h"

int Logaritmo(int numero, int base){
    int resultado = 0;
    while(numero >= base){
        numero = numero/base;
        resultado++;
    }
    return resultado;
}

int Conversor_Reverso(char entrada[255], int base, int &erro, char* &m_erro){
    int tamanho = strlen(entrada) - 1;
    int i,j,resposta = 0;
    char *alpha,*num;
    const char* numero_erro[10] = {"0","1","2","3","4","5","6","7","8","9"};
    const char* letra_erro[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    const char* bases_erro[35] = {"2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21",
                            "22","23","24","25","26","27","28","29","30","31","32","33","34","35","36"};
    alpha = (char*) malloc(26 * sizeof(char));
    num = (char*)malloc(10 * sizeof(char));
    for(i = 0; i < 26; i++){
        alpha[i] = i + 'A';
    }
    alpha[i] = '\0';
    for(i = 0; i < 10; i++){
        num[i] = i + '0';
    }
    num[i] = '\0';
    for(i = 0; i <= tamanho; i++){
        j = 0;
        if(isdigit(entrada[i])){
            while(entrada[i] != num[j]){
                j++;
            }
            if(j >= base){
                erro = 1;
                strcat(m_erro,"O número ");
                strcat(m_erro,numero_erro[j]);
                strcat(m_erro," não existe em bases menores que ");
                strcat(m_erro,numero_erro[j+1]);
                strcat(m_erro,".");
                return 0;
            }
            else{
                resposta = resposta + (j * pow(base,tamanho - i));
            }
        }
        if(isalpha(entrada[i])){
            while(entrada[i] != alpha[j]){
                j++;
            }
            if(j + 10 >= base){
                erro = 1;
                strcat(m_erro,"O caractere ");
                strcat(m_erro,letra_erro[j]);
                strcat(m_erro," não existe em bases menores que ");
                strcat(m_erro,bases_erro[j + 9]);
                strcat(m_erro,".");
                return 0;
            }
            else{
                resposta = resposta + ((j + 10) * pow(base,tamanho - i));
            }
        }
    }
    return resposta;
    free(alpha);
    free(num);
}

char* Conversor_de_Base(int numero, int base){
    int tamanho_do_vetor = Logaritmo(numero,base);
    int vetor[tamanho_do_vetor],i = tamanho_do_vetor,j;
    char *alpha,*num,*resposta;
    alpha = (char*)malloc(26 * sizeof(char));
    num = (char*)malloc(10 * sizeof(char));
    resposta = (char*)malloc(tamanho_do_vetor * sizeof(char));
    for(j = 0; j < 26; j++){
        alpha[j] = j + 'A';
    }
    alpha[j] = '\0';
    for(j = 0; j < 10; j++){
        num[j] = j + '0';
    }
    num[j] = '\0';
    while(numero >= base){
        vetor[i] = numero%base;
        numero = numero/base;
        i--;
    }
    vetor[0] = numero;
    for(i = 0; i <= tamanho_do_vetor; i++){
        if(vetor[i] < 10){
            resposta[i] = num[vetor[i]];
        }
        else{
            resposta[i] = alpha[vetor[i] -10];
        }
    }
    resposta[i] = '\0';
    return resposta;
    free(alpha);
    free(num);
    free(resposta);
}
