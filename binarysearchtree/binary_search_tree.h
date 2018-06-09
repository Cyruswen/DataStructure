#pragma once
#include <stdio.h>

typedef char TreeNodeType;

typedef struct TreeNode{
    TreeNodeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

void TreeInit(TreeNode** pRoot);
