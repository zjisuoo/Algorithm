#include <stdio.h>

int sum(int);

int main(){
	int n = 100;
	printf("1부터 %d까지 합은 %d\n", n, sum(n));
	printf("\n");

	return 0;
}
int sum(int n){
	int i;
	for(int i = 0 ; i <= n ; i++)
		i = i + n;
		
	return i;
}

