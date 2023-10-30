//
//  7568.c
//  baekjoon
//
//  Created by 문지수 on 19/07/2019.
//  Copyright © 2019 문지수. All rights reserved.
//

#include<stdio.h>

int x[55][2];
int n;

int f(int t){
    int ret = 0;
    for(int i = 0 ; i < n ; i++) if(t!=i && x[t][0] < x[i][0] && x[t][1] < x[i][1]) ret++;
    return ret;
}
int main(){
    scanf("%d",&n);
    
    int res[55];
    for(int i = 0 ; i < n ; i++) scanf("%d%d",&x[i][0],&x[i][1]), res[i] = 1;
    for(int i = 0 ; i < n ; i++){
        res[i] += f(i);
        printf("%d ",res[i]);
    }
    return 0;
}

