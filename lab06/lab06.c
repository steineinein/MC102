/* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 06 - It's me, Mario!
 * Input: Indentifacor do formato de imagem, a largura e altura da matriz de pixels que forman a imagem(mapa) e uma
 * matriz com H linhas e W colunas que contém 0's ou 1's que formaram a imagem.
 * Output: Imprime o número de ilhas. 
*/

#include <stdio.h>

int main(){
    /* Declaração das variáveis. */
	char a,b;
	int w, h, map[300][300];
	int earth[300][300], check[180000] = {0}, end, i, j, count, m, n, k, l;

    /* Recebe os inputs e verifica se está no formato correto. */
	scanf("%c%c %d %d",&a,&b,&w,&h);
	if(a == 'P' && b == '1'){
		count = end = 0;
        /* Recebe o mapa e inicializa o mapa auxilar que marca que pedaço da ilha já foi lido. */
		for (i = 0; i < h; ++i)
			for (j = 0; j < w; ++j){
				scanf ("%d", &map[i][j]);
				earth[i][j] = 0;
			}
        /* Varre todo o mapa. */
		for (i = 0; i < h; ++i)
			for (j = 0; j < w; ++j){
                /* Verifica se é terra ou água e e se esse trecho já foi lido ou não. */
				if (!earth[i][j] && map[i][j]){
                    /* Se o trecho ainda não foi lido e é terra incrementa o contador e adiciona o endereço atual 
                    para a pilha. Marca onde a pilha termina. */
					count++;
					check[end] = i;
					check[end + 1] = j;
					end = end + 2;
                    /* Executa enquanto a pilha houve elementos na pilha. */
                    while (end > 0){
                        /* Remove o último elemento. */
                        end = end - 2;
                        m = check[end];
                        n = check[end + 1];
                        /* Checa se ele não foi lido e se é terra. */
                        if (!earth[m][n] && map[m][n]){
                            /* Se ele não foi lido e se é terra, marca-lo ele como lido. */
                            earth[m][n] = 1;
                            /* Checa todos elementos envolta dele. */
                            for(k = - 1; k < 2; ++k)
                                for (l = - 1; l < 2; ++l){
                                    /* Checa se não sai das margens do mapa */
                                    if (m + k >= 0 && m + k < h && n + l >= 0 && n + l < w)
                                        /* Checa se os elementos em volta não foram lidos e se são terra. */
                                        if (map[m + k][n + l] && !earth[m + k][n + l]){
                                            /* Se não foram lidos e se são terra adiciona-los para pilha */
                                            check [end] = m + k;
                                            check [end + 1] = n + l;
                                            end = end + 2;
                                        }
                                }
                            }
                        }
                    }
                }
		printf("%d\n", count);
	}
    return 0;
}