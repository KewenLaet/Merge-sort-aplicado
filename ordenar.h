#ifndef ORDENAR_H
#define ORDENAR_H

#include "dadosDengue.h"

// subfuncoes
void criarVetorCopia(dadosDengue *tabelaReg, int inicio, int fim, int tipo, int *vCopia);
int escificCompare(tipoEscolha op, dadosDengue *tabela, int *vCopia, int i, int j);
//void combinarChar(dadosDengue *tabela, int inicio, int meio, int fim);
//void combinarInt(dadosDengue *tabela, int *vCopia, int inicio, int meio, int fim);

// funcoes principais
void escolhaOrdernarChar(dadosDengue *tabelaReg, tipoEscolha op);
void escolhaOrdenarInt(dadosDengue *tabelaReg, tipoEscolha op);
void mergeSort(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int fim);
//void mergeChar(dadosDengue *tabela, int inicio, int fim);
//void mergeInt(dadosDengue *tabela, int *vCopia, int inicio, int fim);

#endif
