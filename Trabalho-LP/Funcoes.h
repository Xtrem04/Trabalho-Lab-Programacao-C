void LerVetor(int X[], int size, char* nome) //Funcao que le um vetor
{
    int i, n;

    for (i = 0; i < size; i++) //Ciclo que percorre o vetor inteiro
    {
        printf("%s[%d]: ", nome, i); //Pede o valor para cada posicao do vetor
        scanf("%d", &n);
        if (n < VALOR_MIN || n > VALOR_MAX) //Verifica se o valor nao e valido
        {
            printf("ERRO: Valor invalido!\n"); //Indica que o valor nao e valido
            i--; //Regressa ao valor anterior
            continue; //Ignora as iteracoes seguintes do ciclo
        }
        X[i] = n; //Guarda o valor no vetor
    }
}

void EscreverVetor(int X[], int size, char* nome) //Funcao que escreve um vetor
{
	int i;
	
    printf("%s = [", nome); //Escreve o nome do vetor
    for (i = 0; i < size - 1; i++) //Ciclo que percorre o vetor inteiro ate a penultima
    {
        printf("%d, ", X[i]); //Escreve o valor para cada posicao do vetor exceto a ultima
    }
    printf("%d]", X[size - 1]); //Escreve a ultima posicao do vetor
}

void ClonarVetor(int X[], int Y[]) //Funcao que clona um vetor em outro
{
	int i;
	
    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre o vetor inteiro
    {
        Y[i] = X[i]; //Iguala todos os valores do primeiro vetor ao segundo
    }
}

void OrdenarVetor(int X[]) //Funcao que ordena um vetor
{
    int aux, i, j;

    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre o vetor inteiro
    {
        for (j = 0; j < VETOR_SIZE - 1; j++) //Ciclo que percorre o vetor inteiro ate a penultima
        {
            if (X[j] > X[j + 1]) // Verifica se o valor anterior e maior que o posterior
            {
                aux = X[j]; //Guarda o valor maior numa variavel usada como auxiliar
                X[j] = X[j + 1]; //Iguala o maior valor ao menor
                X[j + 1] = aux; //Iguala o menor valor ao maior que estava guardado na variavel usada como auxiliar
            }
        }
    }
}

void SomaMetadeVetor(int X[], int Y[]) //Funcao que soma a primeira metade do vetor com a segunda metade
{
	int i;
	
    for (i = 0; i < VETOR_SIZE / 2; i++) //Vetor que percorre o vetor inteiro
    {
        Y[i] = X[i] + X[VETOR_SIZE / 2 + i]; //Guarda no vetor a soma da primera com a segunda metade do outro vetor
    }
}

void PermutacaoMatriz(int X[][VETOR_SIZE], int Y[]) //Funcao que calcula a matriz das permutacoes de um vetor
{
	int i, j;
    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre as linhas da matriz
    {
        for (j = 0; j < VETOR_SIZE - i; j++) //Ciclo que percorre as colunas da matriz desde o inicio ate ao numero da linha atual
        {
            X[i][j] = Y[i + j]; //Guarda o valor do vetor da posicao resultante da soma da linha e coluna atual na matriz na coluna atual
        }
        for (j = 0; j < i; j++) //Ciclo que percorre as colunas da matriz desde o numero da linha atual ate ao final
        {
            X[i][VETOR_SIZE - i + j] = Y[j]; //Guarda o valor do vetor da posicao da coluna atual na matriz na coluna resultante da diferenca entre o tamanho do vetor e a soma linha com a coluna atual
        }
    }
}

void CossenoVetor(int X[], double Y[], char* nome, int n) //Funcao que calcula o cosseno da segunda metade de um vetor
{
	int i;
	
    for (i = 0; i < VETOR_SIZE / 2 - 1; i++) //Ciclo que percorre o vetor inteiro ate a penultima
    {
        Y[i] = cos(X[VETOR_SIZE / 2 + i]); //Guarda o valor do cosseno de cada posicao da segunda metade de um vetor em outro
        printf("%s[%d]: cos(%d) = %.*lf\n", nome, VETOR_SIZE / 2 + i, X[VETOR_SIZE / 2 + i], n, Y[i]); //Mostra o resultado de cada valor calculado
    }
    Y[VETOR_SIZE / 2 - 1] = cos(X[VETOR_SIZE - 1]); //Guarda o valor do cosseno da ultima posicao da segunda metade de um vetor em outro
    printf("%s[%d]: cos(%d) = %.*lf", nome, VETOR_SIZE - 1, X[VETOR_SIZE - 1], n, Y[VETOR_SIZE / 2 - 1]); //Mostra o resultado do ultimo valor calculado
}

int NumeroAleatorio(int menor, int maior) //Funcao que devolve um valor aleatorio
{
    int Number, aux;

    if (menor > maior) //Verifica se o primeiro valor e maior que o segundo valor
    {
        aux = menor; //Guarda o valor maior numa variavel usada como auxiliar
        menor = maior; //Iguala o maior valor ao menor
        maior = aux; //Iguala o menor valor ao maior que estava guardado na variavel usada como auxiliar
    }

    Number = (rand() % (maior - menor + 1)) + menor; //Gera um valor aleatorio entre o 2 numeros

    return Number; //Devolve o valor gerado
}

void PosicoesMultiplasVetor(int X[], int n, char* nome) //Funcao que mostra os valores de um vetor nas posicoes multiplas de um dado inteiro
{
	int i;
	
    for (i = n; i < VETOR_SIZE - n; i+=n) //Ciclo for que comeca num dado inteiro ate ao penultimo 
    {
        printf("%s[%d]: %d\n", nome, i, X[i]);
    }
    //printf(VETOR_SIZE % n > n / 2.0 ? "%s[%d]: %d" : "%s[%d]: %d", nome, VETOR_SIZE / n * n - n, X[VETOR_SIZE / n * n - n], nome, VETOR_SIZE / n * n, X[VETOR_SIZE / n * n]);
    printf("%s[%d]: %d", nome, (VETOR_SIZE - 1) / n * n, X[(VETOR_SIZE - 1) / n * n]);
}

void Mistura2Vetores(int X[], int Y[], int Z[])
{
	int i;
	
    for (i = 0; i < VETOR_SIZE; i++)
    {
        Z[i] = i < VETOR_SIZE / 2 ? X[i] : Y[i];
    }
}

void MinimoMultiploComumVetor(int X[], int Y[], char* nome)
{
    int maior, menor, i, j;

    for (i = 0; i < VETOR_SIZE - 2; i++) //Ciclo for que percorre o vetor ate a antepenultima posicao
    {
        maior = X[i] > X[i + 1] ? X[i] : X[i + 1]; //Iguala a variavel maior ao maior elemento a comparar
        menor = X[i] > X[i + 1] ? X[i + 1] : X[i]; //Iguala a variavel menor ao menor elemento a comparar
        for (j = 1; j <= maior; j++) //Ciclo for que comeca em 1 e vai ate ao maior dos numeros a calcular o MMC
        {
            if (((menor * j) % maior) == 0) //Verifica se algum dos multiplos do menor e o minimo multiplo comum dos 2
            {
                Y[i] = menor * j; //Guarda o minimo mulitplo comum encontrado num novo vetor
                printf("MMC(%s[%d] e %s[%d]) = MMC(%d e %d) = %d\n", nome, i, nome, i + 1, X[i], X[i + 1], Y[i]); //Escreve o valor do minimo multiplo comum de cada dois valores seguidos no ecra ate ao penultimo
                break; //Sai fora do ciclo for
            }
        }
    }
    maior = X[VETOR_SIZE - 2] > X[VETOR_SIZE - 1] ? X[VETOR_SIZE - 2] : X[VETOR_SIZE - 1]; //Iguala a variavel maior ao maior elemento a comparar
    menor = X[VETOR_SIZE - 2] > X[VETOR_SIZE - 1] ? X[VETOR_SIZE - 1] : X[VETOR_SIZE - 2]; //Iguala a variavel menor ao menor elemento a comparar
    for (j = 1; j <= maior; j++) //Ciclo for que comeca em 1 e vai ate ao maior dos numeros a calcular o MMC
    {
        if (((menor * j) % maior) == 0) //Verifica se algum dos multiplos do menor e o minimo multiplo comum dos 2
        {
            Y[VETOR_SIZE - 2] = menor * j; //Guarda o minimo mulitplo comum encontrado num novo vetor
            printf("MMC(%s[%d] e %s[%d]) = MMC(%d e %d) = %d", nome, VETOR_SIZE - 2, nome, VETOR_SIZE - 1, X[VETOR_SIZE - 2], X[VETOR_SIZE - 1], Y[VETOR_SIZE - 2]); //Escreve o ultimo valor do minimo multiplo comum de cada dois valores seguidos no ecra
            break; //Sai fora do ciclo for
        }
    }
}

void TransporMatriz(int X[][VETOR_SIZE], int Y[][VETOR_SIZE]) //Funcao que transpoe uma dada matriz em uma nova
{
	int i, j;
	
    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre as linhas da matriz
    {
        for (j = 0; j < VETOR_SIZE; j++) //Ciclo que percorre as colunas da matriz
        {
            Y[i][j] = X[j][i]; //Transpoe os valores da matriz
        }
    }
}


void RandomVetor(int X[]) //Funcao que gera um vetor aleatorio
{
	int i;
	
    srand((unsigned)time(NULL)); //Gera uma nova combinacao de valores aleatorios que altera conforme o tempo
    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre o vetor inteiro
    {
        X[i] = NumeroAleatorio(VALOR_MIN, VALOR_MAX); //Guarda o valor que retorna da funcao no vetor
    }
}

void ProdutoMatriz(int X[], int Y[], int Z[][VETOR_SIZE]) //Funcao que calcula a matriz do produto de 2 vetores
{
	int i, j;
	
    for (i = 0; i < VETOR_SIZE; i++) //Ciclo que percorre as linhas da matriz
    {
        for (j = 0; j < VETOR_SIZE; j++) //Ciclo que percorre as colunas da matriz
        {
            Z[i][j] = X[i] * Y[j]; //Guarda o valor do produto entre o valor de cada posicao de cada linha de um vetor com cada posicao de cada coluna do outro vetor na matriz
        }
    }
}

void EscreverMatriz(int X[][VETOR_SIZE], char* nome, int alg) //Funcao que escreve uma matriz
{
	int i, j;
	
    printf("%s:\n", nome); //Escreve o nome da matriz
    for (i = 0; i < VETOR_SIZE - 1; i++) //Ciclo que percorre as linhas da matriz
    {
        for (j = 0; j < VETOR_SIZE - 1; j++) //Ciclo que percorre as colunas da matriz ate a penultima
        {
            printf("%0*d  ", alg, X[i][j]); //Escreve o valor para cada posicao de cada linha da matriz ate a penultima coluna com numero fixo de algarismos
        }
        printf("%0*d\n", alg, X[i][VETOR_SIZE - 1]); //Escreve o ultimo valor para cada posicao de cada linha da matriz com numero fixo de algarismos
    }
    for (j = 0; j < VETOR_SIZE - 1; j++)
    {
        printf("%0*d  ", alg, X[VETOR_SIZE - 1][j]);
    }
    printf("%0*d", alg, X[VETOR_SIZE - 1][VETOR_SIZE - 1]);
}
