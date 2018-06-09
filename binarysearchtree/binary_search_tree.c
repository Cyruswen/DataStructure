#include "binary_search_tree.h"

void TreeInit(TreeNode** pRoot){
    if(pRoot == NULL){
        //非法输入
        return;
    }
    if(*pRoot == NULL){
        //空树
        return;
    }
    *pRoot = NULL;
    return;
}
