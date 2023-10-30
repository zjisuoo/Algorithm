#include <stdio.h>

char *function1();
char *function2();
char *function3();

int main()
{
	char *school = NULL;
	char *dept = NULL;
	char *name = NULL;

	school = function1(); 
	dept = function2();
	name = function3();

	printf("%s \n %s \n %s \n", school, dept, name);

	return 0;
}
char *function1()
{
	char *a = NULL; // a포인터 시작 주소 NULL 로 만듦
	a = (char *)malloc(sizeof(char)*100); // a에 char 100 크기만큼 동적 메모리 할당
	strcpy(a, "한국산업기술대학교"); // a에 한국산업기술대학교 문자열 복사
	return a;
}
char *function2()
{
	char *b = NULL; // b포인터 시작 주소 NULL 로 만듦
	b = (char *)malloc(sizeof(char)*100); // b에 char 100 크기만큼 동적 메모리 할당
	strcpy(b, "컴퓨터공학부"); // b에 컴퓨터공학부 문자열 복사
	return b;
}
char *function3()
{
	char *c = NULL; // c포인터 시작 주소 NULL 로 만듦
	c = (char *)malloc(sizeof(char)*100); // c에 char 100 크기만큼 동적 메모리 할당
	strcpy(c, "홍길동"); // c에 홍길동 문자열 복사
	return c;
}