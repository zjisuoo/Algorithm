//
//  10950.c
//  baekjoon
//
//  Created by 문지수 on 16/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i, j;
    int a, b;
    
    scanf("%d", &i);
    
    for(j = 0 ; j < i ; j++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}
