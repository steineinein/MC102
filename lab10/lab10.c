 /* MC102 - Turma O - Professor Julio López
 * Gabriel Paschoal Stein - RA 197466
 *
 * Laboratório 10 - Autômato musical
 * Input: Informãções da música, uma linha com informação do som a ser produzido contendo:
 * número do instrumento; número da nota; intensidade; instante de início; duração.
 * Output: Enventos da música em ordem de instante, instrumento, nota e intensidade.
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

void bubblesort(TpEvento *event, int size);
void swap(TpEvento *ex, TpEvento *ey);
int compare (TpEvento *a, TpEvento *b);

int main(){
    int instrument, note, intensity, ti, deltaT, i, size;
    TpEvento *event;
    /* aloca espaço de 20 TpEvento para event */
    event = malloc(20 * sizeof(TpEvento));
    i = 0;
    do {
        /* checa se é necessário alocar mais espaço */
        if (i % 20 == 0){
            event = realloc (event, (i + 20)*sizeof(TpEvento));
        }
        /* escaneia os dados da entrada */
        scanf ("%d %d %d %d %d", &instrument, &note, &intensity, &ti, &deltaT);
        /* instante inicial do som */
        (event + i)->instante = ti;
        (event + i)->instrumento = instrument;
        (event + i)->nota = note;
        (event + i)->intensidade = intensity;
        /* instante final do som */
        (event + i + 1)->instante = ti + deltaT;
        (event + i + 1)->instrumento = instrument;
        (event + i + 1)->nota = note;
        (event + i + 1)->intensidade = 0;
        i = i + 2;
        /* repete enquanto não chega ao final */
    } while (instrument != 0);
    size = i - 2;
    /* chama a função de ordenação, para ordenar os sons de forma correta */
    bubblesort(event, size);
    /* imprime a saída */
    saida (0, size, event);
    /* libera o espaço alocado para event */
    free (event);
    return 0;
}

/* função para ordenar os eventos, usando bubblesort */
void bubblesort(TpEvento *event, int size){
    int i, j, swapped;
    for (i = 0; i < size - 1; i++){
        swapped = 0;
        for (j = 0; j < size - i - 1; j++){
            /* compara o para e decide qual deve vir primeiro */
            if (compare (event + j, event + j +1)){
                swap(event + j, event + j + 1);
                swapped = 1;
            }
        }
        /* se já está ordenado, finaliza o loop */
        if (swapped == 0)
            i = size;
    }
}

/* função para trocar 2 eventos de posição */
void swap(TpEvento *ex, TpEvento *ey){
    TpEvento temp_event;
    temp_event = *ex;
    *ex = *ey;
    *ey = temp_event;
}

/* Retorna 0 se a < b e 1 se a > b */
int compare (TpEvento *a, TpEvento *b){
    int flag;
    flag = 0;
    if (a->instante > b->instante){
        flag = 1;
    }
    else if (a->instante == b->instante){
        if (a->instrumento > b->instrumento){
            flag = 1;
        }
        else if (a->instrumento == b->instrumento){
            if (a->nota > b->nota){
                flag = 1;
            }
            else if (a->nota == b->nota){
                if (a->intensidade > b->intensidade){
                    flag = 1;
                }
            }
        }
    }
    return flag;
}