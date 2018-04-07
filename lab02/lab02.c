 /* MC102 - Turma O - Professor Julio López
    * Aluno: Gabriel Paschoal Stein - RA 197466
    *
    * Laboratório 02 - Encontrar o menor caminho de Dene para Altair.
    * Input: 11 distancias em inteiros.
    * Output: Caminho com menor distancia em inteiro.
*/

#include<stdio.h>

int main() {
    int a, b, c, d, e, f, g, h, i, j, k;
    int aej, aeik, adfj, adfik, adgk, bfj, bfik, bgk, chk; /*Caminhos possiveis*/
    int shortest_path; /*Caminho mais curto*/
    int six_mult_path; /* Caminho escolhendo o mais curto para próxima estrela*/

    scanf("%d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k);

    aej = a + e + j;
    aeik = a + e + i + k;
    adfj = a + d + f + j;
    adfik = a + d + f + i + k;
    adgk = a + d + g + k;
    bfj = b + f + j;
    bfik = b + f + i + k;
    bgk = b + g + k;
    chk = c + h + k;

    /* calcula caminho mais curto */
    if (aej < aeik)             /*compara 2 caminhos e atribui o menor ao caminho mais curto*/
        shortest_path = aej; 
    else
        shortest_path = aeik;
    if (adfj < shortest_path)   /* checa se o caminho escolhido é o menor caminho se sim atribui ele ao menor caminho, repetir até testar todos caminhos */
        shortest_path = adfj;
    if (adfik < shortest_path)
        shortest_path = adfik;
    if (adgk < shortest_path)
        shortest_path = adgk;
    if (bfj < shortest_path)
        shortest_path = bfj;
    if (bfik < shortest_path)
        shortest_path = bfik;
    if (bgk < shortest_path)
        shortest_path = bgk;
    if (chk < shortest_path)
        shortest_path = chk;

    /*calcula o caminho pelo metodo do trecho mais curto*/
    if (a < b && a < c){
        if (d < e){
            if (f < g){
                if (i < j)
                    six_mult_path = adfik;
                else
                    six_mult_path = adfj;
            }
            else
                six_mult_path = adgk;
        }
        else{
            if (i < j)
                six_mult_path = aeik;
            else
                six_mult_path = aej;
        }
    }
    else if (b < c){
        if (f < g){
            if (i < j)
                six_mult_path = bfik;
            else
                six_mult_path = bfj;
        }
        else
            six_mult_path = bgk;
    }
    else
        six_mult_path = chk;

    if ((six_mult_path % 6) == 0)   /*checa se o caminho é multiplo de 6, se sim menor caminho é zero*/
        shortest_path = 0;

    printf("%d\n", shortest_path);

    return 0;
}
