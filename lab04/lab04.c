/* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 04 - Space Invaders 
 * Input: Dimensão 'n' do tabuleiro, cinco pares ordenados que representam as coordenadas das naves alienigenas e a posição horizontal k da nave mestre.
 * Output: Imprime os 10 primeiros estados do jogo. 
 * Imprime 10 matrizes 'n'x'n' dos simbolos ". "(vazio), "* "(nave alienigena), "X "(nave mestre) e "| "(tiro).
*/
 
#include <stdio.h>
 
int main(){

    int n, i1, j1, i2, j2, i3, j3, i4, j4, i5, j5, k; /* Inputs */
    int i, j, l, tiro, pos_morte; /* Variáveis necessárias */

    scanf ("%d %d %d %d %d %d %d %d %d %d %d %d", &n, &i1, &j1, &i2, &j2, &i3, &j3, &i4, &j4, &i5, &j5, &k); 
    tiro = n;

    /* Reliza l = 10 intereções do jogo */
    for (l = 1; l <= 10; ++l){
        /* Imprime o estado do jogo na tela, imprimindo cada elemento de uma linha e depois partindo para a próxima.
         * Onde i representa a linha atual e j representa a coluna atual.*/
        for (i = 1; i <= n; ++i){
            for (j = 1; j <= n; ++j){
                /* Checa o que deve ser imprimido na tela:
                 * naves alienigeas, nave mestre, tiro ou vazio */
                if (i == i1 && j == j1)
                    printf ("* ");
                else if (i == i2 && j == j2)
                    printf ("* ");
                else if (i == i3 && j == j3)
                    printf ("* ");
                else if (i == i4 && j == j4)
                    printf ("* ");
                else if (i == i5 && j == j5)
                    printf ("* ");
                else if (i == n && j == k)
                    printf ("X ");
                else if (i >= tiro && i < n && j == k)
                    printf ("| ");
                else printf (". ");
            }
            printf ("\n");
        }
        printf ("\n");
        /* avança o tiro uma quadra */
        tiro--;
        /* move as naves checando para não baterem nas paredes */
        if (l == 2 || l == 3 || l == 6 || l == 7){
            if (j1 > 1)
                j1--;
            if (j2 > 1)
                j2--;
            if (j3 > 1)
                j3--;
            if (j4 > 1)
                j4--;
            if (j5 > 1)
                j5--;
        }
        else{
            if (j1 < n)
                j1++;
            if (j2 < n)
                j2++;
            if (j3 < n)
                j3++;
            if (j4 < n)
                j4++;
            if (j5 < n)
                j5++;
        }
        /* Destroi as naves quando elas estão na mesma posição que o tiro e guarda a posição da nave que foi
         * destruida mais perto da nave mestre.*/
        pos_morte = 0;
        if (i1 >= tiro && j1 == k){
            pos_morte = i1;
            i1 = 0;
            j1 = 0;
        }
        if (i2 >= tiro && j2 == k){
            if (pos_morte < i2)
                pos_morte = i2;
            i2 = 0;
            j2 = 0;
        }
        if (i3 >= tiro && j3 == k){
            if (pos_morte < i3)
                pos_morte = i3;
            i3 = 0;
            j3 = 0;
        }
        if (i4 >= tiro && j4 == k){
            if (pos_morte < i4)
                pos_morte = i4;
            i4 = 0;
            j4 = 0;
        }
        if (i5 >= tiro && j5 == k){
            if (pos_morte < i5)
                pos_morte = i5;
            i5 = 0;
            j5 = 0;
        }
        /* Checa se alguma nave foi destruida e atualiza a posição do tiro.*/
        if (pos_morte != 0)
            tiro = pos_morte + 1;
    }
    return 0;
}
