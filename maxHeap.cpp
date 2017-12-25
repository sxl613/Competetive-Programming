#include<bits/stdc++.h>
#include<climits>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MaxHeap{
    int* arr;
    int capacity;
    int size;
    public:
        MaxHeap(int capacity);
        void MaxHeapify(int root);
        int getMax()    {return arr[0];};
        int extractMax();
        void changeKey(int key, int value);
        void insert(int value);
        void remove(int i);
        int left(int node) {return 2*node + 1;};
        int right(int node) {return 2*node + 2;};
        int parent(int node) {return node/2;};
};

MaxHeap::MaxHeap(int c)
{
    size = 0;
    capacity = c;
    arr = new int[c];
}

void MaxHeap::MaxHeapify(int root)
{
    int l = left(root);
    int r = right(root);
    int s = root;
    if (l < size && arr[l] > arr[s])  s = l;
    if (r < size && arr[r] > arr[s])  s = r;
    if (s != root)
    {
        swap(&arr[s], &arr[root]);
        MaxHeapify(s);
    }
}

int MaxHeap::extractMax()
{
    int e = arr[0];
    arr[0] = arr[size-1];
    size--;
    MaxHeapify(0);
    return e;
}
void MaxHeap::changeKey(int key, int value)
{
    if (key > size) return;
    arr[key] = value;
    int i = key;
    while (i != 0 && arr[i] > arr[parent(i)])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::insert(int value)
{
    if (size == capacity)   return;
    arr[size] = value;
    int i = size;
    size++;
    while (i != 0 && arr[i] > arr[parent(i)])
    {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::remove(int key)
{
    changeKey(key, INT_MAX);
    extractMax();
}


int main()
{
    return 0;
}
