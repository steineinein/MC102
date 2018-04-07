#include <stdio.h>

int char_to_int (char c){
	int n;
	n = c - '0';
	return n;
}

void dfs (int g[][1440], int tam[],int level, int i, int j, int n){
	int temp, k;
	temp = g[i][j];
	g[i][j] = - 1;
	if (level == n){

	}
	else if (level == 0){
		for (k = 0; k < tam[2]; k ++){
			if (possible_door(g, tam[1], level)){
				dfs (g, tam, 1, 2, k, n);
			}
		}
	}
	else if {
		for (k = 0; k < tam[2*level]; k ++){
			if (possible_door(g, tam[2*level + 1], level)){
				dfs (g, tam, level + 1, 2*level, k, n);
			}
		}
		for (k = 0; k < tam[2*level - 2]; k ++){
			if (possible_door(g, tam[2*level -1], level)){
				dfs (g, tam, level + 1, 2*level - 2, k, n);
			}
		}
	}
}

int main(){
	int n, i, j, wall[20][1440] = {{0}}, pass[10][1440], tam[20];
	char c;

	scanf ("%d\n", &n);
	i = j = 0;
	while ((c = getchar()) != EOF){
		if (c != ' ' &&  c != '\n'){
			wall[i][j] = 10*wall[i][j] + char_to_int (c);
		}
		else if (c == '\n'){
			tam[i] = j + 1;
			j = 0;
			i++;
		}
		else{
			j++;
		}
	}
	for (i = 0; i < n*2 - 1; i++){
		for (j = 0; j < tam[i]; j++){
			printf("%d ", wall[i][j]);
		}
		printf("\n");
	}
	dfs (wall, tam, 0, 0, 0, n);
}