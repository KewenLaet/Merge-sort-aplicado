#ifndef ORDENAR_H
#define ORDENAR_H

#include "dadosDengue.h"

// subfuncoes
void criarVetorCopia(dadosGerais *dados, int inicio, int fim, int tipo);
void combinar(dadosGerais *dados, int inicio, int meio, int fim);
int especificCompare(dadosGerais *dados, int i, int j);

// funcoes principais
void mergeSort(dadosGerais *dados, int inicio, int fim);

#endif
