#include <stdio.h>
#include <stdlib.h>
#include "lab10.h"

void bubblesort_instant(TpEvento *event, int size);
void sort_isntrumento(TpEvento *event, int size);
void sort_nota(TpEvento *event, int size);
void sort_intesidade(TpEvento *event, int size);
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
		(event + i + 1)->instante = ti + deltaT;	
	    (event + i + 1)->instrumento = instrument;
	    (event + i + 1)->nota = note;
	    (event + i + 1)->intensidade = 0;
	    i = i + 2;
	} while (instrument != 0);
	size = i - 2;
	bubblesort_instant(event, size);
	saida (0, size, event);
	free (event);
	return 0;
}

void bubblesort_instant(TpEvento *event, int size){
/*	int i, j, swapped;
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
	}*/
	int i,j, tam;
	tam = 0;
	for (j = 0; j < size-1; j++)
	{
	    int iMin = j;
	    for (i = j+1; i < size; i++)
	    {
	        if ((event+i)->instante < (event+iMin)->instante)
	        {
	            iMin = i;
	        }
	    }
	    if ((event+iMin)->instante == (event+j)->instante){
	    	tam++;
	    	printf("tam%d\n",tam );
	    }
	    else if ((event+iMin)->instante != (event+j)->instante){
	    	sort_isntrumento(event + j - tam, tam +1);
	    	tam = 0;
	    }
	    if (iMin != j) 
	    {
	        swap(event+j, event+iMin);
	    }
	}
}

void sort_isntrumento(TpEvento *event, int size){
	int i,j, tam;
	tam = 0;
	for (j = 0; j < size-1; j++)
	{
	    int iMin = j;
	    for (i = j+1; i < size; i++)
	    {
	        if ((event+i)->instrumento < (event+iMin)->instrumento)
	        {
	            iMin = i;
	        }
	    }
	    if ((event+iMin)->instrumento == (event+j)->instrumento){
	    	tam++;
	    }
	    else if ((event+iMin)->instrumento != (event+j)->instrumento){
	    	sort_nota(event + j - tam, tam + 1);
	    	tam = 0;
	    }
	    if (iMin != j) 
	    {
	        swap(event+j, event+iMin);
	    }
	}
	printf("oi%d\n",size);
}

void sort_nota(TpEvento *event, int size){

	int i,j, tam;
	printf("oi\n");
	tam = 0;
	for (j = 0; j < size-1; j++)
	{
	    int iMin = j;
	    for (i = j+1; i < size; i++)
	    {
	        if ((event+i)->nota < (event+iMin)->nota)
	        {
	            iMin = i;
	        }
	    }
	    if ((event+iMin)->nota == (event+j)->nota){
	    	tam++;
	    }
	    else if ((event+iMin)->nota != (event+j)->nota){
	    	sort_intesidade(event + j - tam, tam + 1);
	    	tam = 0;
	    }
	    if (iMin != j) 
	    {
	        swap(event+j, event+iMin);
	    }
	}
}

void sort_intesidade(TpEvento *event, int size){
	int i,j;
	for (j = 0; j < size-1; j++)
	{
	    int iMin = j;
	    for (i = j+1; i < size; i++)
	    {
	        if ((event+i)->intensidade > (event+iMin)->intensidade)
	        {
	            iMin = i;
	        }
	    }
	    if (iMin != j) 
	    {
	        swap(event+j, event+iMin);
	    }
	}
}



void swap(TpEvento *ex, TpEvento *ey){
	TpEvento temp_event;
	temp_event = *ex;
	*ex = *ey;
	*ey = temp_event;
}