//
//  1436.c
//  baekjoon
//
//  Created by 문지수 on 19/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    int a[10000] = {0};
    int index = 0;
    int i = 666;
    
    scanf("%d", n);
    
    while(index <= n - 1)
    {
        int count = 0;
        int a = i;
        while(1)
        {
            if(a % 10 == 6)
                count++;
            else
                count = 0;
            a /= 10;
            if(count == 3)
            {
                a[index] = i;
                index++;
            }
            if(a == 0)
                break;
        }
        i++;
    }
    printf("%d", a[n - 1]);
}
