//
//  10952.c
//  baekjoon
//
//  Created by 문지수 on 17/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a, b;
    
    while(scanf("%d %d", &a, &b) != EOF)
        //EOF (End - Of - File) fgets, getchar 함수가 파일 글에 도달할 경우 반환
        //scanf 는 성공적으로 받아온 수를 return, 에러 발생하거나 EOF 만나면 -1 반환
    {
        if(a == 0 && b == 0)
        {
            break;
        }
        else
            printf("%d\n", a + b);
    }
    return 0;
}
