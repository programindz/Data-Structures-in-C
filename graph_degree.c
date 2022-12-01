#include<stdio.h>

main(){
	int graph[4][4] = {{0,1,0,1},
					   {0,0,1,0},
					   {0,0,0,1},
					   {1,0,0,0}};
	int i, j;
	int k = 0;
	for(i = 0; i< 4;i++){
		int sum = 0;
		for(j = 0; j< 4;j++){
			sum+=graph[i][j];
		}
		k++;
		printf("Outdegree of node %d: %d\n", k, sum);
	}
	k = 0;
	for(i = 0; i< 4;i++){
		int sum = 0;
		for(j = 0; j< 4;j++){
			sum+=graph[j][i];
		}
		k++;
		printf("\nIndegree of node %d: %d", k, sum);
	}
}
