#include "tree.h"

void TreeInit(TreeNode** root){
    if(root == NULL){
        return;
    }
    *root = NULL;
}

//先序遍历
void PerOrder(TreeNode* root){
    if(root == NULL){
        //printf("# ");
        return;
    }
    printf("%c ", root->data);
    PerOrder(root->lchild);
    PerOrder(root->rchild);
}

TreeNode* CreateTreeNode(TreeNodeType value){
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

void InOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    InOrder(root->lchild);
    printf("%c ",root->data);
    InOrder(root->rchild);
}

void PostOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    PostOrder(root->lchild);
    PostOrder(root->rchild);
    printf("%c ",root->data);
    return;
}

void LevelOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    SeqQueue q;
    SeqQueueInit(&q);
   //先把根结点插入队列
    SeqQueuePush(&q, root);
   //循环取队首元素
   TreeNode* cur = NULL;
   while(SeqQueueFront(&q, &cur)){
       //访问队首元素并出队列
       printf("%c ", cur->data);
       SeqQueuePop(&q);
       //将队首元素的左子树节点右子树节点依次入队列
       if(cur->lchild != NULL){
           SeqQueuePush(&q, cur->lchild);
       }
       if(cur->rchild != NULL){
           SeqQueuePush(&q, cur->rchild);
       }
       //进入下一次循环，直到队列为空，说明遍历完了
   }
}

TreeNode* _TreeCreate(TreeNodeType array[], size_t size, size_t* index, TreeNodeType null_node){
    if(index == NULL){
        //非法输入
        return NULL;
    }
    if(*index >= size){
        //构建完成
        return NULL;
    }
    if(array[*index] == null_node){
        //是空节点
        return NULL;
    }
    TreeNode* new_node = CreateTreeNode(array[*index]);
    ++(*index);
    new_node->lchild = _TreeCreate(array, size, index, null_node);
    ++(*index);
    new_node->rchild = _TreeCreate(array, size, index, null_node);
    return new_node;
}

TreeNode* TreeCreate(TreeNodeType array[], size_t size, TreeNodeType null_node){
   //当前读到了数组中第几个元素 
    size_t index = 0;
    TreeNode* new_node = _TreeCreate(array, size, &index, null_node);
    return new_node;
}

void DestroyTreeNode(Tree root){
    if(root == NULL){
        return;
    }
    free(root);
    return;
}

void TreeDestroy(Tree* root){
    if(root == NULL){
        return;
    }
    if(*root == NULL){
        return;
    }
    TreeDestroy(&(*root)->lchild);
    TreeDestroy(&(*root)->rchild);
    DestroyTreeNode(*root);
    *root = NULL;
}

TreeNode* TreeClone(TreeNode* root){
    if(root == NULL){
        return NULL;
    }
    TreeNode* new_node = CreateTreeNode(root->data);
    new_node->lchild = TreeClone(root->lchild);
    new_node->rchild = TreeClone(root->rchild);
    return new_node;
}

size_t TreeSize(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + TreeSize(root->lchild) + TreeSize(root->rchild);
}

void _TreeSize(TreeNode* root, size_t* size){
    if(root == NULL || size == NULL){
        return;
    }
    (*size)++;
    _TreeSize(root->lchild, size);
    _TreeSize(root->rchild, size);
    return;
}

size_t TreeSize2(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    size_t size = 0;
    _TreeSize(root, &size);
    return size;
}
