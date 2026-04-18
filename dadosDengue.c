#include "dadosDengue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lerDados(dadosGerais *dados, char *filepath, int qntUF){
    FILE *fp = fopen(filepath, "r");
    if (fp == NULL){
        printf("\nERRO AO ABRIR ARQUIVO!\n");
        return;
    }

    int n = 0, Gr23, Ob23, Gr24, Ob24, DIFF_Gr, DIFF_Ob;
    char UF[3];

    while(fscanf(fp, "%[^;];%d;%d;%d;%d;%d;%d%*c", UF, &Gr23, &Ob23, &Gr24, &Ob24, &DIFF_Gr, &DIFF_Ob) == 7 && n < qntUF){
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
void escreverDados(dadosGerais *dados, int qntUF){ //-> descricao no arquivo dadosDengue.h
    FILE *arq = fopen("dadosOrdenados.txt", "w");
    int i;

    //fprintf(arq, "Regiao: %s", tabelaReg[op.reg].regiao); criar uma funcao que troca o numero da regiao por uma string e devolve aqui

    for(i=0 ; i<qntUF ; i++){
        //No tipo que forem strings, passar o op escolhido pelo usuario no op.tipo
        fprintf(arq, " | UF: %s | Graves 23: %d | Graves 24: %d | Obitos 23: %d | Obitos 24: %d | DifGraves: %d | DifObitos: %d\n",
         dados->tabela[i].UF, dados->tabela[i].graves23, dados->tabela[i].graves24,
         dados->tabela[i].obitos23, dados->tabela[i].obitos24,
         dados->tabela[i].difGraves, dados->tabela[i].difObitos);// lembra de fazer um trem tipo isso = %-12s pra exibir de forma padrao
        //(char *)25 <-> cast
    }
    //fprintf aqui -> abrir o fopen do txt vazio
    //tabelaReg[i].uf -> graves23 -> obitos23...
    fclose(arq);
}
/*void exibirDados(dadosDengue *tabelaReg, tipoEscolha op, int qntUF){ //-> descricao no arquivo dadosDengue.h


}*/
int pegarDadosDeReg(int reg, char *caminho){
    const int ufRegiao[]= { 4, 9, 7, 4, 3 };
    const char caminhoPt2[5][30]= { "dengueCentroOeste.txt", "dengueNordeste.txt", "dengueNorte.txt", "dengueSudeste.txt", "dengueSul.txt" };

    strcpy(caminho, "ArquivosReg/");
    strcat(caminho, caminhoPt2[reg-1]);

    return ufRegiao[reg-1];
}
