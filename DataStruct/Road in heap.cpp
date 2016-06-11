#include <iostream>
#include <vector>

typedef struct Hnode {
    std::vector<int> array;
    int size;
    //堆中个数
//    int capacity;//堆最大容量
} *Heap;

//初始化数组生成最小堆
Heap InitHeap(std::vector<int> &array, int size) {
    for (int i = size / 2; i >= 1; i--) {
        int temp = array[i];
        int child, parent;
        for (parent = i; parent * 2 <= size; parent = child) {
            child = parent * 2;
            if (child <= size && array[child] > array[child + 1])
                child++;
            if (array[child] >= temp)
                break;
            else
                array[parent] = array[child];
        }
        array[child] = temp;
    }
    array[0] = array[1];
    Heap MinHeap = (Heap) new Hnode;
    MinHeap->array = array;
    MinHeap->size = size;
//    MinHeap->capacity = capacity;
    return MinHeap;
}

Heap Create() {
    Heap MinHeap = (Heap) new Hnode;
    std::vector<int> array = {0};
    MinHeap->array = array;
    MinHeap->size = 0;
    return MinHeap;
}

void Insert(Heap &heap, int num) {
    heap->array.push_back(num);
    heap->size++;
    int parent, child;
    for (child = heap->size, parent = child / 2; parent >= 1; child = parent, parent = child/2) {
        if (heap->array[child] < heap->array[parent]) {
            int temp = heap->array[parent];
            heap->array[parent] = heap->array[child];
            heap->array[child] = temp;
        }
        else
            break;
    }
}

void Road(Heap &MinHeap, std::vector<int> &nodes, int M) {
    for (int i = 0; i < M; ++i) {
        int start = nodes[i];
        for (int j = start; j > 0; j /= 2) {
            if (j != 1)
                std::cout << MinHeap->array[j] << " ";
            else
                std::cout << MinHeap->array[j] << std::endl;
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    Heap MinHeap = Create();
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        Insert(MinHeap, num);
    }
    std::vector<int> nodes(M, 0);
    for (int j = 0; j < M; ++j) {
        std::cin >> nodes[j];
    }
    Road(MinHeap, nodes, M);
    return 0;
}