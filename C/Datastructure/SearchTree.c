#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
	int key;
	struct TreeNode *left, *right;
} TreeNode;

// 순환 탐색
TreeNode *search(TreeNode *node, int key)
{
	if(node == NULL)							// 찾는 값을 찾는데 NULL 이거나, node 자체가 NULL
		return NULL;
	if(key == node -> key)						// 원하는 값 찾음
		return node;							// 해당 노드 주소 return
	else if(key < node -> key)					// 찾는 값보다 키값이 작은 경우
		return search(node -> left, key);		// 왼쪽으로 이동
	else										// 찾는 값보다 키값이 큰 경우
		return search(node -> right, key);		// 오른쪽으로 이동
}

// 반복 탐색
TreeNode *search(TreeNode *node, int key)
{
	while(node == NULL)
	{
		if(key == node -> key)					// 원하는 키값 발견
			return node;						// 해당 노드 주소 return
		else if(key < node -> key)				// 찾는 값보다 키값이 큰 경우
			node = node -> left;				// 왼쪽으로 이동
		else									// 찾는 값 보다 키값이 작은 경우
			node = node -> right;				// 오른쪽으로 이동
	}
	return NULL;
}

// 노드 삽입 함수
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t;		// p 부모노드 가리키는 포인터, t 현재 노드 포인터
	TreeNode *n;			// n 새로운 노드 포인터

	t = *root;				// 처음 현재 노드는 root
	p = NULL;				// root 의 부모노드가 없기 때문

	while(t)
	{
		if(key == t -> key)
			return;
		p = t;					// 부모 노드를 현재 노드로 설정, 새로운 root

		if(key < p -> key)		// 부모 키값과 비교
			t = p -> left;		// 현재 노드 -> 부모의 왼쪽 서브트리
		else
			t = p -> right;		// 현재 노드 -> 부모의 오른쪽 서브트리
	}
	n = (TreeNode *)malloc(sizeof(TreeNode));	// 새로 삽입 될 노드 생성
	if(!n)
		return;									// 동적할당 실패했을 경우 return

	if(p)						// 부모 노드 존재
	{
		if(key < p -> key)
			p -> left = n;
		else
			p -> right = n;
	}
	else						// 부모 노드 존재 안할 경우 새로운 노드가 root 
		*root = n;
}

// 노드 삭제 함수
void delete_node(TreeNode **root, int key)
{
	TreeNode *parent, *child, *suc, *suc_p, *t;

	parent = NULL;		// parent 는 t 의 부모노드
	t = *root;

	while(t != NULL && t -> key != key)
	{
		parent = t;														// 부모를 t 값과 동일하게 준 후 t 통해 탐색
		t = (key < parent -> key) ? parent -> left : parent -> right;	// t 는 왼쪽이나 키값에 따라 왼쪽이나 오른쪽으로 내려감
	}
	if(!t)
	{
		printf("KEY IS NOT IN THE TREE");			// 탐색이 끝난 시점에 키값이 트리에 없으면 t 는 NULL
		return;
	}
																// 탐색 성공 시 
	if(t -> left == NULL && t -> right == NULL)					// 1st : 단말노드인 경우
	{
		if(parent)												// 부모노드가 NULL 아닐 때
		{
			if(parent -> left == t)
				parent -> left = NULL:
			else
				parent -> right = NULL;
		}
		else													// 부모노드가 NULL 이면 루트 노드 삭제
			*root = NULL;
	}
	else if((t -> left == NULL) || (t -> right == NULL))		// 2nd : 하나 서브트리만 가지는 경우
	{
		child = (t -> left != NULL) ? t -> left : t -> right;
		if(parent)
		{
			if(parent -> left == t)
				parent -> left = child;
			else
				parent -> right = child;
		}
		else													// 부모노드가 NULL 이면 루트 노드 삭제
			*root = child;
	}
	else														// 3rd : 두 개의 서브트리 가지는 경우
	{
		suc_p = t;												// 오른쪽 서브트리에서 가장 작은 값 찾음
		suc = t -> right;
		while(suc -> left != NULL)
		{
			suc_p = suc;
			suc = suc -> left;
		}
		if(suc_p -> left == suc)								// successor 부모와 자식 연결
			suc_p -> left = suc -> right;						// successor -> rihgt 값 대입
		else
			suc_p -> right = suc -> right;
		t -> key = suc -> key;									// 키값 -> successor 키값 대체
		t = suc;												// t 가 가리키는 노드 -> successor 대체
	}
	free(t);
}

















