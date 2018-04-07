#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

void bubblesort_instant(TpEvento *event, int size);
void swap(TpEvento *ex, TpEvento *ey);

int main(){
	int instrument, note, intensity, ti, deltaT, i, size;
    TpEvento *event;
    event = malloc(20 * sizeof(TpEvento));
    i = 0;
    do {
    	if (i % 20 == 0){
    		event = realloc (event, (i + 20)*sizeof(TpEvento));
    	}
	    scanf ("%d %d %d %d %d", &instrument, &note, &intensity, &ti, &deltaT);
	    (event + i)->instante = ti;
	    (event + i)->instrumento = instrument;
	    (event + i)->nota = note;
	    (event + i)->intensidade = intensity;
        if (instrument != 0){
    		(event + i + 1)->instante = ti + deltaT;
    	    (event + i + 1)->instrumento = instrument;
    	    (event + i + 1)->nota = note;
    	    (event + i + 1)->intensidade = 0;
        }
	    i = i + 2;
	} while (instrument != 0);
	size = i - 2;
/*	bubblesort_instant(event, size);*/
	saida (0, size, event);
	free (event);
	return 0;
}

void bubblesort_instant(TpEvento *event, int size){
	int i, j, swapped;
   	for (i = 0; i < size - 1; i++){
   		swapped = 0;
       	for (j = 0; j < size - i - 1; j++){
        	if ((event + j)->instante > (event  + j + 1)->instante){
            	swap(event + j, event + j + 1);
            	swapped = 1;
            }
            else  if ((event + j)->instante == (event  + j + 1)->instante){
            	if ((event + j)->instrumento > (event  + j + 1)->instrumento){
            	swap(event + j, event + j + 1);           		
            	}
            	else if ((event + j)->instrumento == (event  + j + 1)->instrumento){
            		if ((event + j)->nota > (event  + j + 1)->nota){
            			swap(event + j, event + j + 1);
            		}
            		else if ((event + j)->nota == (event  + j + 1)->nota){
            			if ((event + j)->intensidade > (event  + j + 1)->intensidade){
            				swap(event + j, event + j + 1);
            			}
            		}   		
            	}
            }
		}
		if (swapped == 0)
			i = size;
	}
}

void swap(TpEvento *ex, TpEvento *ey){
	TpEvento temp_event;
	temp_event = *ex;
	*ex = *ey;
	*ey = temp_event;
}