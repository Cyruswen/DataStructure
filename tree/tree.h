#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "seqqueue.h"

//#define TestType printf("\n################################## %s ####################################\n",__FUNCTION__)

typedef char TreeNodeType;

typedef struct TreeNode {
    TreeNodeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
} TreeNode;

void TreeInit(TreeNode** root);

void PerOrder(TreeNode* root);

TreeNode* CreateTreeNode(TreeNodeType value);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

void LevelOrder(TreeNode* root);

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node);

TreeNode* TreeClone(TreeNode* root);

void TreeDestroy(TreeNode* root);
