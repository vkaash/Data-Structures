#include "MinHeap.h"

int main() {
    MinHeap<int> heap;

    const int size = 6;
    int arr[size] = {2, 8, 15, 5, 1, 20};

    heap.buildHeap(arr, size);
    heap.printHeap();

    cout << heap.getMin() << endl;
    heap.removeMin();
    cout << heap.getMin() << endl;
    heap.removeMin();

    heap.insert(-10);
    cout << heap.getMin() << endl;

    return 0;
}