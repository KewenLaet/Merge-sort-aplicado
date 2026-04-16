#ifndef ORDENAR_H
#define ORDENAR_H

#include "dadosDengue.h"

void escolhaOrdernarChar(dadosDengue *tabelaReg, tipoEscolha op);
void escolhaOrdenarInt(dadosDengue *tabelaReg, tipoEscolha op);
void criarVetorCopia(dadosDengue *tabela, tipoEscolha op, int *vCopia);
// insertion temporario ate terminar o codigo em volta do merge
void insertionSort(dadosDengue *tabelaReg, int tam);


#endif
