//
//  2884.c
//  baekjoon
//
//  Created by 문지수 on 16/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//
// 알람 시계

#include <stdio.h>
#include <string.h>

int main()
{
    int h, m;
    
    scanf("%d %d", &h, &m);
    
    if(m < 45)
    {
        m += 15;
        if(--h < 0)
            h = 23;
    }
    else
        m -= 45;
    printf("%d %d\n", h, m);
    
    return 0;
}
