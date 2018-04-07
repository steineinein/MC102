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
    int angle_male[1000], angle_female[1000], dif_angle_male, dif_angle_female;
    int i, same, sum_f, sum_m, sum_04f, sum_26f, sum_15f, sum_37f, sum_04m, sum_26m, sum_15m, sum_37m;

    scanf("%d %d", &female_n_steps, &male_n_steps);
    for (i = 0; i < female_n_steps; ++i)
        scanf("%d %d", &female_direction[i], &female_steps[i]);
    for (i = 0; i < male_n_steps; ++i)
        scanf("%d %d", &male_direction[i], &male_steps[i]);

    if (male_n_steps != female_n_steps)
        printf("Incompatibilidade total.\n");
    else{
        sum_04f = sum_15f = sum_26f = sum_37f = 0;
        for (i = 0; i < male_n_steps; ++i){
            if(female_direction[i] == 0){
                sum_04f = sum_04f + female_steps[i];
                angle_female[i] = 0;
            }
            else if(female_direction[i] == 1){
                sum_15f = sum_15f + female_steps[i];
                angle_female[i] = 1;
            }
            else if(female_direction[i] == 2){
                sum_26f = sum_26f + female_steps[i];
                angle_female[i] = 2;
            }
            else if(female_direction[i] == 3){
                sum_37f = sum_37f + female_steps[i];
                angle_female[i] = 3;
            }
            else if(female_direction[i] == 4){
                sum_04f = sum_04f - female_steps[i];
                angle_female[i] = 4;
            }
            else if(female_direction[i] == 5){
                sum_15f = sum_15f - female_steps[i];
                angle_female[i] = 3;
            }
            else if(female_direction[i] == 6){
                sum_26f = sum_26f - female_steps[i];
                angle_female[i] = 2;
            }
            else if(female_direction[i] == 7){
                sum_37f = sum_37f - female_steps[i];
                angle_female[i] = 1;
            }

            if(male_direction[i] == 0){
                sum_04m = sum_04m + male_steps[i];
                angle_male[i] = 0;
            }
            else if(male_direction[i] == 1){
                sum_15m = sum_15m + male_steps[i];
                angle_male[i] = 1;
            }
            else if(male_direction[i] == 2){
                sum_26m = sum_26m + male_steps[i];
                angle_male[i] = 2;
            }
            else if(male_direction[i] == 3){
                sum_37m = sum_37m + male_steps[i];
                angle_male[i] = 3;
            }
            else if(male_direction[i] == 4){
                sum_04m = sum_04m - male_steps[i];
                angle_male[i] = 4;
            }
            else if(male_direction[i] == 5){
                sum_15m = sum_15m - male_steps[i];
                angle_male[i] = 3;
            }
            else if(male_direction[i] == 6){
                sum_26m = sum_26m - male_steps[i];
                angle_male[i] = 2;
            }
            else if(male_direction[i] == 7){
                sum_37m = sum_37m - male_steps[i];
                angle_male[i] = 1;
            }
        }
        sum_f = sum_04f*sum_04f + sum_15f*sum_15f + sum_26f*sum_26f + sum_37f*sum_37f;
        sum_m = sum_04m*sum_04m + sum_15m*sum_15m + sum_26m*sum_26m + sum_37m*sum_37m;
        if (sum_f == 0 && sum_m == 0){
            same = 1;
            for (i = 1; i < male_n_steps && same; ++i){
                dif_angle_male = (angle_male[i] - angle_male[i-1]);
                dif_angle_female = (angle_female[i] - angle_female[i-1]);
                printf("male: %d - female: %d\n",dif_angle_male ,dif_angle_female);
                if(dif_angle_male*dif_angle_male != dif_angle_female*dif_angle_female)
                    same = 0;
                
            }
            if(same)
                printf("Compatibilidade natural.\n");
            else
                printf("Incompatibilidade total.\n");
        }
        else
            printf("Incompatibilidade total.\n");
    
    }
    

    return 0;
}
