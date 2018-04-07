  /* MC102 - Turma O - Professor Julio López
     * Gabriel Paschoal Stein - RA 197466
     *
     * Laboratório 03 - Calcular de que forma entregaras joias ao cliente.
     * Input: segundo menor valor das joias, menor valor faltante, segundo menor valor faltante,
     * valor total da joias.
     * Output: A forma que as joias são entregues, sua quantidade e seu valor.
 */
 
#include <stdio.h>

int main(){

    int joia2, falta1, falta2;
    int quociente,falta_check, n_joia;
    unsigned int valor_joia, valor_total, sum_check;

    sum_check = n_joia = 0;
    
    scanf("%d %d %d %u", &joia2, &falta1, &falta2, &valor_total);
    
    /* Calcula qual é o maior valor possível necessário das joias. Calcula a maior potência que é menor que o valor total e menor que GR$ 4.000.000.000*/
    valor_joia = 1;
    quociente = valor_total / joia2;
    while(quociente != 0 && valor_joia * joia2 <= 4000000000){
        quociente = quociente / joia2;
        valor_joia = valor_joia * joia2;
    }

    /* Executa um loop até que a soma das joias seja igual ao valor pedido.*/
    while(sum_check != valor_total){
        /* checa se a joia não está faltando, vendo se ela pertence a PA das faltantes.*/
        if (valor_joia >= falta1)
            falta_check = (valor_joia - falta1) % (falta2 - falta1);
        else
            falta_check = 1;
        /* se a joia estiver em falta, não entrega nada, se estiver em estoque soma-se o seu
         * valor o numero maximo de vezes possivel a soma das joias.*/
        if (falta_check != 0){
            n_joia = (valor_total - sum_check) / valor_joia;
            if (n_joia > 0)
                printf("%d %u\n", n_joia, valor_joia);
            sum_check = sum_check + valor_joia * n_joia;
        }
        /* Divide o valor da joia pela razão da PG para determinar o valor seguinte, que é 
         * menor que o atual.*/
        valor_joia = valor_joia / joia2;
    }

    return 0;
}
