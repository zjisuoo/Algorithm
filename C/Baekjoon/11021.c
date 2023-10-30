//
//  11021.c
//  baekjoon
//
//  Created by 문지수 on 16/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i = 0, j = 0;
    int a = 0, b = 0;
        
    scanf("%d", &i);
        
    for(j = 1 ; j <= i ; j++)
    {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", j, a, b, a+b);
    }
    return 0;
}
