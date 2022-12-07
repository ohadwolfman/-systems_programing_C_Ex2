#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define V 10

// create distance matrix
int dis[V][V];

void floydWarshall(){
	// update distance from node i to node j:
	// if there is an edge from i to j, and it has a smaller value than going from i to j through k (assuming that exsists as well)
	// keep that value; otherwise, update the value in dis[i][j] to be the route through k.
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				if((dis[i][j] != 0) && (dis[i][k] != 0) && (dis[k][j]!=0)){
					dis[i][j] = fmin(dis[i][j], dis[i][k]+dis[k][j])
				}
				if(i!=j && dis[i][j]==0 && dis[i][k]!=0 && dis[k][j]!=0){
					dis[i][j] = dis[i][k]+dis[k][j]
				}
			}
		}
	}
}


void createMatrix(){
	int x;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			scanf("%d", &x);
			matrix[i][j] = x;
		}
	}
	floydWarshall();
}

void isConnected(int a, int b){
	if(dis[i][j] != 0){
		printf("True");
	} else {
		printf("False");
	}
}

int shortestPath(int a, int b){
	if(dis[i][j]!=0){
		return dis[i][j];
	}
	else{
		return -1;
	}
}

