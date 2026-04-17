#include "dadosDengue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerDados(dadosDengue *tabelaRegiao, char *filepath, int qntUF){
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        return;
    }

    int n = 0, Gr23, Ob23, Gr24, Ob24, DIFF_Gr, DIFF_Ob;
    char reg[15], UF[3];

    // possivelmente trocar o espaco por algum outro caractere como marcacao entre uma coluna e a outra, requeriria obviamente mudanca nos txt
    while(fscanf(fp, "%[^;];%d;%d;%d;%d;%d;%d", UF, &Gr23, &Ob23, &Gr24, &Ob24, &DIFF_Gr, &DIFF_Ob) == 7 && n < qntUF){
        strncpy(tabelaRegiao[n].regiao, reg, 14);
        tabelaRegiao[n].regiao[14] = '\0';
        strncpy(tabelaRegiao[n].UF, UF, 2);
        tabelaRegiao[n].UF[2] = '\0';
        tabelaRegiao[n].graves23 = Gr23;
        tabelaRegiao[n].obitos23 = Ob23;
        tabelaRegiao[n].graves24 = Gr24;
        tabelaRegiao[n].obitos24 = Ob24;
        tabelaRegiao[n].difGraves = DIFF_Gr;
        tabelaRegiao[n].difObitos = DIFF_Ob;
        n++;
    }

    fpclose(fp);
}
void escreverDados(dadosDengue *tabelaReg, tipoEscolha op){ //-> descricao no arquivo dadosDengue.h
    FILE *arq = fopen("dadosOrdenados.txt", "w");
    int i;
    for(i=0 ; i<qntUF ; i++){
        //No tipo que forem strings, passar o op escolhido pelo usuario no op.tipo
        fprintf(arq, tabelaReg[op.reg].regiao);
        (char *)25
    }
    //fprintf aqui -> abrir o fopen do txt vazio
    //tabelaReg[i].uf -> graves23 -> obitos23...
    //op.alguma coisa
    //
    fpclose(arq);
}
//void exibirDados(); -> descricao no arquivo dadosDengue.h

int pegarDadosDeReg(int reg, char *caminho){
    const int ufRegiao[]= { 4, 9, 7, 4, 3 };
    char const caminhoPt2[15][5]= { "dengueCentroOeste", "dengueNordeste", "dengueNorte", "dengueSudeste", "dengueSul" };

    strcpy(caminho, "./Arquivo das regiões/");
    strcat(caminho, caminhoPt2[reg]);

    return ufRegiao[reg-1];
}
