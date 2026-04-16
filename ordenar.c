#include "ordenar.h"
#include "dadosDengue.h"
#include <stdio.h>
#include <string.h>

// funcoes auxiliares (geralmente genéricas, atuam onde for necessario)


// subfuncoes (servem a uma outra funcao)
void criarVetorCopia(dadosDengue *tabelaReg, tipoEscolha op, int *vCopia){
    int i;

// O unico jeito de sumir com esse switch case que eu pensei foi usando algo como "vCopia[i] = tabelaReg[i].(&graves23 + 4)"
// 4 sendo pro endereco de memoria de um inteiro ser somado a quantidade de vezes necessaria pra escolher especificamente o que eu quero, nem sei se faz sentido...

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
/*
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

    criarVetorCopia(tabelaReg, op, vCopia);

    //aplicar merge sort com as alteracoes especificas do metodo int na comparacao e troca
    //mergeInt(tabela, vCopia, 0, op.qntUF - 1);
}
void mergeChar(dadosDengue *tabela, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeChar(tabela, inicio, meio);
        mergeChar(tabela, meio+1, fim);
        combinarChar(tabela, inicio, meio, fim);
    }
}
/*
void mergeInt(dadosDengue *tabela, int *vCopia, int inicio, int fim){
    if (inicio < fim){
        int meio = inicio + (fim - inicio)/2;
        mergeInt(tabela, vCopia, inicio, meio);
        mergeInt(tabela, vCopia, meio+1, fim);
        combinarInt(tabela, vCopia, inicio, meio, fim);
    }
}
*/
