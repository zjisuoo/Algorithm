//
//  1085.c
//  baekjoon
//
//  Created by 문지수 on 18/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int x, y, w, h;
    int i, min;
    int arr[4];
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    arr[0] = x;
    arr[1] = w - x;
    arr[2] = y;
    arr[3] = h - y;
    
    for(i = 0 ; i < 3 ; i++)
    {
        if(arr[i] <= arr[i + 1])
        {
            min = arr[i];
            arr[i + 1] = min;
        }
        else
            min = arr[i + 1];
    }
    printf("%d\n", min);
    
    return 0;
}
