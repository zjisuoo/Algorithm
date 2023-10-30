#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element; // 항목 정의

typedef struct arrayList
{
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장 된 항목들의 갯수
	// int *list;
	// int length;
} ArrayListType;

void error(char *message)	//오류 처리 함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArrayListType *L)	// 리스트 초기화 함수
{
	L -> size = 0;
}

int is_empty(ArrayListType *L)	// 리스트가 차있으면 1, 아니면 0 return
{
	return L -> size == 0;
}

int is_full(ArrayListType *L) // 리스트가 차있으면 1, 아니면 0 return
{
	return L -> size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos)
{
	if(pos < 0 || pos >= L -> size)
		error("위치 오류");
	return L -> array[pos];
}

void print_list(ArrayListType *L) // 리스트 출력
{
	int i;
	 for(i = 0 ; i < L -> size ; i++)
	 	printf("%d ->", L -> array[i]);
	 printf("\n");
}

void insert_last(ArrayListType *L, element item)
{
	if(L -> size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우");
	}
	L -> array[L -> size++] = item;
}

void insert(ArrayListType *L, int pos, element item)
{
	if(!is_full(L)&&(pos >= 0)&&(pos <= L -> size))
	{
		for(int i = (L -> size -1) ; i >= pos ; i--)
		{
			L -> array[i + 1] = L -> array[i];
			L -> array[pos] = item;
			L -> size++;
		}
	}
}

element delete(ArrayListType *L, int pos)
{
	element item;

	if(pos < 0 || pos >= L -> size)
		error("위치 오류");
	item = L -> array[pos];
	for(int i = pos ; i < (L -> size - 1) ; i++)
	{
		L -> array[i] = L -> array[i + 1];
		L -> size--;
		return item;
	}
}

int main(void)
{
	ArrayListType list;	// ArrayListType 정적으로 생성하고 ArrayListType 가리키는 포인터 함수 매개변수로 전달

	init(&list);
	insert(&list, 0 , 10);
	print_list(&list);
	insert(&list, 0 , 20);
	print_list(&list);
	insert(&list, 0 , 30);
	print_list(&list);
	insert_last(&list, 40);
	print_list(&list);
	delete(&list, 0);
	print_list(&list);
	return 0;
}
