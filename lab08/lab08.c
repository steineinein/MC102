/* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 08 - Superis Vincio Grandia
 * Input: Uma imagem SVG que contém nos cometário iniciais uma série de operações (copiar, escalonar, transladar e rotacionar) a serem aplicadas na imagem.
 * Também contém as coordenadas de todos os polígnos da imagem.
 * Output: Uma imagem SVG com as coordenadas de novos polígnos resultados da aplicação das operações.
 */

 #include <math.h>
 #include "lab08.h"

#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256

#define MY_PI 3.14159265358979323846

double translation(double a, double t);
double scaling(double a, double s);
double rotation_x(double x, double y, double beta);
double rotation_y(double x, double y, double beta);
void do_operations(int n[], double p[][2], char s[]);


int main(){
	int n_operation [1];
	double p_operation [MAX_OPERATIONS][2];
	char s_operation [MAX_OPERATIONS];

	/* le commandos a ser executados */
	scan_svg(n_operation, p_operation, s_operation);
	/* executa as operações */
	do_operations(n_operation, p_operation, s_operation);
	return 0;
}

void do_operations(int n[], double p[][2], char s[]){
	int i, j, n_in[1], check_print;
	double p_in[MAX_POINTS][2], p_out[MAX_POINTS][2], x, y;
	char s_in[MAX_STYLE];

	scan_svg(n_in, p_in, s_in);

	while (n_in[0] >= 0){
		/* variavel para checar quando a impressão deve ser feita. */
		check_print = 0;
		for (i = 0; i < n[0]; ++i){
			/* checa se deve imprimir as modificações */
			if (s[i] == 'C' && check_print)
				/* como as operações só afetam os pontos do poligono, o número de pontos e a formatação de saída são os mesmos da entrada. */
				print_svg(n_in, p_out, s_in);
			/* checa se deve copiar os dados de entrada, copia os dados que serão modificados para o vetor de saída*/
			if (s[i] == 'C'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = p_in[j][0];
					p_out[j][1] = p_in[j][1];
				}
				check_print++;
			}
			/* checa se deve fazer a translação, se sim chama a função que a realiza */
			else if (s[i] == 'T'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = translation(p_out[j][0], p[i][0]);
					p_out[j][1] = translation(p_out[j][1], p[i][1]);
				}
			}
			/* checa se deve fazer o escalonamento, se sim chama a função que o realiza */
			else if (s[i] == 'S'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = scaling(p_out[j][0], p[i][0]);
					p_out[j][1] = scaling(p_out[j][1], p[i][1]);
				}
			}
			/* cecha se deve fazer rotação, se sim chama a função que a realiza */
			else if (s[i] == 'R'){
				for (j = 0; j < n_in[0]; ++j){
					x = p_out[j][0];
					y = p_out[j][1];
					p_out[j][0] = rotation_x(x, y, p[i][0]);
					p_out[j][1] = rotation_y(x, y, p[i][0]);
				}
			}
		}
		/* imprime a ultima copia */
		print_svg(n_in, p_out, s_in);
		/* escaneia o proximo poligono a ser trabalhado. */
		scan_svg(n_in, p_in, s_in);
	}
	/* fecha o arquivo svg depois que nao precisamos mais dele. */
	close_svg();
}

/* função para transladar o poligno, soma a cordenada x ou a cordenada y ao valor de translação respectivo*/
double translation(double a, double t){
	a = a + t;
	return a;
}

/* função para escalonar o poligno, multiplica a cordenada x ou a cordenada y pelo valor de escalonamento respectivo*/
double scaling(double a, double s){
	a = a * s;
	return a;
}

/* funções para rotazionar o poligno onde, o angulo de rotação é dados em graus:
* x' =  x * cos(angulo) - y * sin(angulo)
* y' =  x * sin(angulo) - y * cos(angulo)
*/
double rotation_x(double x, double y, double beta){
	x = x * cos (beta * MY_PI / 180.0) - y * sin (beta * MY_PI / 180.0);
	return x;
}

double rotation_y(double x, double y, double beta){
	y = x * sin (beta * MY_PI / 180.0) + y * cos (beta * MY_PI / 180.0);
	return y;
}