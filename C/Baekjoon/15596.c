//
//  15596.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long sum(int *, int);

int main()
{
    int n, m;
    long long result;
    scanf("%d", &n);
    int *a[n];
    
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d", &m);
        *a[i] = m;
    }
    result = sum(*a, n);
    
    printf("%lli", result);
    
    return 0;
}

long long sum(int *a, int n)
{
    long long result = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        result += a[i];
    }
    return result;
}

