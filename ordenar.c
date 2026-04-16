#include "ordenar.h"
#include "dadosDengue.h"
#include <stdio.h>
#include <string.h>

void escolhaOrdernarChar(dadosDengue *tabelaReg, tipoEscolha op){
    // literal so fazer o merge sort direto aqui, so que comparando e trocando com strings
}
void escolhaOrdenarInt(dadosDengue *tabelaReg, tipoEscolha op){
    //int *adress = { &tabelaReg->graves23, &tabelaReg->obitos23, &tabelaReg->graves24, &tabelaReg->obitos24, &tabelaReg->difGraves, &tabelaReg->difObitos };
    //int *auxPrincipal= adress[?];
    int vCopia[op.qntUF];

    criarVetorCopia(tabelaReg, op, vCopia);

    //aplicar merge sort com as alteracoes especificas do metodo int na comparacao e troca
}
void criarVetorCopia(dadosDengue *tabelaReg, tipoEscolha op, int *vCopia){
    int i;

    switch (op.tipo){
        case 2:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].graves23;
            }
        break;
        case 3:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].obitos23;
            }
        break;
        case 4:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].graves24;
            }
        break;
        case 5:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].obitos24;
            }
        break;
        case 6:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].difGraves;
            }
        break;
        case 7:
            for (i = 0; i < op.qntUF; i++){
                vCopia[i] = tabelaReg[i].difObitos;
            }
        break;
        default:
            printf("\nErro na funcao \"criarVetorCopia\"!\n");
            return;
    }
}

void insertionSort(dadosDengue *meuVetor, int tam){
    int i, j;
    dadosDengue aux;

    for (i=1; i < tam; i++){
        for (j=i; j > 0; j--){
            if (strncmp((meuVetor[j-1]).UF, (meuVetor[j]).UF, 3) > 0){
                aux= meuVetor[j-1];
                meuVetor[j-1]= meuVetor[j];
                meuVetor[j]= aux;
            } 
            else {
                break;
            }
        }
    }
}
