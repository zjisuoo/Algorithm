//
//  2869.c
//  baekjoon
//
//  Created by 문지수 on 18/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a, b, v;
    int day;
    
    scanf("%d %d %d", &a, &b, &v);
    
    day = (v - b - 1)/(a - b) + 1;
    printf("%d", day);
    
    return 0;
}
