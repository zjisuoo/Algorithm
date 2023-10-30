#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const char linestart[] = "------------------ MENU ------------------\n";

typedef struct TreeNode
{
	int key;
	struct TreeNode *left, *right;
} TreeNode;

// 트리 출력 함수
void display(TreeNode *p) {
	if(p != NULL) {
		display(p -> left);
		printf("%3d", p -> key);
		display(p -> right);
	}
}

// 노드 삽입 함수
void insert_node(TreeNode **root, int key)
{
	TreeNode *p, *t;		// p 부모노드 가리키는 포인터, t 현재 노드 포인터
	TreeNode *n;			// n 새로운 노드 포인터

	t = *root;				// 처음 현재 노드는 root
	p = NULL;				// root 의 부모노드가 없기 때문

	while(t != NULL)
	{
		if(key == t -> key)		// 삽입하려고 하는 값이 이미 트리에 존재
			return;
		p = t;					// 부모 노드를 현재 노드로 설정, 새로운 root

		if(key < p -> key)		// 부모 키값과 비교
			t = t -> left;		// 현재 노드 -> 부모의 왼쪽 서브트리
		else
			t = t -> right;		// 현재 노드 -> 부모의 오른쪽 서브트리
	}
	
	n = (TreeNode *)malloc(sizeof(TreeNode));	// 새로 삽입 될 노드 생성
	if(n == NULL)
		return;									// 동적할당 실패했을 경우 return

	n -> key = key;								// 새 노드에 데이터 복사, 링크 초기화
	n -> left = n -> right = NULL;

	if(p != NULL)						// 부모 노드 존재
	{
		if(key < p -> key)
			p -> left = n;				// 왼쪽 자식으로 연결
		else					
			p -> right = n;				// 오른쪽 자식으로 연결
	}
	else							// 부모 노드 존재 안할 경우 새로운 노드가 root 
		*root = n;					// 부모노드가 NULL이면 현재트리 공백상태, 새로운 노드를 루트노드로 설정
}

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
TreeNode *search1(TreeNode *node, int key)
{
	while(node != NULL)
	{
		if(key == node -> key)					// 원하는 키값 발견
			return node;						// 해당 노드 주소 return
		else if(key < node -> key)				// 찾는 값보다 키값이 큰 경우
			node = node -> left;				// 왼쪽으로 이동
		else									// 찾는 값 보다 키값이 작은 경우
			node = node -> right;				// 오른쪽으로 이동
	}
	return NULL;								// 탐색에 실패했을 경우 NULL 반환
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
		t = (key < t -> key) ? t -> left : t -> right;		// t 는 왼쪽이나 키값에 따라 왼쪽이나 오른쪽으로 내려감
	}
	if(t == NULL)									// 탐색이 종료된 시점에 t가 NULL이면 트리 안에 key가 없음
	{
		printf("KEY IS NOT IN THE TREE");			// 탐색이 끝난 시점에 키값이 트리에 없으면 t 는 NULL
		return;
	}
																// 탐색 성공 시 
	if(t -> left == NULL && t -> right == NULL)					// 1st : 단말노드인 경우
	{
		if(parent != NULL)												// 부모노드가 NULL 아닐 때
		{
			if(parent -> left == t)
				parent -> left = NULL;
			else
				parent -> right = NULL;
		}
		else													// 부모노드가 NULL 이면 루트 노드 삭제
			*root = NULL;
	}

	else if((t -> left == NULL) || (t -> right == NULL))		// 2nd : 하나 서브트리만 가지는 경우
	{
		child = (t -> left != NULL) ? t -> left : t -> right;
		if(parent != NULL)
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

int main()
{
	TreeNode *root = NULL;
	//TreeNode *tmp = NULL;
	//TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;
	int find_number;
	int insert_number;
	int delete_number;
	int menuNum;
	int isExcute = 1;

	/* 
	insert_node(&root, 10);
	insert_node(&root, 20);
	insert_node(&root, 30);
	insert_node(&root, 40);
	insert_node(&root, 50);
	insert_node(&root, 60);
	insert_node(&root, 70);
	*/

	/*
	for(int i = 0 ; i < 10 ; i++)
	{
		printf("INSERT NUMBER = ");
		insert_node(*input_data, key);
	}
	*/

	/*
	while(1) {
		printf("INSERT NUMBER = ");
		scanf("%d", &insert_number);
		if(insert_number == 0) 
			break;
		insert_node(&root, insert_number);
		
	}
	*/
	while(isExcute) {
		printf("%s", linestart);
		printf("1. PRINT\n");
		printf("2. SEARCH\n");
		printf("3. INSERT\n");
		printf("4. DELETE\n");
		printf("5. EXIT\n>>");
		scanf("%d", &menuNum);

		switch(menuNum) {
			case 1: 			// 트리 출력
				printf("Tree =");
				display(root);
				printf("\n");
				break;			// 탐색
			case 2:
				printf("FIND NUMBER = ");
				scanf("%d", &find_number);
				if(search(root, find_number) != NULL)
					printf("CAN FIND %d NUMBER\n", find_number);
				else
					printf("CAN NOT FIND %d NUMBER\n", find_number);
				break;
			case 3: 			// insert
				printf("INSERT NUMBER = ");
				scanf("%d", &insert_number);
				insert_node(&root, insert_number);
				break;
			case 4: 			// delete
				printf("DELETE NUMBER = ");
				scanf("%d", &delete_number);
				delete_node(&root, delete_number);
				break;
			case 5:
				isExcute = 0;
				break;
		}
	}	
	return 0;
}