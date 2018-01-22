#include "MinHeap.cpp"
#include <bits/stdc++.h>

template <typename T>
void Heapsort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end)
{
    MinHeap<T> H(begin, end);
    for (typename std::vector<T>::iterator it = begin; it != end; it++)
    {
        *it = H.pop();
    }
}
