#include <stdio.h>
#include "my_mat.h"

#define V 10

int main(){
	int matrix[V][V]; /*= {{ 0, 3, 1, 0, 0, 2, 0, 0, 0, 0},
						{ 3, 0, 1, 0, 0, 0, 0, 0, 0, 0},
						{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 5, 0, 0},
						{ 0, 0, 0, 0, 0, 0, 0, 4, 1, 1},
						{ 2, 0, 0, 0, 0, 0, 2, 0, 0, 0},
						{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0},
						{ 0, 0, 0, 5, 4, 0, 0, 0, 0, 2},
						{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
						{ 0, 0, 0, 0, 1, 0, 0, 2, 0, 0}};*/
	int flag = 1;
	while(flag == 1){
		char choice;
		printf("What would you like to do?\
			\n'A': Enter values of new matrix.\
			\n'B': Check if there is a route between two nodes.\
			\n'C': Find shortest route between two nodes.\
			\n'D': Exit program.\n");
		scanf("%c", &choice);
		if(choice=='A'){
			createMatrix(matrix);
			printf("\n");
			scanf("%c", &choice);
		}
		else if(choice=='B'){
			int a, b; 
			printf("Please enter two nodes from the graph to see if there's a route between them: /n");
			scanf("%d%d", &a, &b);
			isConnected(a, b, matrix);
			printf("\n");
			scanf("%c", &choice);
		}
		else if(choice=='C'){
			int c, d;
			printf("Please choose two nodes from the graph (0-9) to find shortest route between them: /n");
			scanf("%d%d", &c, &d);
			printf("%d", shortestPath(c, d, matrix));
			printf("\n");
			scanf("%c", &choice);
		}
		else if(choice=='D'){
			printf("Goodbye");
			flag = 0;
		}
		else{
			printf("Please enter a valid option - A, B, C or D.\n");
			scanf("%c", &choice);
		}
	}
	return 0;
}