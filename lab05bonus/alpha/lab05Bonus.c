 /* MC102 - Turma O - Professor Julio López
  * Gabriel Paschoal Stein - RA 197466
  *
  * Laboratório 05 bonus -
 */

#include <stdio.h>

int main(){

    int male_n_steps, female_n_steps;
    int male_steps[1000], female_steps[1000];
    int male_direction[1000], female_direction[1000];
    int i, same, angle_dif, soma_dir[8], second_stage, third_stage_f, third_stage_m, check_second_end, fechou;

    scanf("%d %d", &female_n_steps, &male_n_steps);
    for (i = 0; i < female_n_steps; ++i)
        scanf("%d %d", &female_direction[i], &female_steps[i]);
    for (i = 0; i < male_n_steps; ++i)
        scanf("%d %d", &male_direction[i], &male_steps[i]);

    angle_dif = 0; 
    same = 1;
    for (i = 0; i < 8; i++)
        soma_dir[i] = 0; 

    /* checa se primeira parte da femea é fechada */
    if (same){
        i = 0;
        fechou = 0;
        do{
            soma_dir[female_direction[i]] = soma_dir[female_direction[i]] + female_steps[i];
            if (soma_dir[0] == soma_dir[4] && soma_dir[1] == soma_dir[5] && soma_dir[2] == soma_dir[6] && soma_dir[3] == soma_dir[7])
                fechou = 1;
            i++;
        } while(!fechou && i < female_n_steps);
        second_stage = i;
        if (!fechou)
            same = 0;
    }

    /* checa se primeira parte é igual e se macho tem passos maiores*/
    if (male_steps[0] <= female_steps[0])
        same = 2;
    angle_dif = male_direction[0] - female_direction[0];
    if (same){
        for (i = 0; i < second_stage && same; i++){
            if (male_steps[0]*female_steps[i] != male_steps[i]*female_steps[0])
                same = 2;
            if((female_direction[i] + angle_dif + 8) % 8 != male_direction[i])
                same = 2;
        }
    }

    /* segunda parte */
    if (same == 1){
        /* checa fim da segunda fase da femea*/
        check_second_end = 1;
        for (i = second_stage; i < female_n_steps && check_second_end >= 0; i++){
            if((female_direction[i] - female_direction[i-1] + 8) % 8 == 4)
                check_second_end = female_steps[i - 1] - female_steps[i];
        }
        third_stage_f = i;
        /* checa fim da segunda fase do macho */
        check_second_end = 1;
        for (i = second_stage; i < male_n_steps && check_second_end >= 0; i++){
            if((male_direction[i] - male_direction[i-1] + 8) % 8 == 4)
                check_second_end = male_steps[i - 1] - male_steps[i];
        }
        third_stage_m = i;
        /* checa se o macho deu mais passos que a femea */
        if (third_stage_m > third_stage_f)
            same = 2;
    }

    /* terceira parte */
    if (same == 1){
        angle_dif = male_direction[third_stage_m] - female_direction[third_stage_f];
            for (i = 0; i < female_n_steps - third_stage_f && same; i++){
                if (male_steps[third_stage_m]*female_steps[i + third_stage_f] != male_steps[i + third_stage_m]*female_steps[third_stage_f])
                    same = 2;
                if((female_direction[i + third_stage_f] + angle_dif + 8) % 8 != male_direction[i + third_stage_m])
                    same = 2;
            }
    }

    /* reversos */
    /* checa se a primeira parte do reverso é igual e se o passo do macho é maior */
    if (male_steps[male_n_steps - 1] <= female_steps[0] && same == 2)
        same = 0;
    angle_dif = male_direction[male_n_steps - 1] - female_direction[0];
    if (same == 2){
        for (i = 0; i < second_stage && same == 2; i++){
            if (male_steps[male_n_steps - 1]*female_steps[i] != male_steps[male_n_steps - 1 - i]*female_steps[0])
                same = 0;
            if((female_direction[i] + angle_dif + 8) % 8 != male_direction[male_n_steps - 1 - i])
                same = 0;
        }
        printf ("etap 1same: %d\n", same);
    }

    /* segunda parte */
    if (same == 2){
        /* checa fim da segunda fase da femea*/
        check_second_end = 1;
        for (i = second_stage; i < female_n_steps && check_second_end >= 0; i++){
            if((female_direction[i] - female_direction[i-1] + 8) % 8 == 4)
                check_second_end = female_steps[i - 1] - female_steps[i];
        }
        third_stage_f = i;
        /* checa fim da segunda fase do macho */
        check_second_end = 1;
        for (i = second_stage; i < male_n_steps && check_second_end >= 0; i++){
            if((male_direction[male_n_steps - 1 - i] - male_direction[male_n_steps - i] + 8) % 8 == 4)
                check_second_end = male_steps[male_n_steps - i] - male_steps[male_n_steps - i - 1];
        }
        third_stage_m = male_n_steps - i - 1;
        /* checa se o macho deu mais passos que a femea */
        if (male_n_steps - third_stage_m - 1 > third_stage_f)
            same = 0;
        printf ("etap 2same: %d\n", same);
    }

    /* terceira parte */
    if (same == 2){
        angle_dif = male_direction[third_stage_m] - female_direction[third_stage_f];
            for (i = 0; i < female_n_steps - third_stage_f && same == 2; i++){
                if (male_steps[third_stage_m - i]*female_steps[i + third_stage_f] != male_steps[third_stage_m - i]*female_steps[third_stage_f])
                    same = 0;
                if((female_direction[i + third_stage_f] + angle_dif + 8) % 8 != male_direction[third_stage_m - i])
                    same = 0;
            }
    }

    if (same == 1)
        printf("Compatibilidade natural.\n");
    else if (same == 2)
        printf("Reverso tem compatibilidade.\n");
    else
        printf("Incompatibilidade total.\n");


    return 0;
}
