//
//  2562.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a[9];
    int max = 0;
    int index;
    
    for(int i = 0 ; i < 9 ; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    printf("%d\n%d", max, index+1);
    
    return 0;
}
