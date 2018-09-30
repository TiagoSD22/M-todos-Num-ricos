#include "funcoes_erro.h"

double Truncar(double numero, int digitos){
    return numero - fmod(numero,pow(10,-digitos));
    /*double round_down, round_up;
    double scale = pow(10,digitos);
      round_down   = std::floor (numero * scale);
      round_up     = (round_down + 1.0) / scale;
      round_down  /= scale;

    if (numero != round_up){
        numero = round_down;
    }
    return numero;
    */
}

double SPF(double numero, int base, int mantissa, int lower, int upper){
    double resultado = numero/pow(10,(int)((log(numero)/log(10)) + 1));
    return Truncar(resultado,mantissa);
}

double Maximo(int base, int mantissa, int upper){
    double resultado = (1 - (1 /pow(10,mantissa))) * pow(10,upper);
    return resultado;
}

double Minimo(int base, int mantissa, int lower){
    double resultado = 0.1 * pow(10,lower);
    return resultado;
}
