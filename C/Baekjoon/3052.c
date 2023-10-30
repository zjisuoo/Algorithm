//
//  3052.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a[11], b[11];
    int num = 10;
    int i = 0, j = 1, k;
    
    for(i = 0 ; i < 10 ; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i] % 42;
    }
    for(k = 0 ; k < 10 ; k++)
    {
        for(j = k + 1 ; j < 11 ; j++)
        {
            if(b[j] != 42)
            {
                if(b[k] == b[j])
                {
                    b[j] = 42;
                    num = num - 1;
                }
            }
        }
    }
    printf("%d\n", num);
    
    return 0;
}
