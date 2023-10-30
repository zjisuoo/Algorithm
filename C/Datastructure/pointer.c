#include <stdio.h>

int main()
{
	int i = 10, j = 20;
	int *ptr;

	printf(" i 의 값 = %d \n j 의 값 = %d \n", i, j);
	printf(" i 의 메모리 주소 (&i) = %u\n", &i);
	printf(" j 의 메모리 주소 (&j) = %u\n", &j);

	ptr = &i;
	printf("\n ptr = &i 실행");
	printf("\n ptr 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr 의 값(ptr) = %u", ptr);
	printf("\n ptr 의 참조값(*ptr) = %d\n", *ptr);

	ptr = &j;
	printf("\n ptr = &j 실행");
	printf("\n ptr 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr 의 값(ptr) = %u", ptr);
	printf("\n ptr 의 참조값(*ptr) = %d\n", *ptr);

	i = *ptr;
	printf("\n i = *ptr 실행");
	printf("\n i 의 값 = %d\n", i);

	getchar();

	return 0;
}