	/* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 07 - Hipótese de Sapir–Whorf
 * Input: Número de frases no texto, texto a ser tratado, número de palavras de busca e as palavras a serem buscadas.
 * Output: A relação em porcentagem das palavras de busca com os marcadores temporais de maior frequência. Todas as palavras presentes no texto
 * e número de vezes que essas palavras ocorrem.
*/

 #include <stdio.h>
 #include "lab07.h"
 #include <string.h>

int verifica_palavraBusca(char busca[][21], char palavra[], int nPalavras);
int checa_existe(char palavra[][21], char word[], int indice);
int maior_num(int a, int b);

int main(void){

	int nFrase, nPalavras, i, j, k, totalPalavrasDif, indice, contaPalavra[250] = {0}, totalPalavrasFrase, maior, relOcorr;
	int ocorrenciasMarc[50][N_MARCADORES] = {{0}}, ocorrenciasPalvra[50][10] = {{0}}, total[10][12] = {{0}};
	char text[50][251], palavrasBusca[10][21], palavras[250][21] = {{'\0'}}, word[21], palavrasFrase[125][21] = {{'\0'}};
	char marcadores[N_MARCADORES][TAM_MARCADORES] = MARCADORES;

	scanf("%d ", &nFrase);

	for (i = 0; i < nFrase; ++i){
		scanf("%[^\n]%*c", text[i]);
		minusculas (text[i]);
	}

	scanf("%d%*c", &nPalavras);

	for (i = 0; i < nPalavras; ++i){
		scanf("%[^\n]%*c", palavrasBusca[i]);
		minusculas (palavrasBusca[i]);
	}

	totalPalavrasDif = 0;
	for (i = 0; i < nFrase; ++i){
		indice = 0;

		totalPalavrasFrase = 0;
		while (indice >= 0){
			indice =  proxima_palavra(text[i], word, indice);
			j = verifica_marcador(marcadores, word);
/*			printf("i=%d j=%d\n", i, j);*/
			if (j >= 0)
				ocorrenciasMarc[i][j] = 1;
			j = verifica_palavraBusca(palavrasBusca, word, nPalavras);
			if (j >= 0)
				ocorrenciasPalvra[i][j] = 1;
/*checa se a palavra já existe na frase e monta um vetor e palavras unicas da frase*/
			k = checa_existe(palavrasFrase, word, totalPalavrasFrase);
			if(k < 0){
				strcpy(palavrasFrase[totalPalavrasFrase], word);
				totalPalavrasFrase++;
			}

		}
/*checa se as palvras unicas da frase já existem no vetor de palavras unicas do texto, se não existem as adiciona ao vetor e incrementa sua quantidade
e caso existam só incrementa a quantidade */
		for (j = 0; j < totalPalavrasFrase; ++j){
			k = checa_existe(palavras, palavrasFrase[j], totalPalavrasDif + j);
			if(k < 0){
				strcpy(palavras[totalPalavrasDif], palavrasFrase[j]);
				contaPalavra[totalPalavrasDif]++;
				totalPalavrasDif++;
			}
			else
				contaPalavra[k]++;
			strcpy(palavrasFrase[j], "\0");
		}
	}
	
	for (j = 0; j < nPalavras; ++j){
		for (i = 0; i < nFrase; ++i){
			total[j][11] = total[j][11] + ocorrenciasPalvra[i][j];
			for (k = 0; k < N_MARCADORES; ++k){
				total[j][k] = total[j][k] + ocorrenciasPalvra[i][j] * ocorrenciasMarc[i][k];
			}
		}
	}

	for (i = 0; i < nPalavras; ++i)	{
		maior = total[i][0];
		for (j = 1; j < 11; ++j){
			maior = maior_num(total[i][j],maior);
		}
		if (maior == 0)
			printf("<%s> nao se relacionou com nenhum marcador temporal.\n", palavrasBusca[i]);
		else{
			for (j = 0; j < 11; ++j){
				if (total[i][j] ==  maior){
					relOcorr = total[i][j]*100/total[i][11];
					printf("<%s> se relaciona com <%s> em %d %% das ocorrencias.\n", palavrasBusca[i], marcadores[j], relOcorr);
				}
			}
		}
	}



	for (i = 0; i < totalPalavrasDif; ++i)
		printf("%s ", palavras[i]);
	printf("\n");
	for (i = 0; i < totalPalavrasDif; ++i)
		printf("%d ", contaPalavra[i]);
	printf("\n");
	return 0;
}

/* Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int proxima_palavra(char frase[], char palavra[], int inicio){
	int i, j;
	for (i = inicio, j = 0; (frase[i] >= 'a' && frase[i] <= 'z'); ++i)
		palavra[j++] = frase[i];
	palavra[j] = '\0';
	while ((frase[i] < 'a' || frase[i] > 'z') && frase[i] != '\0')
		i ++;
	if (frase[i] == '\0')
		i = -1;
	return (i);
}


/* Objetivo: verifica se palavra de entrada é um marcador temporal.
 *
 * Entrada: - recebe a matriz de marcadores temporais marcVetor;
 *          - e a palavra a ser analisada palavra.
 * Saida:   Se a palavra for um marcador, devolve o índice correspondente em marcVetor, senão devolve -1
 */
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]){
	int i, b;
	b = -1;
	for (i = 0; i < N_MARCADORES; ++i){
		if (strcmp(marcVetor[i], palavra) == 0)
			b = i;
	}
	return b;
}

/* Objetivo: verifica se palavra de entrada é uma palavra de busca.
 *
 * Entrada: - recebe a matriz de palavras de busca;
 *          - e a palavra a ser analisada palavra.
 * Saida:   Se a palavra for uma palavra de bbusca, devolve o índice correspondente, senão devolve -1
 */
int verifica_palavraBusca(char busca[][21], char palavra[], int nPalavras){
	int i, b;
	b = -1;
	for (i = 0; i < nPalavras; ++i){
		if (strcmp(busca[i], palavra) == 0)
			b = i;
	}
	return b;
}

/* Objetivo: verifica se palavra de entrada existe no vetor de palavras.
 *
 * Entrada: - recebe uma string com as palvras;
 *          - a palavra a ser analisada palavra.
 *			- indice da última palavra existem no vetor de palavras
 * Saida:   Se a palavra for uma palavra de existe, devolve o índice correspondente, senão devolve -1
 */
int checa_existe(char palavras[][21], char palavra[], int indice){
	int i, b;
	b = - 1;
	for (i = 0; i < indice + 1; ++i){
		if (strcmp(palavras[i], palavra) == 0)
			b = i;
	}
	return b;
}

/* Objetivo: verifica se um número é maior que o outro.
 *
 * Entrada: - recebe 2 inteiros;
 * Saida:  	Devolve "a" se "a" for maior que "b", devolve "b" caso contrário.
 */
int maior_num(int a, int b){
	int aux;
	if (a > b)
		aux = a;
	else
		aux = b;
	return aux;
}
