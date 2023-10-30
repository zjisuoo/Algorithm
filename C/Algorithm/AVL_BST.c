//
//  AVL_BST.c
//  AVL-BST
//
//  Created by 문지수 on 2019/11/30.
//  Copyright © 2019 문지수. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(x, y) ((x)>(y)?(x):(y))

// AVL
typedef int element;
typedef struct AVLNode
{
    element key;
    struct AVLNode* left, * right;
} AVLNode;

// BST
typedef int element;
typedef struct TreeNode
{
    element key;
    struct TreeNode* left, * right;
} TreeNode;

// AVL
int get_height_a(AVLNode* node)
{
    int height = 0;
    if (node != NULL)
        height = 1 + max(get_height_a(node->left), get_height_a(node->right));
    return height;
}

int get_balance(AVLNode* node)
{
    if (node == NULL)
        return 0;
    return get_height_a(node->left) - get_height_a(node->right);
}

int search_count_a(AVLNode* node, int key, int count_a)
{
    count_a++;
    if (node == NULL)
        return NULL;
    if (key == node->key)
    {
        return count_a;
    }
    else if (key < node->key)
    {
        return search_count_a(node->left, key, count_a);
    }
    else
    {
        return search_count_a(node->right, key, count_a);
    }
}

AVLNode* create_node(int key)
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

AVLNode* rotate_right(AVLNode* parent)
{
    AVLNode* child = parent->left;
    parent->left = child->right;
    child->right = parent;

    return child;
}

AVLNode* rotate_left(AVLNode* parent)
{
    AVLNode* child = parent->right;
    parent->right = child->left;
    child->left = parent;

    return child;
}

AVLNode* insert(AVLNode* node, int key)
{
    if (node == NULL)
        return(create_node(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    int balance = get_balance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rotate_right(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return rotate_left(node);

    // LR
    if (balance > 1 && key > node->left->key)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // RL
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

void pre_order(AVLNode* root_a)
{
    if (root_a != NULL)
    {
        printf("[%d]", root_a->key);
        pre_order(root_a->left);
        pre_order(root_a->right);
    }
}

// BST 

int search_count_b(TreeNode* node, int key, int count_b)
{
    count_b++;
    if (node == NULL)
        return NULL;
    if (key == node->key)
    {
        return count_b;
    }
    else if (key < node->key)
    {
        return search_count_b(node->left, key, count_b);
    }
    else
    {
        return search_count_b(node->right, key, count_b);
    }
}

TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    return node;
}

TreeNode* min_value_node(TreeNode* node)
{
    TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

TreeNode* delete_node(TreeNode* root_b, int key)
{
    if (root_b == NULL)
        return root_b;
    if (key < root_b->key)
        root_b->left = delete_node(root_b->left, key);
    else if (key > root_b->key)
        root_b->right = delete_node(root_b->right, key);
    else
    {
        if (root_b->left == NULL)
        {
            TreeNode* temp = root_b->right;
            free(root_b);
            return temp;
        }
        else if (root_b->right == NULL)
        {
            TreeNode* temp = root_b->left;
            free(root_b);
            return temp;
        }
        TreeNode* temp = min_value_node(root_b->right);
        root_b->key = temp->key;
        root_b->right = delete_node(root_b->right, temp->key);
    }
    return root_b;
}

void inorder(TreeNode* root_b)
{
    if (root_b)
    {
        inorder(root_b->left);
        printf("[%d]", root_b->key);
        inorder(root_b->right);
    }
}

int get_height_b(TreeNode* root_b)
{
    int height = 0;
    if (root_b != NULL)
        height = 1 + max(get_height_b(root_b->left), get_height_b(root_b->right));

    return height;
}

int main(void)
{
    float height_avg_a = 0, height_avg_b = 0;
    int height_sum_a = 0, height_sum_b = 0;
    float count_avg_a = 0, count_avg_b = 0;
    int count_sum_a = 0, count_sum_b = 0;

    printf("AVL, BST 트리 생성 시작\n");
    for (int a = 0; a < 100; a++)
    {
        AVLNode* root_a = NULL;
        TreeNode* root_b = NULL;
        TreeNode* tmp = NULL;
        int count_a = 0;
        int count_b = 0;

        printf("%d 번째 트리 생성 중...\n", (a + 1));
        srand(time(NULL));
        int random_node = 0;
        for (int i = 0 ; i < 100 ; i++) // 노드 수 설정
        {
            random_node = rand() % 10000 + 1;
            root_a = insert(root_a, random_node);
            root_b = insert_node(root_b, random_node);
        }

        height_sum_a += get_height_a(root_a);
        if (search_count_a(root_a, random_node, count_a) != NULL)
        {
            count_sum_a += (int)search_count_a(root_a, random_node, count_a);
        }


        height_sum_b += get_height_b(root_b);
        if (search_count_b(root_b, random_node, count_b) != NULL)
        {
            count_sum_b += (int)search_count_b(root_b, random_node, count_b);
        }
    }
    height_avg_a = height_sum_a / 100.0;
    height_avg_b = height_sum_b / 100.0;
    count_avg_a = count_sum_a / 100.0;
    count_avg_b = count_sum_b / 100.0;

    printf("AVL, BST 트리 생성 완료\n");
    printf("Height Average AVL = %.2f\n", height_avg_a);
    printf("Height Average BST = %.2f\n", height_avg_b);
    printf("Search Count Average AVL = %.2f\n", count_avg_a);
    printf("Search Count Average BST = %.2f\n", count_avg_b);

    /*
    printf("AVL 전위 순회 결과 : \n");
    pre_order(root_a);
    printf("\n");
    printf("BST 중위 순회 결과 : \n");
    inorder(root_b);
    printf("\n");
    */
    /*
    printf("AVL 높이 : ");
    printf("%d", get_height_a(root_a));
    printf("\n");
    if(search_count_a(root_a, random_node, count_a) != NULL)
    {
        printf("AVL 임의의 수 %d 찾음\n", random_node);
        printf("AVL 임의의 수 탐색 횟수 : %d\n", search_count_a(root_a, random_node, count_a));
    }
    else
    {
        printf("이진 탐색 트리에서 임의의 수 %d 못 찾음\n", random_node);
    }
    printf("\n");
    printf("BST 높이 : ");
    printf("%d", get_height_b(root_b));
    printf("\n");
    if(search_count_b(root_b, random_node, count_b) != NULL)
    {
        printf("BST 임의의 수 %d 찾음\n", random_node);
        printf("BST 임의의 수 탐색 횟수 : %d\n", search_count_b(root_b, random_node, count_b));
    }
    else
    {
        printf("이진 탐색 트리에서 임의의 수 %d 못 찾음\n", random_node);
    }
    */
    return 0;
}




