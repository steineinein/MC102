 /* MC102 - Turma O - Professor Julio López
  * Gabriel Paschoal Stein - RA 197466
  *
  * Laboratório 05 -
 */

#include <stdio.h>

int main(){

    int male_n_steps, female_n_steps;
    int male_steps[1000], female_steps[1000];
    int male_direction[1000], female_direction[1000];
    int i, same, angle_dif, sum_f, sum_m, sum_04f, sum_26f, sum_15f, sum_37f, sum_04m, sum_26m, sum_15m, sum_37m;

    scanf("%d %d", &female_n_steps, &male_n_steps);
    for (i = 0; i < female_n_steps; ++i)
        scanf("%d %d", &female_direction[i], &female_steps[i]);
    for (i = 0; i < male_n_steps; ++i)
        scanf("%d %d", &male_direction[i], &male_steps[i]);

    if (male_n_steps != female_n_steps){
        printf("Incompatibilidade total.\n");
        return 0;
    }
    if (male_steps[0] <= female_steps[0]){
        printf("Incompatibilidade total.\n");
        return 0;
    }

    sum_04f = sum_15f = sum_26f = sum_37f = 0;
    for (i = 0; i < male_n_steps; ++i){
        if(female_direction[i] == 0)
            sum_04f = sum_04f + female_steps[i];
        else if(female_direction[i] == 1)
            sum_15f = sum_15f + female_steps[i];
        else if(female_direction[i] == 2)
            sum_26f = sum_26f + female_steps[i];
        else if(female_direction[i] == 3)
            sum_37f = sum_37f + female_steps[i];
        else if(female_direction[i] == 4)
            sum_04f = sum_04f - female_steps[i];
        else if(female_direction[i] == 5)
            sum_15f = sum_15f - female_steps[i];
        else if(female_direction[i] == 6)
            sum_26f = sum_26f - female_steps[i];
        else if(female_direction[i] == 7)
            sum_37f = sum_37f - female_steps[i];

        if(male_direction[i] == 0)
            sum_04m = sum_04m + male_steps[i];
        else if(male_direction[i] == 1)
            sum_15m = sum_15m + male_steps[i];
        else if(male_direction[i] == 2)
            sum_26m = sum_26m + male_steps[i];
        else if(male_direction[i] == 3)
            sum_37m = sum_37m + male_steps[i];
        else if(male_direction[i] == 4)
            sum_04m = sum_04m - male_steps[i];
        else if(male_direction[i] == 5)
            sum_15m = sum_15m - male_steps[i];
        else if(male_direction[i] == 6)
            sum_26m = sum_26m - male_steps[i];
        else if(male_direction[i] == 7)
            sum_37m = sum_37m - male_steps[i];
    }
    sum_f = sum_04f*sum_04f + sum_15f*sum_15f + sum_26f*sum_26f + sum_37f*sum_37f;
    sum_m = sum_04m*sum_04m + sum_15m*sum_15m + sum_26m*sum_26m + sum_37m*sum_37m;
    if (sum_f != 0 || sum_m != 0){
        printf("Incompatibilidade total.\n");
        return 0;
    }

    angle_dif = male_direction[0] - female_direction[0];
    same = 1;
    for (i = 0; i < male_n_steps && same; i++){
        if (male_steps[0]*female_steps[i] != male_steps[i]*female_steps[0])
            same = 0;
        if((female_direction[i] + angle_dif + 8) % 8 != male_direction[i])
            same = 0;
        printf("tam%d||%d\n",male_steps[0]*female_steps[i],male_steps[i]*female_steps[0]);
        printf("dir%d||%d\n",(female_direction[i] + angle_dif + 8) % 8,male_direction[i]);
    }
    if (same){
        printf("Compatibilidade natural.\n");
        return 0;
    }
    same = 1;
    angle_dif = male_direction[male_n_steps - 1] - female_direction[0];
    for (i = 0; i < male_n_steps && same; i++){
        if (male_steps[male_n_steps - 1]*female_steps[i] != male_steps[male_n_steps -1 - i]*female_steps[0])
            same = 0;
        if((female_direction[i] + angle_dif + 8) % 8 != male_direction[male_n_steps - 1 - i])
            same = 0;
    }
    if (same)
        printf("Reverso tem compatibilidade.\n");
    else
        printf("Incompatibilidade total.\n");

    return 0;
}
