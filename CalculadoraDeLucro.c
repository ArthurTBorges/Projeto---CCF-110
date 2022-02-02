//Objetivos do código:
// 1) Ler as operações feitas no mercado no periodo de 1 dia.
// 2) Separar as operaçôes por tipo de mercado.( Overgols e Virtual)
// 3) Calcular o lucro diario e taxa de acertividade.
//OBSERVAÇÕES:
// 1) As operações acertivas tem sempre a mesma recompensa por mercado.



#include <stdio.h>

int main(){

    //Recebendo os valores e resultados das apostas.
    //O programa cria duas matrizes para guardar na primeira linha o valor das apostas e o resultado na segunda.

    int qOver;
    printf("Quantas operacoes foram feitas no mercado de OVERGOLS?\n");
    scanf("%d", &qOver);
    float operacoesOver[2][qOver];
    for(int i = 0; i < qOver; i++){
        int aux;
        printf("Valor da aposta %d:\n", i);
        scanf("%f", &operacoesOver[0][i]);
        printf("Aposta bem sucedida? Use 1 para SIM e 0 para NAO:\n");
        scanf("%f", &aux);
        if(aux == 1){
            operacoesOver[1][i] = 0.7;
        }
        else{
            operacoesOver[1][i] = -1;
        }
    }

    int qVirtual;
    printf("Quantas operacoes foram feitas no mercado VIRTUAL?\n");
    scanf("%d", &qVirtual);
    float operacoesVirtual[2][qVirtual];
    for(int i = 0; i < qVirtual; i++){
        int aux;
        printf("Valor da aposta %d:\n", i);
        scanf("%f", &operacoesVirtual[0][i]);
        printf("Aposta bem sucedida? Use 1 para SIM e 0 para NAO:\n");
        scanf("%f", &aux);
        if(aux == 1){
            operacoesVirtual[1][i] = 0.7;
        }
        else{
            operacoesVirtual[1][i] = -1;
        }
    }

    //Calculando lucro:
    float lucroOver = 0, lucroVirtual = 0;
    for(int i = 0; i < qOver; i++){
        lucroOver *= operacoesOver[0][i] * operacoesOver[1][i];
    }
    for(int i = 0; i < qVirtual; i++){
        lucroVirtual += operacoesVirtual[0][i] * operacoesVirtual[1][i];
    }

    //Calculando a quantidade de acertos para definir a acertividade:
    float acertosOver = 0, acertosVirtual = 0;
    for(int i = 0; i < qOver; i++){
        if(operacoesOver[1][i] > 0){
            acertosOver += 1;
        }
    }
    for(int i = 0; i < qVirtual; i++){
        if(operacoesVirtual[1][i] > 0){
            acertosVirtual += 1;
        }
    }

    //Calculando acertividade:
    float acertividadeOver = (acertosOver * 100) / qOver;
    float acertividadeVirtual = (acertosVirtual * 100) / qVirtual;

    //Definindo variaveis para ajudar o raciocinio:
    float acertosTotal = acertosVirtual + acertosOver;
    float lucroTotal = lucroVirtual + lucroOver;

    //Informando os resultados:
    printf("\n>>>RESULTADO DIARIO<<<\n\n");

    printf("Resultados do mercado de Overgols:\n");
    printf("Lucro = R$ %.2f\n", lucroOver);
    printf("Foram %f operacoes bem sucedidas", acertosOver);
    printf("Acertividade = %.2f %\n\n", acertividadeOver);

    printf("Resultados do mercado Virtual:\n");
    printf("Lucro = R$ %.2f\n", lucroVirtual);
    printf("Foram %f operacoes bem sucedidas\n", acertosVirtual);
    printf("Acertividade = %.2f %\n\n", acertividadeVirtual);

    printf("Resultado final\n");
    printf("%f operacoes bem sucedidas no total\n", acertosTotal);
    printf("Lucro Total = R$ %.2f\n", lucroTotal);

    return 0;
}
