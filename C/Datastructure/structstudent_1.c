#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_t
{
	char name[32];
	int id;
}student;

student *get_data(int *, int *);
void display_data(student *, int);

int main()
{
	int a, b = 30, *ap = NULL, *pt = ap, *bp = &b;

	ap = &a;
	*ap = 10;

	student = get_data(&a, &b);
	printf("%d, %d, 이름 : %s\n", a, b, student[0].name);
	display_data(student, 2);

	return 0;
}

student *get_data(int *x, int *y)
{
	student *st = NULL;

	st = (student *)malloc(sizeof(student)*2);

	strcpy(st[0].name, "zjisuoo");
	st[0].id = 2017154046;

	strcpy(st[1].name, "jisu");
	st[1].id = 201520020;

	printf("Function called by reference : %d and %d\n", ++(*x), (*y)++);

	return st;
}

void display_data(student *student, int size)
{
	int i;

	for(i = 0 ; i < size ; i++)
	{
		printf("학번 : %d, 이름 : %s\n", student[i].id, (student+i)->name);
	}
}