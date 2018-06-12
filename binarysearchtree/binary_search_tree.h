#pragma once
#include <stdio.h>

typedef char TreeNodeType;

typedef struct TreeNode{
    TreeNodeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

void TreeInit(TreeNode** pRoot);

void TreeDestroy(TreeNode** pRoot);

void TreeInsert(TreeNode** pRoot, TreeNodeType to_insert);

void PreOrder(TreeNode* root);

void InOrder(TreeNode* root);
