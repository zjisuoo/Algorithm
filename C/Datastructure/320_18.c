#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;
typedef struct TreeNode
{
	element key;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode *search(TreeNode * node, int key)
{
	if(node == NULL)
		return NULL;
	if(key == node -> key)
		return node;
	else if(key < node -> key)
		return search(node -> left, key);
	else
		return search(node -> right, key);
}

TreeNode *new_node(int item)
{
	TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp -> key = item;
	temp -> left = temp -> right = NULL;
	return temp;
}

TreeNode *insert_node(TreeNode * node, int key)
{
	if(node == NULL)
		return new_node(key);
	if(key < node -> key)
		node -> left = insert_node(node -> left, key);
	else if(key > node -> key)
		node -> right = insert_node(node -> right, key);

	return node;
}

TreeNode *min_value_node(TreeNode * node)
{
	TreeNode * current = node;

	while(current -> left != NULL)
		current = current -> left;

	return current;
}

TreeNode *delete_node(TreeNode * root, int key)
{
	if(root == NULL)
		return root;
	if(key < root -> key)
		root -> left = delete_node(root -> left, key);
	else if(key > root -> key)
		root -> right = delete_node(root -> right, key);
	else
	{
		if(root -> left == NULL)
		{
			TreeNode * temp = root -> right;
			free(root);
			return temp;
		}
		else if(root -> right == NULL)
		{
			TreeNode * temp = root -> left;
			free(root);
			return temp;
		}	
		TreeNode * temp = min_value_node(root -> right);

		root -> key = temp -> key;
		root -> right = delete_node(root -> right, temp -> key);		
	}
	return root;	
}

void inorder(TreeNode * root)
{
	if(root)
	{
		inorder(root -> left);
		printf("[%d]", root -> key);
		inorder(root -> right);
	}
}

int main()
{
	TreeNode * root = NULL;
	TreeNode * temp = NULL;

	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);

	printf("BINARY TREE INORDER RESULT\n");
	inorder(root);
	printf("\n\n");

	return 0;
}








