//
//  2753.c
//  baekjoon
//
//  Created by 문지수 on 15/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//
// 윤년

#include <stdio.h>
#include <string.h>

int main()
{
    int year;
    
    scanf("%d", &year);
    
    if((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}
