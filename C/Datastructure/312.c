#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct
{
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;

typedef struct TreeNode
{
	element key;
	struct TreeNode *left, *right;
} TreeNode;

// e1 < e2 -1 return
// e1 == e2 0 return
// e1 > 32 1 return
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}

// 이진 탐색 트리 출력 함수
void display(TreeNode *p)
{
	if(p != NULL)
	{
		printf("(");
		display(p -> right);
		printf("%s", p -> key.word);
		display(p -> left);
		printf(")");
	}
}

// 이진 탐색 트리 탐색 함수
TreeNode *search(TreeNode *root, element key)
{
	TreeNode *p = root;
	while(p != NULL)
	{
		switch(compare(key, p -> key))
		{
			case -1 :
				p = p -> left;
				break;
			case 0 : 
				return p;
			case 1 : 
				p = p -> right;
				break;
		}
	}
	return p;										// 탐색 실패 했을 경우 NULL return
}

void insert_node(TreeNode **root, element key)
{
	TreeNode *p, *t;								// p 는 부모 노드, t 는 자식 노드
	TreeNode *n;									// n 은 새로운 노드

	t = *root;
	p = NULL;
	while(t != NULL)								// 탐색 먼저 수행
	{
		if(compare(key, t -> key) == 0)
			return;
		p = t;
		if(compare(key, t -> key) < 0)
			t = t -> right;
		else 
			t = t -> left;
	}
	n = (TreeNode *)malloc(sizeof(TreeNode));		// item 이 트리 안에 없으므로 삽입 가능
	if(n == NULL)									
		return;
	n -> key = key;									// 데이터 복사
	n -> right = n -> left = NULL;
	if(p != NULL)									// 부모 노드와 링크 연결
		if(compare(key, p -> key) < 0)
			p -> right = n;
		else
			p -> left = n;
	else *root = n;

}

// 삭제 함수
void delete_node(TreeNode **root, element key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	p = NULL;													// 키를 갖는 노드 t 탐색, p 는 t 의 부모 노드
	t = *root;

	while(t != NULL && compare(t -> key, key) != 0)
	{
		p = t;
		t = (compare(key, t -> key) < 0) ? t -> left : t -> right;
	}
	if(t == NULL)												// 탐색트리에 없는 키
	{
		printf("KEY IS NOT IN THE TREE");
		return;
	}
	if((t -> left == NULL) && (t -> right == NULL))				// 단말 노드 인 경우
	{
		if(p != NULL)
		{
			if(p -> right == t)
				p -> right = NULL;
			else
				p -> left = NULL;
		}
		else
			*root = NULL;										// 부모 노드가 없으면 루트
	}
	else if((t -> left == NULL) || (t -> right == NULL))		// 하나의 자식만 가지는 경우
	{
		child = (t -> left != NULL) ? t -> left : t -> right;
		if(p != NULL)
		{
			if(p -> right == t)
				p -> right = child;								// 부모 노드 자식 노드와 연결
			else 
				p -> left = child;
		}
		else
			*root = child;
	}
	else														// 두 개 자식을 가지는 경우
	{
		succ_p = t;
		succ = t -> left;										// 오른쪽 서브트리에서 후속자 찾음

		while(succ -> right != NULL)								// 후속자 찾아서 왼쪽으로 이동
		{
			succ_p = succ;
			succ = succ -> right;
		}
		if(succ_p -> right == succ)								// 후속자의 부모와 자식 연결
			succ_p -> right = succ -> right;
		else
			succ_p -> left = succ -> left;

		t -> key = succ -> key;									// 후속자 현재 노드로 이동
		t = succ;
	}
	free(t);
}

void help()
{
	printf("\n--- i : 입력 / d : 삭제 / s : 탐색 / p : 출력 / q : 종료 ---\n");
}

// 이진 트리를 사용하는 영어 사전 프로그램
int main()
{
	char command;
	element e;
	TreeNode *root = NULL;
	TreeNode *tmp;

	do
	{
		help();
		command = getchar();
		fflush(stdin);			
		switch(command)
		{
			case 'i' : 
				printf("단어 : ");
				gets(e.word);
				printf("의미 : ");
				gets(e.meaning);
				insert_node(&root, e);
				break;
			case 'd' :
				printf("단어 : ");
				gets(e.word);
				delete_node(&root, e);
				break;
			case 'p' : 
				display(root);
				printf("\n");
				break;
			case 's' :
				printf("단어 : ");
				gets(e.word);
				tmp = search(root, e);
				if(tmp != NULL)
					printf("의미 : %s\n", e.meaning);
				break;
		}
	}
	while(command != 'q');
}
