#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fact(int);

int main()
{
    clock_t start, finish;
    double duration;
    
    start = clock();
    
    int number = 0;
    number = fact(10);
    printf("%d\n", number);
    
    finish = clock();
    
    duration = (double)(finish - start);
    printf("%d 초 입니다.\n", (int)duration);
    
    return 0;
}
int fact(int n)
{
    if(n == 1)
    {
        return n;
    }
    else
        return n * fact(n-1);
}
