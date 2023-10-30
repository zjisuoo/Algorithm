//
//  1712.c
//  baekjoon
//
//  Created by 문지수 on 18/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a, b, c;
    int n;
    
    scanf("%d %d %d", &a, &b, &c);
    
    n = c - b;
    
    if(n <= 0)
        printf("-1\n");
    else
        printf("%d", a / n + 1);
    
    return 0;
}
