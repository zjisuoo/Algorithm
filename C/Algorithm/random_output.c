//
//  random_output.c
//  AVL-BST
//
//  Created by 문지수 on 2019/12/06.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int num;

	srand(time(NULL));
	for(num = 0 ; num < 10 ; num++)
		printf("%d\n", rand()%100 + 1);

	return 0;
}