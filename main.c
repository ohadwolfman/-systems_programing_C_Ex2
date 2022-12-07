#include <stdio.h>
#include "my_mat.h"

#define V 10

int main() {
    char function;
    while(scanf("%c",&function)!=EOF && function!='D'){
        if(function=='A'){
			createMatrix();
		}
        
        if(function=='B') {
			isConnected();
		}
        
        if(function=='C') {
			shortestPath();
		}
    }      
    return 0;
}