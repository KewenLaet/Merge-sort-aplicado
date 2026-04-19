#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dadosDengue.h"
#include "ordenar.h"
 
int main (void){
    tipoEscolha op;

    dadosGerais *dados = (dadosGerais *) malloc(sizeof(dadosGerais));
    if (dados == NULL){
        printf("\nFalha na alocacao de memoria.");
        return 1;
    }
 
    do{
        printf("\nQual regiao gostaria de ordenar?");
        printf("\n[1] Centro-Oeste"
            "\n[2] Nordeste"
            "\n[3] Norte"
            "\n[4] Sudeste"
            "\n[5] Sul\n- ");
        scanf("%d", &op.reg);
    } while(op.reg < 1 || op.reg > 5);
 
    op.qntUF = pegarDadosDeReg(op.reg, op.path);
    strcpy(op.finalPath, "dadosOrdenados.txt");
 
    dados->tabela = (dadosDengue *) calloc(op.qntUF, sizeof(dadosDengue));
    if (dados->tabela == NULL){
        printf("\nFalha na alocacao de memoria.");
        return 1;
    }
 
    do{
        printf("\nEscolha o tipo de ordenacao: ");
        printf("\n[1] UF alfabetica"
                "\n[2] Casos graves 2023"
                "\n[3] Obitos por dengue 2023"
                "\n[4] Casos graves 2024"
                "\n[5] Obitos por dengue 2024"
                "\n[6] Diferenca de casos graves"
                "\n[7] Diferenca de obitos por dengue\n- ");
        scanf("%d", &op.tipo);
    } while(op.tipo < 1 || op.tipo > 7);
 
    do{
        printf("\nComo sera ordenado?");
        printf("\n[1] Crescente"
                "\n[2] Decrescente\n- ");
        scanf("%d", &op.modo);
    } while(op.modo < 1 || op.modo > 2);
 
    dados->op = op;
 
    lerDados(dados, op.path, op.qntUF);
 
    dados->vCopia = (int *) calloc(op.qntUF, sizeof(int));
    if (dados->vCopia == NULL){
        printf("\nFalha na alocacao de memoria.");
        return 1;
    }
 
    criarVetorCopia(dados, 0, op.qntUF - 1, op.tipo);
    mergeSort(dados, 0, op.qntUF - 1);
    escreverDados(dados, op.qntUF);
    exibirDados(dados->tabela, op.qntUF);
 
    free(dados->vCopia);
    free(dados->tabela);
    free(dados);
 
    printf("\n\nDigite Enter para sair...\n");
    while((getchar()) != '\n');
    getchar();
    return 0;
}
