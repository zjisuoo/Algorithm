#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 32

typedef int element;
typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int front, rear;
	int count;
} QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType *q)
{
	q -> front = q -> rear = 0;
	q -> count = q -> rear % MAX_QUEUE_SIZE;
}

int is_empty(QueueType *q)
{
	return q -> front == q -> rear;
}

int is_full(QueueType *q)
{
	return q -> front == (q -> rear + 1) % MAX_QUEUE_SIZE;
}

void enqueue(QueueType *q, element item)
{
	if (is_full(q))
		error("queue is full");
	q -> rear = (q -> rear + 1) % MAX_QUEUE_SIZE;
	q -> queue[q -> rear] = item;
}

element dequeue(QueueType *q)
{
	if (is_empty(q))
		error("queue is empty");
	q -> front = (q -> front + 1) % MAX_QUEUE_SIZE;
	return q -> queue[q -> front];
}

element peek(QueueType *q)
{
	if (is_empty(q))
		error("queue is empty");
	return q -> queue[(q -> front + 1) % MAX_QUEUE_SIZE];
}

int main()
{
	QueueType q;
	int i;
	init(&q);
	int n;
	printf("n : ");
	scanf("%d", &n);

	printf("front = %d rear = %d\n", q.front, q.rear);

	while (1) { 

		for(i = 1; i <= 16; i++) {
			enqueue(&q, n);
			q.count++;
			n++;

		}
		
		for(i = 1; i <= 10; i++) {
			printf("dequeue(%d) = %d\n", i, dequeue(&q));
			q.count--; 

		}
		if(n >= 1000) {
			br
		}
	}
	

	printf("front = %d rear = %d\n count = %d\n", q.front, q.rear, q.count);

	return 0;
}