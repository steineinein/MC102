 /* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 11 - Gremlins
 * Input: Número de gremlins.
 * Output: Resposta se é possivel ter 42 gremlins na roda: "Sim" ou "Nao".
 */

#include <stdio.h>

int check42 (int n);
int mult_last2digits (int n);

int main(){
	int n, a;
	scanf ("%d", &n);
	a = check42(n);
	if (a)
		printf("Sim\n");
	else
		printf("Nao\n");
	return 0;
}

/* função para checar se é possivel ter exatamente 42 gremlins
 * retorna 0 se não e um inteiro >= 1 se sim */
int check42 (int n){
	int a;
	a = 0;
	/* para numeros menores que 42 é impossível ter 42 gremlins*/
	if (n >= 42){
		/* retorna 1 se é possivel chegar a 2 gremlins */
		if (n == 42){
			return 1;
		}
		/* testa a regra a) de forma recursiva */
		if (n % 2 == 0){
			a = a + check42 (n/2);
		}
		/* testa a regra b) de forma recursiva */
		if (n % 3 == 0 || n % 4 == 0){
			/* só testa se o nultiplo for diferente de 0, se não entra em um loop infinito */
			if (mult_last2digits(n) != 0)
				a = a + check42 (n - mult_last2digits (n));
		}
		/* testa a regra c) de forma recursiva */
		if (n % 5 == 0){
			a = a + check42 (n - 42);
		}
	}
	return a;
}

/* função para multiplicar os ultimos dois digítos de um inteiro */
int mult_last2digits (int n){
	int a, b;
	a = n % 10;
	b = (n / 10) % 10;
	return a*b;
}
