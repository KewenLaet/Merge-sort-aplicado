#include "ordenar.h"
#include "dadosDengue.h"
#include <stdio.h>
#include <string.h>


// subfuncoes (servem a uma outra funcao)
void criarVetorCopia(dadosDengue *tabelaReg, int inicio, int fim, int tipo, int *vCopia){
    int *pnt, i;
    for (i = inicio; i <= fim; i++){
        pnt = &tabelaReg[i].graves23 + (tipo-2);
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
        if (especificCompare(op, tabela, vCopia, i, j)){
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
int especificCompare(tipoEscolha op, dadosDengue *tabela, int *vCopia, int i, int j){
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

// Funcoes principais
void mergeSort(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeSort(tabela, op, vCopia, inicio, meio);
        mergeSort(tabela, op, vCopia, meio+1, fim);
        combinar(tabela, op, vCopia, inicio, meio, fim);
    }
}
