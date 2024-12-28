#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class MaxHeap {
   private:
    // heapifyUp()t is meant to restore the
    // heap property going up from a node to the root.
    void heapifyUp(int i) {
        if (i <= 0)
            return;
        else if (h[parent(i)] < h[i]) {
            swap(h[i], h[parent(i)]);
            heapifyUp(parent(i));
        }
    }
    void heapifyDown(int i) {
        int lc = lchild(i);
        int rc = rchild(i);
        int imax = i;

        if (lc < size() && h[lc] > h[imax])
            imax = lc;
        if (rc < size() && h[rc] > h[imax])
            imax = rc;
        if (i != imax) {
            swap(h[i], h[imax]);
            heapifyDown(imax);
        }
    }

   public:
    vector<T> h;

    inline int parent(int i) {
        return (i - 1) / 2;
    }
    inline int lchild(int i) {
        return i * 2 + 1;
    }
    inline int rchild(int i) {
        return i * 2 + 2;
    }
    MaxHeap() {
        h.resize(0);
    }
    int size() {
        return h.size();
    }
    T getMax() {
        if (size() <= 0) {
            return -1;
        } else
            return h[0];
    }
    void insert(const T &key) {
        // Push elements into vector from the back
        h.push_back(key);
        // Store index of last value of vector in  variable i
        int i = size() - 1;
        // Restore heap property
        heapifyUp(i);
    }
    void removeMax() {
        if (size() == 1) {
            h.pop_back();
        } else if (size() > 1) {
            swap(h[0], h[size() - 1]);
            // Deletes last element
            h.pop_back();
            // Restore heap property
            heapifyDown(0);
        } else
            return;
    }
    void buildHeap(T arr[], int size) {
        // Copy elements of array into vector h
        copy(&arr[0], &arr[size], back_inserter(h));
        for (int i = (size - 1) / 2; i >= 0;
             i--) {  // All the parent node occurs before (n-1)/2 because for others their children will exceed bounds
            heapifyDown(i);
        }
    }
    void printHeap() {
        for (int i = 0; i <= size() - 1; i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }
};
