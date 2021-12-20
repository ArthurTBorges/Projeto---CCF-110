//Objetivos do código:
// 1) Ler as operações feitas no mercado no periodo de 1 dia.
// 2) Separar as operaçôes por tipo de mercado.( Overgols, Virtual e escanteio asiatico)
// 3) Calcular o lucro diario e taxa de acertividade.
//OBSERVAÇÕES:
// 1) Odd = porcentagem de lucro. Ex: odd 0,45 = 45% de lucro na operação.
// 2) As são feitas sempre com 1%.
// 3)

#include <stdio.h>

int main(){
    int i, qOver, qVirtual, qAsiatico, banca;
    printf("Valor da banca:\n");
    scanf("%d", &banca);

    //Recebendo dados e calculando a porcentagem de lucro do mercado de Overgols
    printf("Quantas operacoes foram feitas no mercado de OVERGOLS?\n");
    scanf("%d", &qOver);
    float mercOvergols[qOver], acertosOver = 0;
    for(i = 0; i < qOver; i++){
        int resultado;
        printf("A operação foi bem sucedida? SIM = 1/NAO = 0:\n");
        scanf("%d", &resultado);
        if(resultado == 1){
            printf("Valor da Odd:\n");
            scanf("%f", mercOvergols[i]);
            acertosOver++;
        }
        else{
            mercOvergols[i] = -1;
        }
    }

    //Recebendo dados e calculando a porcentagem de lucro do mercado Virtual
    printf("Quantas operacoes foram feitas no mercado VIRTUAL?\n");
    scanf("%d", &qVirtual);
    float mercVirtual[qVirtual], acertosVirtual = 0;
    for(i = 0; i < qVirtual; i++){
        int resultado;
        printf("A operação foi bem sucedida? SIM = 1/NAO = 0:\n");
        scanf("%d", &resultado);
        if(resultado == 1){
            printf("Valor da Odd:\n");
            scanf("%f", mercVirtual[i]);
            acertosVirtual++;
        }
        else{
            mercVirtual[i] = -1;
        }
    }

    //Recebendo dados e calculando a porcentagem de lucro do mercado de Escanteios asiaticos
    printf("Quantas operacoes foram feitas no mercado de ESCANTEIOS ASIATICOS?\n");
    scanf("%d", &qAsiatico);
    float mercAsiatico[qAsiatico], acertosAsiatico = 0;
    for(i = 0; i < qAsiatico; i++){
        int resultado;
        printf("A operação foi bem sucedida? SIM = 1/NAO = 0:\n");
        scanf("%d", &resultado);
        if(resultado == 1){
            printf("Valor da Odd:\n");
            scanf("%f", mercAsiatico[i]);
            acertosAsiatico++;
        }
        else{
            mercAsiatico[i] = -1;
        }
    }

    //Calculando resultados do dia
    float porcentagemTotal = 0;
    float acertividadeOver = acertosOver / qOver;
    float acertividadeVirtual = acertosVirtual / qVirtual;
    float acertividadeAsiatico = acertosAsiatico / qAsiatico;
    int todasAsEntradas = qAsiatico + qVirtual + qOver;
    for(i = 0; i < todasAsEntradas; i++){
        porcentagemTotal += mercAsiatico[i];
        porcentagemTotal += mercOvergols[i];
        porcentagemTotal += mercVirtual[i];
    }
    float total = (porcentagemTotal / 100) * banca;

    //Imprimindo os resultados
    printf("RESUMO DO DIA:\n\n");
    printf("Banca de R$ %d\n", banca);
    printf("Mercado de Overgols, acertividade de %.2f\n", acertividadeOver);
    printf("Mercado de Escanteio asiatico, acertividade de %.2f\n", acertividadeAsiatico);
    printf("Mercado de Futebol Virtual, acertividade de %.2f\n", acertividadeVirtual);

    printf("Lucro total = R$ %.2f, %.2f % de lucro", total, porcentagemTotal);
    return 0;
}
