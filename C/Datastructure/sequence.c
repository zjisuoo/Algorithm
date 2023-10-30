#include <stdio.h>

int sum(int);

int main()
{
	int n = 100;
	printf("1부터 %d까지 합은 %d\n", n, sum(n));

	return 0;
}
int sum(int n)
{
	if(n == 1)
		return 1;
	else 
		return (n + sum(n - 1));
}