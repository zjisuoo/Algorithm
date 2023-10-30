#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stdent_tag
{
	int ID;
	char name[32];
	char hobby[128];
}student;

student *get_data();
void display_data(student *);

int main(int argc, char const *argv[])
{
	student *st = NULL;

	st = get_data();
	display_data(st);
	
	return 0;
}

student *get_data()
{
	int i;
	student *input = NULL; 
	input = (student *)malloc(sizeof(student)*3);

	input[0].ID = 2017154046;
	strcpy(input[0].name, "zjisuoo");
	strcpy(input[0].hobby, "play");

	input[1].ID = 2015200020;
	strcpy(input[1].name, "jisu");
	strcpy(input[1].hobby, "music");


	input[2].ID = 2015123456;
	strcpy(input[2].name, "seungwoo");
	strcpy(input[2].hobby, "guitar");

	return input;
}

void display_data(student *st)
{
	int i;
	for(i = 0 ; i < 3 ; i++)
	{
		printf("%d %s %s\n", st[i].ID, &st[i].name, &st[i].hobby);
	}
}