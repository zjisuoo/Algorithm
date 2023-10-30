#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
	if(top < SIZE -1 && p != NULL)
		stack[++top] = p;
}

TreeNode *pop()
{
	TreeNode *p = NULL;
	if(top >= 0)
		p = stack[top--];

	return p;
}

void inorder(TreeNode *root)
{
	while(1)
	{
		for( ; root ; root = root -> left)	// root 가 제일 끝 왼쪽 노드까지 가도록 반복
			push(root);						// 제일 왼쪽 노드까지 오면 root push 
		root = pop();						// 제일 왼쪽 노드인 root pop
		if(!root)							// root 아닐 경우
			break;							// 멈춤
		printf("[%d]", root -> data);		
		root = root -> right;			
	}
}

void preorder(TreeNode *root)
{
	push(root);								// root push
	while(1)
	{
		root = pop();						// root push 해서 root pop
		if(!root) 							// root 아닐 경우
		{
			break;							// 멈춤
		}
		printf("[%d]", root -> data);		// 처음엔 root 가 나옴, 다음부터는 왼쪽 노드부터 pop, 왼쪽 노드 pop 다하면 오른쪽 노드 pop
		push(root -> right);				// 오른쪽 노드 push
		push(root -> left);					// 왼쪽 노드 push
	}
}

void postorder(TreeNode *root)
{
	while(1)
	{
		do 
		{
			if(root -> data != NULL && root != NULL)	// root 값이 있을 경우
			{
				push(root);								// root push
				root = root -> left;					// root 에 왼쪽 노드 값 
			}
			else 										// root 값 있을 경우
			{
				break;									// 멈춤
			}
		} while(root != NULL);							// root 값이 있을 경우
		root = pop();									// root pop
		
		if(!root)										// root 에 왼쪽 노드 값을 넣은 것이 root 가 아닐 경우						
		{
			break;										// 멈춤
		}
		if(root -> right != NULL)						// root 오른쪽 노드가 NULL 이 아닐 경우
		{	
			if(root -> right -> data == NULL)			// root 에 오른족 노드 값이 NULL 일 경우
			{
				printf("[%d]", root -> data);			// root 출력
				root -> data = NULL;					// root 비움
			}
			else
			{
				push(root);								// root push
				root = root -> right;					// root 에 오른쪽 노드 값 
			}
		}
		else											// root 오른쪽 노드가 NULL 일 경우
		{
			printf("[%d]", root -> data);				// root 출력
			root -> data = NULL;						// root 비움
		}
	}
} 

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {5, &n1, NULL};
TreeNode n3 = {15, NULL, NULL};
TreeNode n4 = {20 , NULL, NULL};
TreeNode n5 = {25, &n3, &n4};
TreeNode n6 = {55, &n2, &n5};
TreeNode *root = &n6;

//            55
//         5      25
//       1      15  20
// 중위 순회 = [1][5][55][15][25][20]
// 전위 순회 = [55][5][1][25][15][20]
// 후위 순회 = [1][5][15][20][25][55]

/*
inorder(TreeNode *root)
{
	if(root)
	{
		inorder(root -> left);				// 왼쪽 서브트리 순회
		printf("[%d]", root -> data);		// 노드 방문
		inorder(root -> right);				// 오른쪽 서브트리 순회
	}	
}

preorder(TreeNode *root)
{
	if(root)
	{
		printf("[%d]", root -> data);		// 노드 방문
		preorder(root -> left);				// 왼쪽 서브트리 순회
		preorder(root -> right);			// 오른쪽 서브트리 순회
	}
}

postorder(TreeNode *root)
{
	if(root)
	{
		postorder(root -> left); 			// 왼쪽 서브트리 순회
		postorder(root -> right);			// 오른쪽 서브트리 순회
		printf("[%d]", root -> data);		// 노드 방문
	}
} 
*/

int main()
{
	printf("중위 순회 = ");
	inorder(root);
	printf("\n");

	printf("전위 순회 = ");
	preorder(root);
	printf("\n");

	printf("후위 순회 = ");
	postorder(root);
	printf("\n");

	return 0;
}