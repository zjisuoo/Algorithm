//
//  10818.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int max, min = 0;
    int i, n = 0;
    int a = 0;
    
    scanf("%d", &n);
    
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d", &a);
        
        if(i == 0)
        {
            max = a;
            min = a;
        }
        else
        {
            if(a >= max)
            {
                max = a;
            }
            else if(a <= min)
            {
                min = a;
            }
        }
    }
    printf("%d %d", min, max);
    
    return 0;
}
