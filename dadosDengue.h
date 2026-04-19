#ifndef DADOSDENGUE_H
#define DADOSDENGUE_H

typedef struct dados{
    char UF[3];
    int graves23;
    int obitos23;
    int graves24;
    int obitos24;
    int difGraves;
    int difObitos;
}dadosDengue;

typedef struct escolhas{
    int tipo;
    int modo;
    int reg;
    int qntUF;
    char path[55];
    char finalPath[22];
}tipoEscolha;

typedef struct dadosGerais{
    dadosDengue *tabela;
    tipoEscolha op;
    int *vCopia;
}dadosGerais;


void lerDados(dadosGerais *dados, char *filepath, int qntUF);
void escreverDados(dadosGerais *dados, int qntUF); //-> escrever os dados do vetor de volta no arquivo dadosOrdenados.txt
void exibirDados(dadosDengue *dados, int qntUF); //-> pode ser feito lendo o proprio vetor struct ou lendo o arquivo diretamente
int pegarDadosDeReg(int reg, char *caminho);


#endif
