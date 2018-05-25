#include <stdio.h>

/////////////////////////////////////////////////////////////
//冒泡排序
//时间复杂度：O(N ^ 2)
//空间复杂度：O(1)
//稳定性：稳定排序
////////////////////////////////////////////////////////////

void Swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

//升序
void BubbleSort(int array[], size_t size){
    if(size < 1){
        return;
    }
    //[0,bound) 表示有序元素
    //[bound, size)表示一个待排序空间
    size_t bound = 0;
    for(;bound < size; ++bound){
       size_t cur = size - 1; 
       for(; cur > bound; --cur){
           if(array[cur] < array[cur - 1]){
               Swap(&array[cur], &array[cur - 1]);
           }
       }
    }
    return;
}

/////////////////////////////////////////////////////////////
//选择排序
//时间复杂度：O(N ^ 2)
//空间复杂度：O(1)
//稳定性：不稳定排序
////////////////////////////////////////////////////////////

void SelectSort(int array[], size_t size){
    if(size <= 1){
        return;
    }
    //[0,bound) 表示有序元素
    //[bound, size)表示一个待排序空间
    size_t bound = 0;
    for(; bound < size; bound++){
        size_t cur = bound + 1;
        for(; cur < size; ++cur){
            if(array[bound] > array[cur]){
                Swap(&array[bound], &array[cur]);
            }
        }
    }
    return;
}

/////////////////////////////////////////////////////////////
//插入排序
//时间复杂度：O(N ^ 2)
//空间复杂度：O(1)
//稳定性：稳定排序
//特点：
// 1.数组元素个数比较小，执行效率比较快
// 2.如果数组基本有序，执行效率也很快
////////////////////////////////////////////////////////////

//把有序区间当做线性表，把当前bound指向的元素插入到有序区间这个线性表中
//1.定义好边界
//2.保存bound指向的元素
//3.从后往前去找一个合适的位置，一边找一边搬运

void InsertSort(int array[], size_t size){
    if(size <= 1){
        return;
    }
    //[0,bound) 表示有序元素
    //[bound, size)表示一个待排序空间
    //有序区间当成线性表
    size_t bound = 1;
    for(;bound < size; bound++){
        //保存意义是为了后面搬运
        //保存之后，array[bound]值就可以修改
        int bound_value = array[bound];
        //cur辅助我们搬运下标
        //从后往前遍历，找合适的位置放置 bound_value
        size_t cur = bound;
        for(;cur > 0; --cur){
            if(array[cur - 1] > bound_value){
                //进行搬运
                array[cur] = array[cur - 1];
            }else{
                //说明已经找到合适位置
                break;
            }
        }
        array[cur] = bound_value;
    }
    return;
}

/////////////////////////////////////////////////////////////
//堆排序
//时间复杂度：O(N * logN)
//空间复杂度：O(1)
//稳定性：不稳定排序
////////////////////////////////////////////////////////////

//堆的性质：
//1.完全二叉树
//2.如果是小堆，父节点的值小于子节点, 如果是大堆，父节点的值大于子节点的
//
//如果要实现升序排序，就要使用大堆
//
//步骤：
//1.基于数组建立一个堆；（如果升序，建立大堆）
//2.循环删除堆顶元素，删除完毕，排序完成

//方法一：
//把新元素放到素组末尾，上浮式调整(从前往后遍历)
//方法二：
//采用下沉式的调整。（从前往后遍历，起始位置就是堆从后往前遍历的第一个非叶
//子节点,找到其父节点，将其父节点和子节点比较决定是否调整）

void AdjustUp(int array[], size_t size, size_t index){
    (void)size;
    size_t child = index;
    size_t parent = (child - 1) / 2;
    while(child > 0){
        if(array[parent] < array[child]){
            Swap(&array[parent], &array[child]);
        }else{
            break;
        }
        child = parent;
        parent = (child - 1) / 2;
    }
}

void AdjustDown(int array[], size_t size, size_t index){
    size_t parent = index;
    size_t child = 2 * parent + 1;
    while(child < size){
        //我们要升序排序，需要建立大堆
        if(child + 1 < size && array[child + 1] > array[child]){
            child = child + 1;
        }
        if(array[child] > array[parent]){
            Swap(&array[parent], &array[child]);
        }
        parent = child;
        child = 2 * parent + 1;
    }
}

void HeapCreate(int array[], size_t size){
    if(size <= 1){
        return;
    }
#if 1
    size_t i = (size - 1 - 1) / 2;
    for(; i > 0; --i){
        AdjustDown(array, size, i);
    }
    AdjustDown(array, size, 0);
#else
    //上浮式调整
    //[0,bound)表示堆的有效区间
    size_t bound = 0;
    for(; bound <size; ++bound){
        AdjustUp(array, bound + 1, bound);
    }
#endif
}

//heap_size 表示当前数组中的哪部分元素是堆

void HeapPop(int array[], size_t heap_size){
    if(heap_size <= 1){
        return;
    }
    Swap(&array[0], &array[heap_size - 1]);
    AdjustDown(array, heap_size - 1, 0);
}

void HeapSort(int array[], size_t size){
    if(size <= 1){
        return;
    }
//1.基于数组建立一个堆；（如果升序，建立大堆）
    HeapCreate(array,size);
//2.循环删除堆顶元素，删除完毕，排序完成
    size_t i = 0;
    for(; i < size - 1; i++){
        //第二个参数表示数组中哪部分区间符合堆的规则
        //第一次删除之前，[0,size)都是堆
        //第二次删除之前，[0, size -1) 都是堆
        HeapPop(array, size - i);
    }
    return;
}

