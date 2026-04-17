#ifndef ORDENAR_H
#define ORDENAR_H

#include "dadosDengue.h"

// subfuncoes
void criarVetorCopia(dadosDengue *tabelaReg, int inicio, int fim, int tipo, int *vCopia);
void combinar(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int meio, int fim);
int especificCompare(tipoEscolha op, dadosDengue *tabela, int *vCopia, int i, int j);

// funcoes principais
void mergeSort(dadosDengue *tabela, tipoEscolha op, int *vCopia, int inicio, int fim);

#endif
