/* MC102 - Turma O - Professor Julio López
 * Aluno: Gabriel Paschoal Stiein - RA 197466
 * 
 * Laboratório 00 - Soma de dois números
 * Entrada: dois inteiros
 * Saída: soma dos dois inteiros.
*/

#include <stdio.h>

int main()
{
    int numero1, numero2, resultado;

    scanf("%d %d", &numero1, &numero2);
    resultado = numero1 + numero2;
    printf("%d + %d = %d\n", numero1, numero2, resultado);

    return 0;
}
