//
//  4153.c
//  baekjoon
//
//  Created by 문지수 on 18/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    while(1)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        
        if(!a && !b && !c)
            break;
        if(b*b + c*c == a*a || a*a + c*c == b*b || b*b + a*a == c*c)
            printf("right\n");
        else
            printf("wrong\n");
    }
    return 0;
}

