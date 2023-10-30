//
//  AVL.c
//  AVL-BST
//
//  Created by 문지수 on 2019/12/06.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(x, y) ((x)>(y)?(x):(y))

typedef struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

int get_height(AVLNode *node)
{
    int height = 0;
    if(node!= NULL)
        height = 1 + max(get_height(node -> left), get_height(node -> right));
    return height;
}

int get_balance(AVLNode* node)
{
    if(node == NULL)
        return 0;
    return get_height(node -> left) - get_height(node -> right);
}

AVLNode* create_node(int key)
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

AVLNode *rotate_right(AVLNode *parent)
{
    AVLNode* child = parent -> left;
    parent -> left = child -> right;
    child -> right = parent;
    
    return child;
}

AVLNode *rotate_left(AVLNode *parent)
{
    AVLNode* child = parent -> right;
    parent -> right = child -> left;
    child -> left = parent;
    
    return child;
}

AVLNode* insert(AVLNode* node, int key)
{
    if(node == NULL)
        return(create_node(key));
    
    if(key < node -> key)
        node -> left = insert(node -> left, key);
    else if(key > node -> key)
        node -> right = insert(node -> right, key);
    else
        return node;
    
    int balance = get_balance(node);
    
    // LL
    if(balance > 1 && key < node -> left -> key)
        return rotate_right(node);
    
    // RR
    if(balance < -1 && key > node -> right -> key)
        return rotate_left(node);
    
    // LR
    if(balance > 1 && key > node -> left -> key)
    {
        node -> left = rotate_left(node -> left);
        return rotate_right(node);
    }
    
    // RL
    if(balance < -1 && key < node -> right -> key)
    {
        node -> right = rotate_right(node -> right);
        return rotate_left(node);
    }
    return node;
}

void pre_order(AVLNode *root)
{
    if(root != NULL)
    {
        printf("[%d]", root -> key);
        pre_order(root -> left);
        pre_order(root -> right);
    }
}

int main(void)
{
    AVLNode *root = NULL;
    
    srand(time(NULL));
    int random_node = 0;
    for(int i = 0 ; i < 10 ; i++)
    {
        random_node = rand()%100 + 1;
        root = insert(root, random_node);
    }    
    printf("전위 순회 결과 : \n");
    pre_order(root);
    printf("\n");
    printf("AVL 높이 : ");
    printf("%d", get_height(root));
    
    return 0;
}
