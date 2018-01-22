#include<bits/stdc++.h>

/*
A simple min heap data stricture implemented in C++. Used to solidify understanding and for self-usage.
*/

#ifndef MinHeap_
#define MinHeap_
template <typename T> class MinHeap
{
public:

	// Constructors
	MinHeap();
	MinHeap(typename std::vector<T>::iterator b, typename std::vector<T>::iterator end);
	// Deconstructor
	~MinHeap();

	// Used to push a new element on top of the min heap. The operation makes
	//  sure the heap property is satisfied.
	void insert(const T& el);
	// Returns the top of the heap, without changing the heap in any way.
	const T& top();
	// Pops and returns the top of the heap. The opeartion makes sure
	// the heap property is satisfied.
	T pop();
	// Function used to make a heap out of the std::vector heap.
	void Heapify();
	// Sifts an element up the heap if it is smaller than its parent.
	// Used to maintain the heap property when a new element is inserted.
	void siftUp(size_t start, size_t end);
	// Sifts an element down the heap if it is bigger than its child.
	// Used to maintain the heap property.
	void siftDown(size_t start);
	// Used to remove the element at index key.
	void remove(size_t key);
	// Changes value at index key to val.
	void changeKey(size_t key, T val);
	// Returns the current heap size.
	size_t size() const;
	// Returns true if the heap is empty, false otherwise.
	bool empty() const;
	// Returns the index of the left child of the heap element node.
	size_t left(size_t node);
	// Returns the index of the right child of the heap element node.
	size_t right(size_t node);
	// Returns the index of the parent of the heap element node.
	size_t parent(size_t node);
	// Returns the iterator to heap's beginning
	typename std::vector<T>::iterator begin() const;

	// Returns the iterator to heap's end
	typename std::vector<T>::iterator end() const;



private:
	// std::vector is used to hold the heap elements.
	std::vector<T> heap;
	// Current size of the heap.
	size_t hSize;
};
template <typename T>
MinHeap<T>::MinHeap()
{
	hSize = 0;
}
template <typename T>
MinHeap<T>::MinHeap(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
	hSize = 0;
	for (typename std::vector<T>::iterator it = begin; it != end; it++)
	{
		heap.push_back(*it);
		hSize++;
	}
	Heapify();
}
template <typename T>
MinHeap<T>::~MinHeap()
{
	heap.clear();
}
template <typename T>
typename std::vector<T>::iterator MinHeap<T>::end() const
{
	return heap.end();
}
template <typename T>
typename std::vector<T>::iterator MinHeap<T>::begin() const
{
	return heap.begin();
}
template <typename T>
size_t MinHeap<T>::size() const
{
	return hSize;
}
template <typename T>
bool MinHeap<T>::empty() const
{
	return hSize == 0;
}
template <typename T>
void MinHeap<T>::insert(const T& el)
{
	heap.push_back(el);
	hSize++;
	siftUp(0, hSize - 1);
}


template <typename T>
void MinHeap<T>::remove(size_t key)
{
	if (key >= hSize)	return;
	changeKey(key, INT_MIN);
	pop();
}
template <typename T>
const T& MinHeap<T>::top()
{
	return heap[0];
}
template <typename T>
T MinHeap<T>::pop()
{
	T e = heap[0];
	heap[0] = heap[--hSize];
	siftDown(0);
	return e;
}
template <typename T>
void MinHeap<T>::changeKey(size_t key, T val)
{
	if (key >= hSize)	return;
	heap[key] = val;
	siftUp(0, key);
	siftDown(0);
}
template <typename T>
void MinHeap<T>::Heapify()
{
	int start = parent(hSize - 1);
	while (start >= 0)
	{
		siftDown(start);
		start--;
	}
}
template<typename T>
void MinHeap<T>::siftUp(size_t start, size_t end)
{
	size_t child = end; size_t p;
	while (child > start)
	{
		p = parent(child);
		if (heap[p] > heap[child])
		{
			T e = heap[p];
			heap[p] = heap[child];
			heap[child] = e;
			child = p;
		}
		else    return;
	}
}
template<typename T>
void MinHeap<T>::siftDown(size_t start)
{
	if (start >= hSize) return;
	size_t r = start; size_t child, swap;
	while (left(r) < hSize)
	{
		child = left(r);
		swap = r;
		if (heap[swap] > heap[child])   swap = child;
		if (child + 1 < hSize && heap[child + 1] < heap[swap])  swap = child + 1;
		if (swap == r)  return;
		else
		{
			T e = heap[r];
			heap[r] = heap[swap];
			heap[swap] = e;
			r = swap;
		}
	}
}


template <typename T>
size_t MinHeap<T>::parent(size_t node)
{
	return (node-1) / 2;
}
template <typename T>
size_t MinHeap<T>::left(size_t node)
{
	return 2 * node + 1;
}
template <typename T>
size_t MinHeap<T>::right(size_t node)
{
	return 2 * node + 2;
}

#endif
