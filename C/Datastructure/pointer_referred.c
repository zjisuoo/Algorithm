#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function1 (char **);
void function2 (char **);
void function3 (char **);

int main()
{
	char *school = NULL;
	char *dept = NULL;
	char *name = NULL;

	function1 (&school); // school 의 주소값 대입
	function2 (&dept); // dept 의 주소값 대입
	function3 (&name); // name 의 주소값 대입

	printf("%s \n %s \n %s \n", school, dept, name);

	return 0;
}

void function1(char** a)
{
	*a = (char *)malloc(sizeof(char)*100); // 포인터 a 에 char 100 크기만큼 동적할당  
	strcpy(*a, "한국산업기술대학교"); // a 포인터에 한국산업기술대학교 문자열 복사
}
void function2(char** b)
{
	*b = (char *)malloc(sizeof(char)*100); // 포인터 b 에 char 100 크기만큼 동적할당  
	strcpy(*b, "컴퓨터공학부"); // b 포인터에 컴퓨터공학부 문자열 복사
}

void function3(char** c)
{
	*c = (char *)malloc(sizeof(char)*100); // 포인터 c 에 char 100 크기만큼 동적할당  
	strcpy(*c, "홍길동"); // c 포인터에 홍길동 문자열 복사
}