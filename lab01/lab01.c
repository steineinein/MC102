/* MC102 - Turma O - Professor Julio López
   * Aluno: Gabriel Paschoal Stein - RA 197466
   *
   * Laboratório 01
 */
#include <stdio.h>

int main(){

    int x1, x2, x3, x4, x5, x6, x7, x8;
    int c1, c2, c3, c4, c5, c6, c7, c8;
    int produto;

    scanf("%d %d %d %d %d %d %d %d", &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8);
    scanf("%d %d %d %d %d %d %d %d", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8);

    produto = c1*c2*c3*c4*c5*c6*c7*c8; /* Calcula o produto dos diacriticos para serem usado em outras partes do programa. */

    if (!(c4 == 2 || c4 == 9)){ /* Regra 1 */
        x1 = x1 + 3;
        x2 = x2 + 3;
        x3 = x3 + 3;
        x4 = x4 + 3;
        x5 = x5 + 3;
        x6 = x6 + 3;
        x7 = x7 + 3;
        x8 = x8 + 3;
    }

    if (c1 >= 11 && c1 <= 42){ /* Regra 2 */
        x7 = x7 + 8;
        x8 = x8 + 7;
    }

    if (!(produto % 2 == 0)) /* Regra 3, se alguma diacritico não for par o produto deles também não é par. */
        x1 = x1 + 2*c5;

    if ((c3 < 20 || c6 < 20) && !(c3 < 20 && c6 <20)){ /* Regra 4, verificado com um ou exclusivo. */
            x4 = x4 + 6;
            x5 = x5 + 6;
    }

    if (c8 != 3 && c8 >= c7) /* Regra 5 */
        x3 = x3 + c2;

    if ((produto % 5 == 0 && produto % 10 != 0) || produto == 30) /* Regra 6 */
        x6 = x6 + 1;

    if (c2 == c8 || c3 == c7) /* Regra 7 */
        x6 = x6 + 1;

    if (x1 >= 1 && x1 <= 26){
        x1 = x1 + 64;
        printf("%c",x1);
    }
    else if (x1 == 27)
    {
        x1 = 32;
        printf("%c", x1);
    }

    if (x2 >= 1 && x2 <= 26){
        x2 = x2 + 64;
        printf("%c",x2);
    }
    else if (x2 == 27){
        x2 = 32;
        printf("%c", x2);
    }

    if (x3 >= 1 && x3 <= 26){
        x3 = x3 + 64;
        printf("%c",x3);
    }
    else if (x3 == 27)    {
        x3 = 32;
        printf("%c", x3);
    }

    if (x4 >= 1 && x4 <= 26){
        x4 = x4 + 64;
        printf("%c",x4);
    }
    else if (x4 == 27)    {
        x4 = 32;
        printf("%c", x4);
    }

    if (x5 >= 1 && x5 <= 26){
        x5 = x5 + 64;
        printf("%c",x5);
    }
    else if (x5 == 27)
    {
        x5 = 32;
        printf("%c", x5);
    }

    if (x6 >= 1 && x6 <= 26){
        x6 = x6 + 64;
        printf("%c",x6);
    }
    else if (x6 == 27){
        x6 = 32;
        printf("%c", x6);
    }

    if (x7 >= 1 && x7 <= 26){
        x7 = x7 + 64;
        printf("%c",x7);
    }
    else if (x7 == 27){
        x7 = 32;
        printf("%c", x7);
    }

    if (x8 >= 1 && x8 <= 26){
        x8 = x8 + 64;
        printf("%c",x8);
    }
    else if (x8 == 27){
        x8 = 32;
        printf("%c", x8);
    }

    printf("\n");

    return 0;
}
