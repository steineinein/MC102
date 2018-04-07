/* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 08 - 
 * Input: 
 * Output: 
 */

 #include <math.h>
 #include "lab08.h"

#define MAX_POINTS      500
#define MAX_OPERATIONS  60000
#define MAX_STYLE       256

#define MY_PI 3.14159265358979323846

double translation(double a, double t);
double scaling(double a, double s);
double rotation();
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
	double p_in[MAX_POINTS][2], p_out[MAX_POINTS][2];
	char s_in[MAX_STYLE];

	scan_svg(n_in, p_in, s_in);
	while (n_in >= 0){
		check_print = 0;
		for (i = 0; i < n[0]; ++i){
			if (s[i] == 'C' && check_print)
				/* como as operações só afetam os pontos do poligono, o número de pontos e a formatação de saída são os mesmos da entrada. */
				print_svg(n_in, p_out, s_in);
			if (s[i] == 'C'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = p_in[j][0];
					p_out[j][1] = p_in[j][1];
				}
				check_print++;
			}
			else if (s[i] == 'T'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = translation(p_out[j][0], p[j][0]);
					p_out[j][1] = translation(p_out[j][1], p[j][1]);;
				}
			}
			else if (s[i] == 'S'){
				for (j = 0; j < n_in[0]; ++j){
					p_out[j][0] = scaling(p_out[j][0], p[j][0]);
					p_out[j][1] = scaling(p_out[j][1], p[j][1]);;
				}
			}
			else if (s[i] == 'R'){

			}
		}
		scan_svg(n_in, p_in, s_in);
	}

	close_svg();
}

double translation(double a, double t){
	a = a + t;
	return a;
}

double scaling(double a, double s){
	a = a * s;
	return a;
}

