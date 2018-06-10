#include "binary_search_tree.h"
#include <stdlib.h>

void TreeInit(TreeNode** pRoot){
    if(pRoot == NULL){
        //非法输入
        return;
    }
    *pRoot = NULL;
    return;
}

void TreeNodeDestory(TreeNode* node){
    free(node);
}

void TreeDestroy(TreeNode** pRoot){
    if(pRoot == NULL){
        //非法输入
        return;
    }
    if(*pRoot == NULL){
        return;
    }
    TreeNode* root = *pRoot;
    TreeDestroy(&root->lchild);
    TreeDestroy(&root->rchild);
    TreeNodeDestory(root);
    *pRoot = NULL;
    return;
}

TreeNode* CreateTreeNode(TreeNodeType value){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

void TreeInsert(TreeNode** pRoot, TreeNodeType to_insert){
    if(pRoot == NULL){
        //非法输入
        return;
    }
    if(*pRoot == NULL){
        //空树,将节点直接插入
        TreeNode* new_node = CreateTreeNode(to_insert);
        *pRoot = new_node;
        return;
    }
    //若不为空树，遍历插入
    TreeNode* cur = *pRoot;
    if(to_insert < cur->data){
        TreeInsert(&cur->lchild, to_insert);
    }else if()
    
}
