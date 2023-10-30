//
//  BST.c
//  AVL-BST
//
//  Created by 문지수 on 2019/12/06.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x)>(y)?(x):(y))

/*
int max(int c1, int c2)
{
    int c1, c2;
    if(c1 > c2)
    {
        return c1;
    }
    else if(c1 < c2)
    {
        return c2;
    }
    else
        return 0;
}
*/

typedef int element;
typedef struct TreeNode
{
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode * search_count(TreeNode * node, int key, int count)
{
    count++;
    if(node == NULL)
        return NULL;
    if(key == node -> key)
    {
        return count;
    }
    else if(key < node -> key)
    {
        return search_count(node -> left, key, count);
    }
    else
    {
        return search_count(node -> right, key, count);
    }
}

TreeNode * new_node(int item)
{
    TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

TreeNode * insert_node(TreeNode * node, int key)
{
    if(node == NULL)
        return new_node(key);
    if(key < node -> key)
        node -> left = insert_node(node -> left, key);
    else if(key > node -> key)
        node -> right = insert_node(node -> right, key);
    return node;
}

TreeNode * min_value_node(TreeNode * node)
{
    TreeNode * current = node;
    while(current -> left != NULL)
        current = current -> left;
    return current;
}

TreeNode * delete_node(TreeNode * root, int key)
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

int get_height(TreeNode * root)
{
    int height = 0;
    if(root != NULL)
        height = 1 + max(get_height(root -> left), get_height(root -> right));
    
    return height;
}

int main()
{
    TreeNode * root = NULL;
    TreeNode * tmp = NULL;
    int count = 0;

    srand(time(NULL));
    int random_root = 0;
    for(int i = 0 ; i < 10 ; i++)
    {
        random_root = rand()%100 + 1;
        root = insert_node(root, random_root);
    }
    
    printf("이진 탐색 트리 중위 순회 결과\n");
    inorder(root);
    printf("\n\n");
    printf("이진 탐색 트리 높이 : %d\n\n", get_height(root));

    if(search_count(root, random_root, count) != NULL)
    {
        printf("이진 탐색 트리에서 임의의 수 %d 찾음\n", random_root);
        printf("이진 탐색 트리에서 임의의 수 탐색 횟수 : %d\n", search_count(root, random_root, count));
    }
    else
    {
        printf("이진 탐색 트리에서 임의의 수 %d 못 찾음\n", random_root);
    }
    return 0;
}
