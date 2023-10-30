//
//  2447.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int n;
int main()
{
    scanf("%d", &n);
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            int dx = i, dy = j;
            while(dx)
            {
                if(dx % 3 == 1 && dy % 3 == 1)
                    break;
                dx /= 3, dy /= 3;
            }
            putchar(dx ? ' ' : '*');
        }
        puts("");
    }
    return 0;
}
