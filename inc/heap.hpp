#ifndef HEAP_HH
#define HEAP_HH

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heap {
public:
    Heap() {
        size = 0;
    }

    void insert(T val) {
        heap.push_back(val);
        size++;
        heapify_up(size - 1);
    }

    void remove(T val) {
        for(int i = 0; i < size; i++) {
            if(heap[i] == val) {
                swap(heap[i], heap[size - 1]);
                heap.pop_back();
                size--;
                heapify_down(i);
                return;
            }
        }
    }

    bool search(T val) {
        for(int i = 0; i < size; i++) {
            if(heap[i] == val) {
                return true;
            }
        }
        return false;
    }

private:
    vector<T> heap;
    int size;

    // funkcja pomocnicza do przesuwania elementu w górę kopca
    void heapify_up(int i) {
        if(i == 0) {
            return;
        }
        int parent = (i - 1) / 2;
        if(heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            heapify_up(parent);
        }
    }

    void heapify_down(int i) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int min_index = i;
        if(left_child < size && heap[left_child] < heap[min_index]) {
            min_index = left_child;
        }
        if(right_child < size && heap[right_child] < heap[min_index]) {
            min_index = right_child;
        }
        if(min_index != i) {
            swap(heap[i], heap[min_index]);
            heapify_down(min_index);
        }
    }
};
#endif