#include <stdio.h>
#include "my_mat.h"

#define V 10

int main() {
    char function " ";
	int a=0, b=0;
    while(scanf("%c",&function)!=EOF && function!='D'){

        if(function=='A'){
			createMatrix();
		}
        
        if(function=='B') {
			scanf("%d%d",&a,&b);
			isConnect(a,b);
		}
        
        if(function=='C') {
			scanf("%d%d",&a,&b);
			shortestPath();
		}
    }      
    return 0;
}