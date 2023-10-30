//
//  2231.c
//  baekjoon
//
//  Created by 문지수 on 19/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = n - 54 ; i < n ; i++)
    {
        int temp = i, sum = i;
        while(temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == n)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
