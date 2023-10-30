#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define FALSE 0
#define TRUE 1

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;
	int is_thread;						// 단말 노드와 비 단말 노드 구별
}TreeNode;	

// successor 찾는 함수
TreeNode *find_successor(TreeNode *p)
{
	TreeNode *q = p -> right;					// q 는 p 오른쪽 포인터
	if(q == NULL || p -> is_thread == TRUE)		// 오른쪽 포인터가 NULL 이거나 스레드이면 오른쪽 포인터 return
		return q;
	while(q -> left != NULL)					// 오른쪽 포인터가 오른쪽 자식이면 가장 왼쪽 노드로 이동
		q = q -> left;
	return q;
}

// 스레드 중위 순회 함수
void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	q = t;
	while(q -> left)					
		q = q -> left;					// 가장 왼쪽 노드로 이동
	do
	{
		printf("[%c]", q -> data);		// 데이터 출력
		q = find_successor(q);			// successor 함수 호출
	} while(q);							// NULL 이 아닐 경우
}

int main()
{
	//         G
	//       C   F
	//     A  B D  E 
	
	TreeNode n1 = {'A', NULL, NULL, TRUE};		// 스레드
	TreeNode n2 = {'B', NULL, NULL, TRUE};		// 스레드
	TreeNode n3 = {'C', &n1, &n2, FALSE};
	TreeNode n4 = {'D', NULL, NULL, TRUE};		// 스레드
	TreeNode n5 = {'E', NULL, NULL, FALSE};
	TreeNode n6 = {'F', &n4, &n5, FALSE};
	TreeNode n7 = {'G', &n3, &n6, FALSE};
	TreeNode *root = &n7;

	n1.right = &n3;  	// A -> C
	n2.right = &n7;		// B -> G
	n4.right = &n6;		// D -> F

	thread_inorder(root);
	printf("\n");

	return 0;
}