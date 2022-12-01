#include<stdio.h>

int graph[10][10], visited[10],n;

main(){
	int i, j;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter adjacency matrix of graph %d x %d :\n ", n, n);
	for(i = 0; i<n;i++){
		for(j= 0; j< n;j++){
			scanf("%d", &graph[i][j]);
		}
	}
	for(i = 0; i<n;i++){
		visited[i] = 0;
	}
	printf("DFS is : ");
	dfs(0);
}

void dfs(int v){
	int j;
	printf("%d\t", v);
	visited[v] = 1;
	for(j = 0; j<n;j++){
		if(!visited[j] && graph[v][j] == 1)
			dfs(j);
	}
	
	
}
