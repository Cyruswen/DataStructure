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

#if 0
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
#endif

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

void TestTreeDestroy(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    Tree root = TreeCreate(array, sizeof(array)-1, '#');
    TreeDestroy(&root);
    printf("execp:(nil), actual:%p\n", root);
}

//void TestTreeClone(){
//    TestType;
//    TreeNodeType array[] = "abd##eg###c#f##";
//    Tree root = TreeCreate(array, sizeof(array)-1, '#');
//    Tree new_root = TreeClone(root);
//    printf("层序遍历\n");
//    LevelOrder(new_root);
//    return;
//}

void TestTreeSize(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    Tree root = TreeCreate(array, sizeof(array)-1, '#');
    size_t size = TreeSize(root);
    printf("The size of tree is %zu\n",size);
    return;
}

void TestTreeSize2(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    Tree root = TreeCreate(array, sizeof(array)-1, '#');
    size_t size = TreeSize2(root);
    printf("The size of tree is %zu\n",size);
}

void TestKLevelSize(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    Tree root = TreeCreate(array, sizeof(array)-1, '#');
    size_t size = TreeKLevelSize(root, 2);
    printf("Kth's size is %zu\n",size);
}

void TestTreeHeight(){
    TestType;
   // TreeNodeType array[] = "abd##eg###c#f##";
    TreeNodeType array[] = "abd##e##c##";
    Tree root = TreeCreate(array, sizeof(array)-1, '#');

    printf("先序遍历结果：");
    PerOrder(root);
    printf("\n");

    printf("中序遍历结果：");
    InOrder(root);
    printf("\n");

    printf("后序遍历结果：");
    PostOrder(root);
    printf("\n");
    size_t size = TreeHeight(root);
    printf("The Tree's height is %zu\n",size);
}

void TestGetLevel(){
    TestType;
    SeqQueue q;
    SeqQueueInit(&q);
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array, sizeof(array)-1, '#');
    GetLevel(root, 4, &q);
    SeqQuquqPrint(&q, "该层元素");
}

void TestIsCompleteBinTree(){
    TestType;
    TreeNodeType array[] = "abd##eg###c#f##";
    TreeNode* root = TreeCreate(array, sizeof(array)-1, '#');
    int result = IsCompleteBinTree(root);
    printf("result is %d\n",result);
    TreeNodeType array2[] = "abd##e##c##";
    TreeNode* root2 = TreeCreate(array2, sizeof(array2)-1, '#');
    int result2 = IsCompleteBinTree(root2);
    printf("result2 is %d\n",result2);
    TreeNodeType array3[] = "abd##e##cf##g##";
    TreeNode* root3 = TreeCreate(array3, sizeof(array3)-1, '#');
    int result3 = IsCompleteBinTree(root3);
    printf("result3 is %d\n",result3);
    TreeNodeType array4[] = "abd##e##c#f##";
    TreeNode* root4 = TreeCreate(array4, sizeof(array4)-1, '#');
    int result4 = IsCompleteBinTree(root4);
    printf("result4 is %d\n",result4);
}

int main(){
    TestPreOrder();
    TestInOrder();
    TestPostOrder();
    //TestLevelOrder();
    TestCreate();
    TestTreeDestroy();
   // TestTreeClone();
    TestTreeSize();
    TestTreeSize2();
    TestKLevelSize();
    TestTreeHeight();
    TestGetLevel();
    TestIsCompleteBinTree();
    return 0;
}
