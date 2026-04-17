#include "ordenar.h"
#include "dadosDengue.h"
#include <stdio.h>
#include <string.h>


// subfuncoes (servem a uma outra funcao)
void criarVetorCopia(dadosDengue *tabelaReg, int inicio, int fim, int tipo, int *vCopia){
    int *pnt, i;
    for (i = inicio; i <= fim; i++){
        pnt = &tabelaReg[i].graves23 + (tipo-2)*4;
        vCopia[i] = *pnt;
    }
}
void combinar(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio+1;
    int k = 0;
    dadosDengue aux[fim - inicio + 1];
    // inicio = 0 | meio = 1 | fim = 3
    while(i <= meio && j <= fim){
        if (especificCompare(op, tabela, i, j)){
            aux[k++] = tabela[i++];
        }
        else {
            aux[k++] = tabela[j++];
        }
    }
        
    while(i <= meio){
        aux[k++] = tabela[i++];
    }
    while(j <= fim){
        aux[k++] = tabela[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++){
        tabela[i] = aux[k];
    }
    if (op.tipo > 1){
        criarVetorCopia(tabela, inicio, fim, op.tipo, vCopia);
    }
}
int escificCompare(tipoEscolha op, dadosDengue *tabela, int *vCopia, int i, int j){
    if (op.modo == 1){
        if (op.tipo == 1){
            return (strcmp(tabela[i].UF, tabela[j].UF) < 0) ? 1: 0;
        }
        else {
            return (vCopia[i] < vCopia[j]) ? 1: 0;
        }
    }
    else {
        if (op.tipo == 1){
            return (strcmp(tabela[i].UF, tabela[j].UF) > 0) ? 1: 0;
        }
        else {
            return (vCopia[i] > vCopia[j]) ? 1: 0;
        }
    }
}
/*
void switchCompare_string(int *iP, int *jP, int *kP){
    if (strcmp(tabela[(*iP)].UF, tabela[(*jP)].UF) < 0){
        aux[(*kP)++] = tabela[(*iP)++];
    }
    else {
        aux[(*kP)++] = tabela[(*jP)++];
    }
}
void switchCompare_int(){}
*/
/*
void combinarChar(dadosDengue *tabela, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio+1;
    int k = 0;
    dadosDengue aux[fim - inicio + 1];
    // inicio = 0 | meio = 1 | fim = 3
    while(i <= meio && j <= fim){
        if (strcmp(tabela[i].UF, tabela[j].UF) < 0){
            aux[k++] = tabela[i++];
        }
        else {
            aux[k++] = tabela[j++];
        }
    }

    while(i <= meio){
        aux[k++] = tabela[i++];
    }
    while(j <= fim){
        aux[k++] = tabela[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++){
        tabela[i] = aux[k];
    }
}
void combinarInt(dadosDengue *tabela, int *vCopia, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio+1;
    int k = 0;
    dadosDengue aux[fim - inicio + 1];
    // inicio = 0 | meio = 1 | fim = 3
    while(i <= meio && j <= fim){
        if (vCopia[i] < vCopia[j]){
            aux[k++] = tabela[i++];
        }
        else {
            aux[k++] = tabela[j++];
        }
    }

    while(i <= meio){
        aux[k++] = tabela[i++];
    }
    while(j <= fim){
        aux[k++] = tabela[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++){
        tabela[i] = aux[k];
    }
}
*/

// Funcoes principais
void escolhaOrdernarChar(dadosDengue *tabelaReg, tipoEscolha op){
    // literal so fazer o merge sort direto aqui, so que comparando e trocando com strings
    //merge sort
    //mergeChar(tabela, 0, op.qntUF - 1);
}
void escolhaOrdenarInt(dadosDengue *tabelaReg, tipoEscolha op){
    //int *adress = { &tabelaReg->graves23, &tabelaReg->obitos23, &tabelaReg->graves24, &tabelaReg->obitos24, &tabelaReg->difGraves, &tabelaReg->difObitos };
    //int *auxPrincipal= adress[?];
    int vCopia[op.qntUF];

    criarVetorCopia(tabelaReg, 0, op.qntUF - 1, op.tipo, vCopia);

    //aplicar merge sort com as alteracoes especificas do metodo int na comparacao e troca
    //mergeInt(tabela, vCopia, 0, op.qntUF - 1);
}
///*
void mergeSort(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeSort(tabela, op, vCopia, inicio, meio);
        mergeSort(tabela, op, vCopia, meio+1, fim);
        combinar(tabela, op, vCopia, inicio, meio, fim);
    }
}
//*/
/*
void mergeChar(dadosDengue *tabela, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeChar(tabela, inicio, meio);
        mergeChar(tabela, meio+1, fim);
        combinarChar(tabela, inicio, meio, fim);
    }
}
void mergeInt(dadosDengue *tabela, int *vCopia, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeInt(tabela, vCopia, inicio, meio);
        mergeInt(tabela, vCopia, meio+1, fim);
        combinarInt(tabela, vCopia, inicio, meio, fim);
    }
}
*/
