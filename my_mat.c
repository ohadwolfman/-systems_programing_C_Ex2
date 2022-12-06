#include <stdio.h>
#include <math.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9


void createMatrix(int matrix[V][V]){
	int x;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			scanf("%d", &x);
			matrix[i][j] = x;
		}
	}
}

/*int isConected(int i, int j){
int k=0;
while(k<10){

}

    if(matrix[i][j] != 0){
        return true;
    }
    return false;
}

int shortestPath(int i, int j){
	return 	dijkstra(matrix, i, j);
}*/


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], int visited[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (visited[v] == 0 && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int dijkstra(int graph[V][V], int src, int j)
{
	int dist[V]; // dist[i] will hold the shortest distance from src to i

	int visited[V]; // visited[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, visited[i] = 0;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, visited);

		// Mark the picked vertex as processed
		visited[u] = 1;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Conditions for updating dist[v]:
			// 1. v isn't in visited,
			// 2. there is an edge from u to v,
			// 3. total weight of path from src to v through u is smaller than current value of dist[v]
			if (visited[v]==0 && (graph[u][v]!=0) && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
				dist[v] = dist[u] + graph[u][v];
			}
	}
	if(dist[j]!=0){
		return dist[j];
	}
	else{
		return -1;
	}
}
