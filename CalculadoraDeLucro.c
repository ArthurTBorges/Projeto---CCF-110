#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano, quantidade;
}inicializar;

typedef struct{
    int resultado;
    float valor, odd, retornoBruto, lucro;
    char mercado[100];
}Entrada;


inicializar lerData(){
    inicializar inic;
    printf("Digite a data(dd mm aaaa):\n"); //Recebendo a data
    scanf("%d %d %d", &inic.dia, &inic.mes, &inic.ano);

    printf("Quantas entradas foram feitas:\n");
    scanf("%d", &inic.quantidade);

    return inic;
}

float calculaResult(float valor, float odd){
    float lucro;
    if(odd < 0){
        lucro = -1 * valor;
    }
    else{
        if(odd > 0){
            lucro = odd * valor;
        }
        else{
            lucro = 0;
        }
    }
    return lucro;
}

int verificaResultado(float retorno){
    int res;
    if(retorno == 0){
        res = 0;
    }
    else{
        if(retorno > 0){
            res = 1;
        }
        else{
            res = -1;
        }
    }

    return res;
}

int calculaAcertos(float retorno){
    int acert = 0;
    if(retorno > 0){
        acert = 1;
    }
    return acert;
}

int calculaErros(float retorno){
    int err;
    if(retorno > 0){
        err = 0;
    }
    else{
        err = 1;
    }

    return err;
}

float calculaSoma(float retorno, float valor){
    float total;
    if(retorno <= 0){
        total = retorno;
    }
    else{
        total = retorno - valor;
    }

    return total;
}

float calculaLucro(float valor, float odd, float retorno){
    float lucro;
    if(odd == 0){
        lucro = 0;
    }else{
        if(odd < 0){
            lucro = -1 * valor;
        }else{
            lucro = retorno - valor;
        }
    }
    return lucro;
}


Entrada lerEntrada(int *acertos, int *erros, float *soma){
    Entrada p;
    printf("Digite o mercado:\n");
    scanf("%s",p.mercado);
    printf("Digite o valor de entrada:\n");
    scanf("%f", &p.valor);
    printf("Digite a ODD:\n");
    scanf("%f", &p.odd);

    p.retornoBruto = calculaResult(p.valor, p.odd);

    p.resultado = verificaResultado(p.retornoBruto);

    p.lucro = calculaLucro(p.valor, p.odd, p.retornoBruto);

    *acertos += calculaAcertos(p.retornoBruto);
    *erros += calculaErros(p.retornoBruto);
    *soma += calculaSoma(p.retornoBruto, p.valor);

    return p;
}

void escreveArquivo(int *ptrAcertos, int *ptrErros, float *ptrSoma, int dia, int mes, int ano){

    inicializar inicial;
    int tam = inicial.quantidade;
    Entrada x[tam];


    FILE *f;
    f = fopen("Relatorio.txt", "w");
    if(f == NULL){
        printf("Erro de abertura!\n");
        system("pause");
        exit(1);
    }

    fprintf(f, "***RELATORIO %d %d %d***\n\n", dia, mes, ano);
    fprintf(f, "Lucro total: R$ %.2f\n", *ptrSoma);
    fprintf(f, "Erros: %d\n", *ptrErros);
    fprintf(f, "Acertos: %d\n\n", *ptrAcertos);

    fclose(f);
}

void imprimirResult(Entrada p){

    FILE *f;
    f = fopen("Relatorio.txt", "a");
    if(f == NULL){
        printf("Erro de reabertura!\n");
        system("pause");
        exit(1);
    }

    fprintf(f, "\nMercado: %s\n", p.mercado);
    fprintf(f, "Aposta:R$ %.2f\n", p.valor);
    fprintf(f, "Odd: %.2f\n", p.odd);
    fprintf(f, "Retorno:R$ %.2f\n", p.retornoBruto);
    fprintf(f, "Lucro:R$ %.2f\n", p.lucro);
    if(p.resultado == 0){
        fprintf(f, "NULA\n");
    }else{
        if(p.resultado == -1){
            fprintf(f, "PERDIDA\n");
        }else{
            fprintf(f, "ACERTIVA\n");
        }
    }

}

int main() {

    inicializar inicial; //rececendo data e quantidade de operações
    inicial = lerData();

    //definindo a quantidade de structs e definindo ponteiros
    int i, tam = inicial.quantidade;
    Entrada x[tam];
    int acertos = 0, erros = 0;
    int *ptrAcertos = &acertos, *ptrErros = &erros;
    float soma = 0;
    float *ptrSoma = & soma;

    for(i = 0; i < tam; i++){
        x[i] = lerEntrada(ptrAcertos, ptrErros, ptrSoma);
    }

    escreveArquivo(ptrAcertos, ptrErros, ptrSoma, inicial.dia, inicial.mes, inicial.ano);

    for(i = 0; i < tam; i++){
        imprimirResult(x[i]);
    }
    return 0;
}
