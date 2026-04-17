/*
O programa deve permitir:
- Ler os dados do arquivo.
- Escolher o tipo de ordenacao.
    UF alfabetica;
    Casos graves;
    Obitos;
    Diferenca(2023-2024);
- Aplicar Merge sort.
- Exibir os dados ordenados.
Objetivo final:
- Filtra por regiao para ordenar.
- Salvar resultados ordenados em arquivos separados.
- Criterio de ordenacao:
    UF; Graves_2023; Graves_2024; Moretes_2023; Mortes_2024; DIFF_graves; DIFF_mortes.
dengue.txt
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dadosDengue.h"
#include "ordenar.h"

int main (void){
    tipoEscolha op;

    dadosDengue *tabelaRegiao;

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

    tabelaRegiao = (dadosDengue *) calloc(op.qntUF, sizeof(dadosDengue));

    if (tabelaRegiao == NULL){
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

    lerDados(tabelaRegiao, op.path, op.qntUF);

    int vCopia[op.qntUF];
    criarVetorCopia(tabelaRegiao, 0, op.qntUF - 1, op.tipo, vCopia);
    mergeSort(tabelaRegiao, op, vCopia, 0, op.qntUF - 1);

    escreverDados(tabelaRegiao, op, op.qntUF);

    //exibirDados(eh so exibir, entao provavelmente so tabelaRegiao e tamanho deve dar, pelo menos no caso de exibir vetor));
    //pessoalmente acho melhor se voce exibir direto do arquivo, ja que dessa forma voce ja pega formatado da forma correta la tlg
    //decidido! exibe diretamente do arquivo (gato mandando joia)

    // lembrar de liberar memoria
    free(tabelaRegiao);

    printf("\n\nDigite Enter para sair...\n");
    while((getchar()) != '\n');
    getchar();
    return 0;
}
