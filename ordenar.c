#include "ordenar.h"
#include "dadosDengue.h"
#include <stdio.h>
#include <string.h>


// subfuncoes (servem a uma outra funcao)
void criarVetorCopia(dadosGerais *dados, int inicio, int fim, int tipo){
    int *pnt, i;
    for (i = inicio; i <= fim; i++){
        pnt = &dados->tabela[i].graves23 + (tipo-2);
        dados->vCopia[i] = *pnt;
    }
}
void combinar(dadosGerais *dados, int inicio, int meio, int fim){
    int i = inicio;
    int j = meio+1;
    int k = 0;
    dadosDengue aux[fim - inicio + 1];
    // inicio = 0 | meio = 1 | fim = 3
    while(i <= meio && j <= fim){
        if (especificCompare(dados, i, j)){
            aux[k++] = dados->tabela[i++];
        }
        else {
            aux[k++] = dados->tabela[j++];
        }
    }
        
    while(i <= meio){
        aux[k++] = dados->tabela[i++];
    }
    while(j <= fim){
        aux[k++] = dados->tabela[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++){
        dados->tabela[i] = aux[k];
    }
    if (dados->op.tipo > 1){
        criarVetorCopia(dados, inicio, fim, dados->op.tipo);
    }
}
int especificCompare(dadosGerais *dados, int i, int j){
    tipoEscolha op = dados->op;
    dadosDengue *tabela = dados->tabela;
    int *vCopia = dados->vCopia;

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
void mergeSort(dadosGerais *dados, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeSort(dados, inicio, meio);
        mergeSort(dados, meio+1, fim);
        combinar(dados, inicio, meio, fim);
    }
}
