/* MC102 Algoritmos e Programação de Computadores
 *  Laboratório 08: Superis Vincio Grandia
 *  Arquivo auxiliar: exemplo.c   
 *  Descrição:   Este arquivo contem exemplos de uso das funções fornecidas
 */

#include "lab08.h"
#include <math.h>

#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256

#define MY_PI 3.14159265358979323846

/* Esta função imprime a sequência de operações e polígonos */
void io_demo(){
	int    n[1];
	double p[MAX_OPERATIONS][2];
	char   s[MAX_OPERATIONS];
	
	int i;
	/* Lendo as operações */
	scan_svg(n,p,s);
	printf("Sequencia de operações:\n");
	for(i=0;i<n[0];++i){
		printf("%c ",s[i]);
		if(s[i]=='S'||s[i]=='T')
			printf("(%.1f , %.1f)\n",p[i][0],p[i][1]);
		else if(s[i]=='R')
			printf("(%.1f)\n",p[i][0]);
		else
			printf("\n");
	}
	/* Polígonos */
	printf("Polígonos lidos:\n");
	scan_svg(n,p,s);
	while(n[0]>=0){
		printf("[");
		for(i=0;i<n[0];++i)
			printf("(%.3f,%.3f)",p[i][0],p[i][1]);
		printf("] s:[%s]\n",s);
		scan_svg(n,p,s);
	}
	printf("\n");
}

/* Esta função imprime um arquivo SVG ignorando as operações */
void file_demo(){
	/* Variáveis para armazenar todas as operações */
	int    op_n[1];
	double op_p[MAX_OPERATIONS][2];
	char   op_s[MAX_OPERATIONS];
	/* Variáveis que armazenam um polígono */
	int    n[1];
	double p[MAX_POINTS][2];
	char   s[MAX_STYLE];
	
	/* Lendo as operações */
	scan_svg(op_n,op_p,op_s);
	/* Operações armazenadas em (op_n,op_p,op_s) */
	
	/* Polígonos */
	scan_svg(n,p,s);
	print_svg(n,p,s);
	while(n[0]>=0){
		scan_svg(n,p,s);
		/* Ignorando operações e copiando polígono original */
		print_svg(n,p,s);
	}
	close_svg();
}

int main(){
	int escolha = 1;
	
	/* Ative a linha abaixo para testar a outra função */
	/* escolha = 1; */
	
	if(escolha == 0){
		file_demo();
	}
	else{
		io_demo();
	}
	
	return 0;
}
