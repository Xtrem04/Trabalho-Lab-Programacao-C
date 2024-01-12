#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

#define VETOR_SIZE 6 //Tamanho dos vetores (Tem que ser par)
#define VALOR_MIN 8 //Valor minimo para o vetor
#define VALOR_MAX 29 //Valor maximo para o vetor

#include "Funcoes.h"

int main()
{
    int objetivo; //Variavel para selecionar que tipo de objetivo o usuario pretende selecionar
    int opcao; //Variavel para selecionar que operacao o usuario pretende selecionar
    int aleatorio; //Variavel para guardar o valor randomizado
    int Inicial[VETOR_SIZE]; //Vetor inicial dado pelo usuario
    int Secundario[VETOR_SIZE]; //Vetor secundario dado pelo usuario
    int A1[VETOR_SIZE]; //Vetor resultado dos objetivos basicos, operacao 1
    int A2[VETOR_SIZE]; //Vetor resultado dos objetivos avancados, operacao 1
    int B1[VETOR_SIZE / 2]; //Vetor resultado dos objetivos basicos, operacao 2
    int B2[VETOR_SIZE - 1]; //Vetor resultado dos objetivos avancados, operacao 2
    int C1[VETOR_SIZE][VETOR_SIZE]; //Matriz resultado dos objetivos basicos, operacao 3
    int C2[VETOR_SIZE][VETOR_SIZE]; //Matriz resultado dos objetivos avancados, operacao 3
    double D1[VETOR_SIZE / 2]; //Vetor resultado dos objetivos basicos, operacao 4
    int D2[VETOR_SIZE][VETOR_SIZE]; //Matriz resultado dos objetivos avancados, operacao 4
    bool ready = false; //Variavel para validar se uma operacao pode ser feita

    setlocale(LC_ALL, "Portuguese"); //Permite usar a biblioteca da linguagem portuguesa

    printf("Insira %d numeros inteiros entre %d e %d para serem elementos do vetor principal.\n\n", VETOR_SIZE, VALOR_MIN, VALOR_MAX);
    LerVetor(Inicial, VETOR_SIZE, "X"); //Funcao que le o vetor inicial
    printf("\n");
    printf("Vetor: ");
    EscreverVetor(Inicial, VETOR_SIZE, "X"); //Funcao que escreve o vetor inicial
    printf("\n\n");
    system("pause && cls");

    do
    {
        printf("----- Laboratórios de Programação -----\n\n");
        printf("1 - Objetivos Básicos\n");
        printf("2 - Objetivos Avançados\n");
        printf("3 - Sair\n\n");
        printf("Opção: ");
        scanf("%d", &objetivo);
        system("cls");

        switch (objetivo)
        {
            case 1:
            {
                printf("----- Laboratórios de Programação -----\n\n");
                printf("Vetor: ");
                EscreverVetor(Inicial, VETOR_SIZE, "X");
                printf("\n\n");
                printf("1 - Devolução do vetor ordenado por ordem crescente.\n");
                printf("2 - Devolução do vetor resultante do cálculo da soma da primeira metade dos elementos do vetor com os da segunda metade.\n");
                printf("3 - Construção de uma matriz %d por %d, em que cada linha é composta pelo vetor lido e por permutações dos seus valores\n", VETOR_SIZE, VETOR_SIZE);
                printf("4 - Cálculo do cosseno (cos) da segunda metade dos elementos do vetor.\n");
                printf("5 - Retorno de um elemento aleatório desse vetor\n");
                printf("6 - Devolução dos valores em posições múltiplas de três do vetor.\n");
                printf("7 - Ajuda.\n\n");
                printf("8 - Voltar ao menu principal.\n\n");
                printf("Opção: ");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao)
                {
                    case 1:
                    {
                        ClonarVetor(Inicial, A1);
                        OrdenarVetor(A1);
                        EscreverVetor(A1, VETOR_SIZE, "Y");
                        break;
                    }
                    case 2:
                    {
                        SomaMetadeVetor(Inicial, B1);
                        EscreverVetor(B1, VETOR_SIZE / 2, "Y");
                        break;
                    }
                    case 3:
                    {
                        PermutacaoMatriz(C1, Inicial);
                        EscreverMatriz(C1, "Y", 2);
                        break;
                    }
                    case 4:
                    {
                        CossenoVetor(Inicial, D1, "X", 3);
                        break;
                    }
                    case 5:
                    {
                        aleatorio = NumeroAleatorio(0, VETOR_SIZE - 1);
                        printf("A posição sorteada foi %d", aleatorio);
                        printf("\n\n");
                        printf("O valor da posição %d é %d", aleatorio, Inicial[aleatorio]);
                        break;
                    }
                    case 6:
                    {
                        PosicoesMultiplasVetor(Inicial, 3, "X");
                        break;
                    }
                    case 7:
                    {
                        printf("----- Ajuda -----\n\n");
                        printf("\n Este programa possibilita que sejam feitos calculos de algumas estatisticas\n e operacoes sobre %d valores inteiros de um vetor, esses valores inteiros\n sao pedidos ao utilizador no inicio do programa.", VETOR_SIZE);
                        printf("\n\nNota: Os valores pedidos devem estar compreendidos entre 8 e 29.\n");
                        printf("_________________________________________________________________\n");
                        printf("\n As funcionalidades do programa estao divididas entre Funcionalidades Basicas\n (acedivel com a tecla [1]) e Funcionalidades Avancadas (acedivel com a tecla [2])\n Para escolher uma das funcionalidades que o programa tem, basta escolher entre\n o tipo da funcionalidade (basica/avancada) e escolher um dos numeros indicados\n no terminal ([1-6], sendo a opcao [7] o menu de ajuda e [8] a opcao de voltar ao\n menu principal), depois pressione Enter para concluir a acao.");
                        break;
                    }
                    case 8:
                    {
                        break;
                    }
                    default:
                    {
                        printf("Opcao nao existe.");
                        break;
                    }
                }
                if (opcao != 8)
                {
                    printf("\n\n");
                    system("pause && cls");
                }
                break;
            }
            case 2:
            {
                printf("----- Laboratórios de Programação -----\n\n");
                EscreverVetor(Inicial, VETOR_SIZE, "Vetor");
                printf("\n\n");
                printf("1 - Leitura de um novo vetor, e devolução de um  vetor que  mistura  metade do primeiro vetor e metade do segundo.\n");
                printf("2 - Cálculo do mínimo múltiplo comum de cada dois números seguidos do vetor.\n");
                printf("3 - Geração  de  um  novo  vetor  1x%d   aleatório,  cálculo  e  devolução  da matriz %dx%d resultante do produto do vetor inicial com o novo vetor lido.\n", VETOR_SIZE, VETOR_SIZE, VETOR_SIZE);
                printf("4 - Cálculo e apresentação da matriz transposta \n");
                printf("5 - Ajuda.\n\n");
                printf("6 - Voltar ao menu principal.\n\n");
                printf("Opção: ");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao)
                {
                    case 1:
                    {
                        LerVetor(Secundario, VETOR_SIZE, "Y");
                        printf("\n");
                        EscreverVetor(Secundario, VETOR_SIZE, "Y");
                        Mistura2Vetores(Inicial, Secundario, A2);
                        printf("\n");
                        EscreverVetor(A2, VETOR_SIZE, "Z");
                        break;
                    }
                    case 2:
                    {
                        MinimoMultiploComumVetor(Inicial, B2, "X");
                        break;
                    }
                    case 3:
                    {
                        RandomVetor(Secundario);
                        EscreverVetor(Secundario, VETOR_SIZE, "Y");
                        ProdutoMatriz(Inicial, Secundario, C2);
                        printf("\n\n");
                        EscreverMatriz(C2, "Z", 3);
                        ready = true;
                        break;
                    }
                    case 4:
                    {
                        if (!ready)
                        {
                            printf("Ainda nao e possivel determinar a matriz neste momento.");
                            break;
                        }
                        TransporMatriz(C2, D2);
                        EscreverMatriz(D2, "Y", 3);
                        break;
                    }
                    case 5:
                    {
                        printf("----- Ajuda -----\n\n");
                        printf("\n Este programa possibilita que sejam feitos calculos de algumas estatisticas\n e operacoes sobre 20 valores inteiros de um vetor, esses valores inteiros\n sao pedidos ao utilizador no inicio do programa.");
                        printf("\n\nNota: Os valores pedidos devem estar compreendidos entre 8 e 29.\n");
                        printf("_________________________________________________________________\n");
                        printf("\n As funcionalidades do programa estao divididas entre Funcionalidades Basicas\n (acedivel com a tecla [1]) e Funcionalidades Avancadas (acedivel com a tecla [2])\n Para escolher uma das funcionalidades que o programa tem, basta escolher entre\n o tipo da funcionalidade (basica/avancada) e escolher um dos numeros indicados\n no terminal ([1-6], sendo a opcao [7] o menu de ajuda e [8] a opcao de voltar ao\n menu principal), depois pressione Enter para concluir a acao.");
                        break;
                    }
                    case 6:
                    {
                        break;
                    }
                    default:
                    {
                        printf("Opcao nao existe.");
                        break;
                    }
                }
                if (opcao != 6)
                {
                    printf("\n\n");
                    system("pause && cls");
                }
                break;
            }
            default:
            {
                system("cls");
            }
        }
    } while (objetivo != 3);

    return 0;
}