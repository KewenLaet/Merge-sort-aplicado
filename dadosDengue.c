#include "dadosDengue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void lerDados(dadosGerais *dados){
    FILE *fp = fopen(dados->op.path, "r");
    if (fp == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        return;
    }
 
    int n = 0, Gr23, Ob23, Gr24, Ob24, DIFF_Gr, DIFF_Ob;
    char UF[3];
 
    while(fscanf(fp, "%[^;];%d;%d;%d;%d;%d;%d%*c", UF, &Gr23, &Ob23, &Gr24, &Ob24, &DIFF_Gr, &DIFF_Ob) == 7 && n < dados->op.qntUF){
        strncpy(dados->tabela[n].UF, UF, 2);
        dados->tabela[n].UF[2] = '\0';
        dados->tabela[n].graves23 = Gr23;
        dados->tabela[n].obitos23 = Ob23;
        dados->tabela[n].graves24 = Gr24;
        dados->tabela[n].obitos24 = Ob24;
        dados->tabela[n].difGraves = DIFF_Gr;
        dados->tabela[n].difObitos = DIFF_Ob;
        n++;
    }
 
    fclose(fp);
}
 
void escreverDados(dadosGerais *dados){
    FILE *arq = fopen("dadosOrdenados.txt", "w");
    int i;
 
    for(i=0; i<dados->op.qntUF; i++){
        fprintf(arq, " | UF: %-12s | Graves 23: %-12d | Graves 24: %-12d | Obitos 23: %-12d | Obitos 24: %-12d | DifGraves: %-12d | DifObitos: %-12d\n",
         dados->tabela[i].UF, dados->tabela[i].graves23, dados->tabela[i].graves24,
         dados->tabela[i].obitos23, dados->tabela[i].obitos24,
         dados->tabela[i].difGraves, dados->tabela[i].difObitos);
    }
    fclose(arq);
}
 
void exibirDados(dadosGerais *dados){
    int i;

    printf("\n\nRegiao: %s\n", dados->NomeReg);
    for(i=0; i<dados->op.qntUF; i++){
        printf(" | UF: %-12s | Graves 23: %-12d | Graves 24: %-12d | Obitos 23: %-12d | Obitos 24: %-12d | DifGraves: %-12d | DifObitos: %-12d\n",
         dados->tabela[i].UF, dados->tabela[i].graves23, dados->tabela[i].graves24,
         dados->tabela[i].obitos23, dados->tabela[i].obitos24,
         dados->tabela[i].difGraves, dados->tabela[i].difObitos);
    }
}
 
int pegarDadosDeReg(int reg, char *caminho, char *nomeReg){
    const int ufRegiao[]= { 4, 9, 7, 4, 3 };
    const char caminhoPt2[5][30]= { "Centro-Oeste", "Nordeste", "Norte", "Sudeste", "Sul" };

    strcpy(caminho, "ArquivosReg/dengue");
    strcat(caminho, caminhoPt2[reg-1]);
    strcat(caminho, ".txt");

    strcpy(nomeReg, caminhoPt2[reg-1]);

    return ufRegiao[reg-1];
}
