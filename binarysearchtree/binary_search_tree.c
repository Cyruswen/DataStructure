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
    }else if(to_insert < cur->data){
        TreeInsert(&cur->rchild, to_insert);
    }else{
        //如果要插入的元素值刚好和现在节点的值相等，有很多种处理方式
        //这里采取的是不允许二叉树中存在重复的元素
        //所以如果遇到插入的值刚好和现在结点的值相等的情况
        //就不采取任何操作，直接返回，插入失败
        //也可以采取其他的方式：
        //  1.可以把这个元素放到相等元素的左子树的最右边
        //  2.可以把这个元素放到相等元素的右子树的最左边
        return;
    }
    return;
}

void PreOrder(TreeNode* root){

}
