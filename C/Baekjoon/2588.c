//
//  2588.c
//  baekjoon
//
//  Created by 문지수 on 15/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//
// 곱셈

#include <stdio.h>

int main()
{
    int input1, input2;
    int result1, result2, result3;
    int result;
    
    scanf("%d", &input1);
    scanf("%d", &input2);
    
    result = input1 * input2;
    result3 = input1 * (input2 % 10);
    result2 = input1 * ((input2 / 10) % 10);
    result1 = input1 * (((input2 / 10) / 10) % 10);
    
    printf("%d\n%d\n%d\n%d", result3, result2, result1, result);
    
    return 0;
}
