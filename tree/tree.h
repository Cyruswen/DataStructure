#pragma once
#include <math.h>
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
} TreeNode,*Tree;

void TreeInit(TreeNode** root);

void PerOrder(TreeNode* root);

TreeNode* CreateTreeNode(TreeNodeType value);

void InOrder(TreeNode* root);

void PostOrder(TreeNode* root);

void LevelOrder(TreeNode* root);

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node);

TreeNode* TreeClone(TreeNode* root);

void TreeDestroy(Tree* root);

size_t TreeSize(TreeNode* root);

size_t TreeSize2(TreeNode* root);

size_t TreeKLevelSize(TreeNode* root, size_t k);

size_t TreeHeight(TreeNode* root);

int IsCompleteBinTree(TreeNode* root);

void GetLevel(TreeNode* root, int level, SeqQueue* q);
