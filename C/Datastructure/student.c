#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct score_tag
{
	char title[32];
	char gpa[3];
} Score;

typedef struct student_tag
{
	int id;
	char name[64];
	Score score[2];
} Student;


int compare(const void *arg1, const void *arg2)
{
	if(*(int *) arg1 > *(int *)arg2)
		return 1;
	else if( *(int *)arg1 == *(int *)arg2) 
		return 0;
	else return -1;
}

int main()
{
	int i = 0;
	Student list[5] = {NULL};
	list[0].id = 2017154046;
	strcpy(list[0].name, "moon");
	strcpy((list[0].score) -> title, "lit");
	strcpy((list[0].score) -> gpa, "a+");
	list[1].id = 2013201322;
	strcpy(list[1].name,"kim");
	strcpy((list[1].score) -> title, "res");
	strcpy((list[1].score) -> gpa, "a0");
	list[2].id = 2011201211;
	strcpy(list[2].name, "min");
	strcpy((list[2].score) -> title, "tot");
	strcpy((list[2].score) -> gpa, "c+");
	list[3].id = 2010201334;
	strcpy(list[3].name, "choi");
	strcpy((list[3].score) -> title, "pop");
	strcpy((list[3].score) -> gpa, "a+");
	list[4].id = 2012234012;
	strcpy(list[4].name, "jung");
	strcpy((list[4].score) -> title, "pio");
	strcpy((list[4].score) -> gpa, "b0");

	printf("Befor Quick Sort \n");
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d %s %s %s \n", list[i].id, list[i].name, (list[i].score) -> title, (list[i].score) -> gpa);
	}
	
	qsort(list, (size_t)5, sizeof(struct student_tag), compare);
	printf("\n");
	printf("After Quick Sort\n");
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d %s %s %s \n", list[i].id, list[i].name, (list[i].score) -> title, (list[i].score) -> gpa);
	}
}