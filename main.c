#include <stdio.h>
#include "my_mat.h"
// Number of vertices in the graph
#define V 9

int main(){
	int flag = 1;
	while(flag == 1){
		char choice;
		printf("What would you like to do?\
			\n'A': Enter values of new matrix.\
			\n'B': Check if there is a path between two nodes.\
			\n'C': Find shortest path between two nodes.\
			\n'D': Exit program.\n");
		scanf("%c", &choice);
		switch(choice){
			case 'A':
				//createMatrix();
				printf("createMatrix()\n");
				scanf("%c", &choice);
				break;
			case 'B':
				//isConnected();
				printf("isConnected()\n");
				scanf("%c", &choice);
				break;
			case 'C':
				//shortestPath();
				printf("shortestPath()\n");
				scanf("%c", &choice);
				break;
			case 'D':
				printf("Goodbye");
				flag = 0;
				break;
			default: //!'A' && !'B' && !'C' && !'D':
				printf("Please enter a valid option - A, B, C or D.\n");
				scanf("%c", &choice);
				break;
		}
	}

	// Let us create the example graph discussed above
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	printf("%d",dijkstra(graph, 1, 2));
	return 0;
}