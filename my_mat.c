#include <stdio.h>
#include <math.h>
#include "my_mat.h"

#define V 10
int matrix[V][V] = {0};

void floydWarshall(){
	// create distances matrix for Floyd-Warshell algorithm
	//int dis[V][V] = {0};

	// update distance from node i to node j:
	// if there is an edge from i to j, and it has a smaller value than going from i to j through k (assuming that exsists as well)
	// keep that value; otherwise, update the value in dis[i][j] to be the route through k.
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if((matrix[i][j] != 0) && (matrix[i][k] != 0) && (matrix[k][j]!=0)){
					matrix[i][j] = fmin(matrix[i][j], matrix[i][k]+matrix[k][j]);
				}
				if(i!=j && matrix[i][j]==0 && matrix[i][k]!=0 && matrix[k][j]!=0){
					matrix[i][j] = matrix[i][k]+matrix[k][j];
				}
			}
		}
	}
}


void createMatrix(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	floydWarshall();
}

void isConnected(){
	int i,j;
	if(scanf("%d%d",&i,&j) != EOF);
	if(matrix[i][j] != 0){
		printf("True");
	} else {
		printf("False");
	}
	printf("\n");
}

void shortestPath(){
	int i,j;
	scanf("%d%d",&i,&j);
	if(matrix[i][j]!=0){
		printf("%d\n", matrix[i][j]);
	}
	else{
		printf("-1\n");
	}
	return;
}