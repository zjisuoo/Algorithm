//
//  1330.c
//  baekjoon
//
//  Created by 문지수 on 15/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//
// 두 수 비교하기

#include <stdio.h>

int main()
{
    int input1, input2;
    
    scanf("%d", &input1);
    scanf("%d", &input2);
    
    if(input1 > input2)
    {
        printf(">\n");
    }
    else if(input1 == input2)
    {
        printf("==\n");
    }
    else if(input1 < input2)
    {
        printf("<\n");
    }
}
