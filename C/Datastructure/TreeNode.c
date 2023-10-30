#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode *left, *right;	// 노드 구조체, 링크 포인터
}TreeNode;

int main()
{
	TreeNode *n1, *n2, *n3;

	n1 = (TreeNode *)malloc(sizeof(TreeNode)); // TreeNode 만큼 크기 동적 할당
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));

	n1 -> data = 10;
	n1 -> left = n2;
	n1 -> right = n3;
	n2 -> data = 20;
	n2 -> left = NULL;
	n2 -> right = NULL;
	n3 -> data = 30;
	n3 -> left = NULL;
	n3 -> right = NULL;

	//    n1          10
	// n2    n3    20    30
 
	free(n1);
	free(n2);
	free(n3);

	return 0;
}