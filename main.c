#include <stdio.h>

int main(){
	char function;
	while((scanf("%c",&function)!=EOF) && (function!='D')){
		switch (function)
		{
			case 'A':
				createMatrix();
				break;

			case 'B':
				isConected();
				break;

			case 'C':
				shortestPath();
				break;
		}
	}
	return 0;
}