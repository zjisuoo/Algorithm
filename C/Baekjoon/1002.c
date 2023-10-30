//
//  1002.c
//  baekjoon
//
//  Created by 문지수 on 18/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <math.h>

/* int main()
{
    long long T = 0, C = 0, sr = 0, br =0;
    double A = 0;
    long long x1 = 0, x2 = 0, y1 = 0, y2 = 0, r1 = 0, r2 = 0;
    
    scanf("%d", &T);
    
    while(T != 0)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        A = sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
        C = r1 + r2;
        
        sr = r1 > r2 ? r2 : r1;
        br = r1 < r2 ? r2 : r1;
        
        if(A == C)
            printf("0\n");
        else if(A == C)
            printf("1\n");
        else if(C > A)
        {
            if(r1 == r2 && x1 == x2 && y1 == y2)
                printf("-1\n");
            else if(A + sr > br)
                printf("2\n");
            else if(A + sr == br)
                printf("1\n");
            else if(A + sr < br)
                printf("0\n");
        }
        T--;
    }
    return 0;
} */

void swap(int , int);

int main()
{
    int x1, x2, y1, y2, r1, r2;
    int T;
    scanf("%d", &T);
    int i;
    int num;
    int d;
    
    for(i = 0 ; i < T ; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        num = 0;
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if(r1 < r2)
        {
            swap(r1, r2);
        }
        if(d == (r1 + r2) * (r1 + r2))
        {
            num = 1;
        }
        else if((r1 - r2) * (r1 - r2) < d && d < (r1 + r2) * (r1 + r2))
        {
            num = 2;
        }
        else if(r1 == r2 && d == 0)
        {
            num = -1;
        }
        else if(d > (r1 + r2) * (r1 + r2))
        {
            num = 0;
            
        }
        else if(d == (r1 - r2) * (r1 - r2) && d != 0)
        {
            num = 1;
        }else if(d < (r1 - r2) * (r1 - r2))
        {
            num = 0;
        }
        printf("%d\n", num);
    }
    return 0;
}

void swap(int a, int b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
