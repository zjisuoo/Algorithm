//
//  10872.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n, i;
    int m = 1;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("1");
    }
    else
    {
        for(i = 1 ; i <= n ; i++)
        {
            m = m * i;
        }
        printf("%d", m);
    }
}
