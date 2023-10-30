#include <stdio.h>

#define MAX_QUEUE_SIZE 32 // 큐의 최대 크기

typedef int QueueObject;
QueueObject queue[MAX_QUEUE_SIZE]; 
int  front, rear, count = 0;

void initialize() 
{
	front = rear = 0;
}

int isEmpty() // 공백 상태 검출
{
	return ((front == rear) && (count == 0));
}

int isFull() // 포화 상태 검출
{
	return ((front == rear) && (count == MAX_QUEUE_SIZE));
}

void addq(QueueObject item)
{ 
  	if(isFull()) { 
		printf("queue is full\n");	} 
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear] = item;
}

QueueObject deleteq() 
{ 
   	if(isEmpty()) 
   	{
   		printf("queue is empty\n");
	}
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
} 

int main()
{
	int i, n;
	initialize();

	while(n <= 1000)
	{
		printf("\nfront=%d rear=%d\n", front, rear);
		for(i=1 ; i <= 16 ; i++)
		{
			addq(i);
			count++;
		}
		for(i=1 ; i <= 10 ; i++)
		{
			printf("deleteq(%d)=%d\n",i,deleteq());
			count--;
		}
	printf("front=%d rear=%d count=%d\n", front, rear, count);
	}	
	return 0;
}