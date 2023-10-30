//
//  2798.c
//  baekjoon
//
//  Created by 문지수 on 19/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n, m;
    int a[100];
    int re = 0;
    
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]);
        for(int i = 0 ; i < n - 2 ; i++)
            for(int j = i + 1 ; j < n - 1 ; j++)
                for(int k = j + 1 ; k < n ; k++)
                    if(a[i] + a[j] + a[k] <= m && m - (a[i] + a[j] + a[k]) < m - re)
                        re = a[i] + a[j] + a[k];
    printf("%d", re);
    return 0;
}
