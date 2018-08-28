#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "linkstack.h"
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

/////////////////////////////////////////////////////////////
//希尔排序
//时间复杂度：取决于步长序列，对于希尔排序，O(N ^ 2)
//如果选择一个最优序列，时间复杂度最高可达(1.3 ^ N)
//空间复杂度：O(1)
//稳定性：不稳定排序
////////////////////////////////////////////////////////////

//插入排序的改进版本
//分组式的插入排序
//假设步长是3  70 30 40 10 80 20 90 100 75 60
//第一组：70 10 90 60      10 60 70 90
//第二组：30 80 100        30 80 100
//第三组：40 20 75         20 40 75
//排序后：10 30 20 60 80 40 70 100 75 90

//假设步长为2
//第一组：10 20 80 70 75    10 20 70 75 80
//第二组：30 60 40 100 90   30 40 60 90 100
//排序后：10 30 20 40 70 60 75 90 80 100

//假设步长为1
//10 30 20 40 70 60 75 90 80 100
//排序后：10 20 30 40 60 70 75 80 90 100
//步长常选择： N/4, N/4, N/8, ...., 1

void ShellSort(int array[], int64_t size){
    if(size <= 1){
        return;
    }
    //此时我们使用希尔序列
    //此循环相当于先处理第一组的第一个数据，第二组的第一个数据，第三组第一个元素 第一组第二个元素......
    int64_t gap = size / 2;
    for(; gap > 0; gap /= 2){
        //第二重循环，进行插入排序
        int64_t bound = gap;// 此处相当于插入排序中的bound = 1
        for(; bound < size; ++bound){
            int bound_value = array[bound];
            //第三重循环，线性表的查找和搬运
            int64_t cur = bound;
            //此处cur -= gap 就是找到同组元素的上一个元素
            for(; cur >= gap; cur -= gap){
                if(array[cur - gap] > bound_value){
                    //进行搬运
                    array[cur] = array[cur - gap];
                }else{
                    //说明找到了
                    break;
                }
            }
            array[cur] = bound_value;
        }
    }
}


/////////////////////////////////////////////////////////////
//归并排序(递归)
//时间复杂度：O(N * logN)
//空间复杂度：O(N)
//稳定性：稳定排序
////////////////////////////////////////////////////////////

void _MergeArray(int array[], int64_t beg, int64_t mid,  int64_t end, int* tmp){
    int64_t cur1 = beg;
    int64_t cur2 = mid;
    int64_t tmp_index = beg;
    while(cur1 < mid && cur2 < end){
        if(array[cur1] < array[cur2]){
            tmp[tmp_index++] = array[cur1++];
        }else{
            tmp[tmp_index++] = array[cur2++];
        }
    }
    while(cur1 < mid){
        tmp[tmp_index++] = array[cur1++];
    }
    while(cur2 < end){
        tmp[tmp_index++] = array[cur2++];
    }
    //进行归并的时候处理的区间是 array[beg, end),
    //对应的会把这部分区间元素填充到 tmp[beg, end)
    memcpy(array + beg, tmp + beg, sizeof(int) * (end - beg));
    return;
}

void _MergeSort(int array[], int64_t beg, int64_t end, int* tmp){
    if(end - beg <= 1){
        //要么一个元素，要么没有元素，要么非法区间
        return;
    }
    int64_t mid = beg +(end - beg) / 2;
    //此时有了两个区间[beg, mid), [mid, end）
    _MergeSort(array, beg, mid, tmp);
    _MergeSort(array, mid, end, tmp);
    _MergeArray(array, beg, mid,  end, tmp);
    return;
}

void MergeSort(int array[], size_t size){
    int* tmp = (int*)malloc(sizeof(int) * size); 
    _MergeSort(array, 0, size, tmp);
    free(tmp);
}


/////////////////////////////////////////////////////////////
//归并排序
//时间复杂度：O(N * logN)
//空间复杂度：O(N)
//稳定性：稳定排序
////////////////////////////////////////////////////////////

void MergeSortByLoop(int array[], size_t size){
    if(size <= 1){
        return;
    }
    int* tmp = (int*)malloc(sizeof(int) * size);
    size_t gap = 1;
    for(; gap < size; gap *= 2){
        //在当前gap下，使用i帮助我们完成所有长度为gap的区间合并
        size_t i = 0;
        for(;i < size; i += 2 * gap){
            size_t beg = i;
            size_t mid = i + gap;
            //为了防止 mid超出数组最大size
            if(mid > size){
                mid = size;
            }
            size_t end = i + 2 * gap;
            if(end > size){
                end = size;
            }
            _MergeArray(array, beg, mid, end, tmp);
        }
    }
    free(tmp);
}


/////////////////////////////////////////////////////////////
//快速排序
//时间复杂度：O(N * logN) 最坏情况O(N ^ 2)
//空间复杂度：最坏O(N)
//稳定性：不稳定排序
////////////////////////////////////////////////////////////

//取一个基准值,倒腾，使前半部分小于基准值，后半部分大于基准值
//如果逆序，快排就不合适，递归可能很深，针对小数组不合适
// C++ STL std::sort
// 1.选取基准值的的方法：三个元素选中间值
// 2.当递归深度达到一定值的时候，就不在继续递归，而是把排序算法转化成堆排序
// 3.当递归达到一定程度之后，子区间的元素个数已经比较小，把排序算法变成插入排序

//交换法
int64_t Partion(int array[], int64_t beg, int64_t end){
    if(end - beg <= 1){
        return beg;
    }
    int64_t left = beg;
    int64_t right = end - 1;
    //数组的最后一个元素作基准元素
    int key = array[right];
    //从左往右找一个大于key的值
    while(left < right){
        while(left < right && array[left] <= key){
            ++left;
        }
        //从右往左找一个小于key的值
        while(left < right && array[right] >= key){
            --right;
        }
        if(left < right){
            Swap(&array[left], &array[right]);
        }
    }
    //最后把left指向的位置和基准值交换
    Swap(&array[left], &array[end - 1]);
    return left;
}

void  _QuickSort(int array[], int64_t beg, int64_t end){
    if(end - beg <= 1){
        return;
    }
    //[beg, mid),左半区间
    //[mid + 1, end]，右半区间
    //
    int64_t mid = Partion(array, beg, end);
    _QuickSort(array, beg, mid);
    _QuickSort(array, mid + 1, end);
}

void QuickSort(int array[], size_t size){
    _QuickSort(array, 0, size);
    return;
}

//挖坑法(哈哈)
int64_t Partion2(int array[], int64_t beg, int64_t end){
    if(end - beg <= 1){
        return beg;
    }
    int64_t left = beg;
    int64_t right = end - 1;
    //数组的最后一个元素作基准元素
    int key = array[right];
    while(left < right){
        while(left < right && array[left] <= key){
            ++left;
        }
        if(left < right){
            array[right--] = array[left];
        }
        while(left < right && array[right] >= key){
            --right;
        }
        //循环可以退出，意味着 right 指向了一个小于基准值的元素,
        //就可以把这个值填到刚才left 指向的坑里
        //一旦复制操作完成，right自身又成了一个坑
        if(left < right){
            array[left++] = array[right];
        }
    }
    //一旦left 和right重合，说明整个区间整理完毕
    //但是还有一个坑
    array[left] = key;
    return left;
}

//3.双指针前移法
//略

//非递归版本快速排序
void QuickSortByLoop(int array[], size_t size){
    if(size <= 1){
        return;
    }
    LinkStack stack;
    LinkStackInit(&stack);
    int64_t beg = 0;
    int64_t end = size;
    LinkStackPush(&stack, beg);
    LinkStackPush(&stack, end);
    while(1){
        int ret = LinkStackTop(&stack, &end);
        if(ret == 0){
            //栈为空，说明排序结束
            break;
        }
        LinkStackPop(&stack);
        LinkStackTop(&stack, &beg);
        if(end - beg <= 1){
            continue;
        }
        int64_t mid = Partion(array,beg, end);
        LinkStackPush(&stack, beg);
        LinkStackPush(&stack, mid);
        LinkStackPush(&stack, mid + 1);
        LinkStackPush(&stack, end);
    }
}

/////////////////////////////////////////////////////////////
//计数排序
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//奇数排序
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//睡眠排序：创建线程，根据退出时间
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
//猴子排序：无线猴子定理
/////////////////////////////////////////////////////////////
