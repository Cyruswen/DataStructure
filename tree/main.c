#include "tree.h"

//void TestInit(){
//    TreeNode* root;
//    TreeInit(&root);
//}
//
void TestPreOrder(){
    TestType;
    TreeNode* root;
    TreeInit(&root);
    TreeNode* a = CreateTreeNode('a');
    TreeNode* b = CreateTreeNode('b');
    TreeNode* c = CreateTreeNode('c');
    TreeNode* d = CreateTreeNode('d');
    TreeNode* e = CreateTreeNode('e');
    TreeNode* f = CreateTreeNode('f');
    TreeNode* g = CreateTreeNode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    root = a;
    printf("先序遍历结果:\n");
    PerOrder(a);
    printf("\n");
    return;
}


void TestInOrder(){
    TestType;
    TreeNode* root;
    TreeInit(&root);
    TreeNode* a = CreateTreeNode('a');
    TreeNode* b = CreateTreeNode('b');
    TreeNode* c = CreateTreeNode('c');
    TreeNode* d = CreateTreeNode('d');
    TreeNode* e = CreateTreeNode('e');
    TreeNode* f = CreateTreeNode('f');
    TreeNode* g = CreateTreeNode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    root = a;
    printf("后序遍历结果:\n");
    InOrder(a);
    printf("\n");
    return;
}

void TestPostOrder(){
    TestType;
    TreeNode* root;
    TreeInit(&root);
    TreeNode* a = CreateTreeNode('a');
    TreeNode* b = CreateTreeNode('b');
    TreeNode* c = CreateTreeNode('c');
    TreeNode* d = CreateTreeNode('d');
    TreeNode* e = CreateTreeNode('e');
    TreeNode* f = CreateTreeNode('f');
    TreeNode* g = CreateTreeNode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    root = a;
    printf("后序遍历结果:\n");
    PostOrder(a);
    printf("\n");
    return;
}


void TestLevelOrder(){
    TestType;
    TreeNode* root;
    TreeInit(&root);
    TreeNode* a = CreateTreeNode('a');
    TreeNode* b = CreateTreeNode('b');
    TreeNode* c = CreateTreeNode('c');
    TreeNode* d = CreateTreeNode('d');
    TreeNode* e = CreateTreeNode('e');
    TreeNode* f = CreateTreeNode('f');
    TreeNode* g = CreateTreeNode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    root = a;
    printf("后序遍历结果:\n");
    LevelOrder(a);
    printf("\n");
    return;
}

void TestCreate(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array, sizeof(array)-1, '#');
    printf("先序遍历结果：");
    PerOrder(root);
    printf("\n");

    printf("中序遍历结果：");
    InOrder(root);
    printf("\n");

    printf("后序遍历结果：");
    PostOrder(root);
    printf("\n");
    return;
}

int main(){
    TestPreOrder();
    TestInOrder();
    TestPostOrder();
    TestLevelOrder();
    TestCreate();
    return 0;
}
