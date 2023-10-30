//
//  1018.c
//  baekjoon
//
//  Created by 문지수 on 19/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int m, n;
    char chess[50][50];
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++)
    {
        getchar();
        for(int j = 0 ; j < m ; j++)
            chess[i][j] = getchar();
    }
    int result = 64;
    for(int i = 0 ; i < n - 8 ; i++)
    {
        for(int j = 0 ; j <= m - 8 ; j++)
        {
            int cnt = 0;
            for(int r = 0 ; r < 8 ; r++)
                for(int c = 0 ; c < 8 ; c++)
                    cnt += (r % 2 == c % 2 ? 'W' : 'B') == chess[i + r][j + c];
            result = min(result, cnt);
            result = min(result, 64 - cnt);
        }
    }
    printf("%d\n", result);
}
