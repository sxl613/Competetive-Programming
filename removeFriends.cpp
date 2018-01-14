/*
	My C++ solution to the Remove Friends problem from 
	https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/practice-problems/algorithm/remove-friends-5/
	Uses std::list as a container.
*/






#include <list>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define getcx getchar_unlocked

void printListiBackwards(list<int>& f, int k)
{
	list<int>::reverse_iterator it; int i = 0;
	for (it = f.rbegin(); it != f.rend() && i < k; ++it)
	{
		printf("%d ", *it);
		i++;
	}
	cout << "\n";
}
inline void inp(int& n)
{
	n = 0;
	int ch = getcx(); int sign = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')	sign = -1;
		ch = getcx();
	}
	while (ch >= '0' && ch <= '9')
	{
		n = (n << 3) + (n << 1) + ch - '0';
		ch = getcx();
	}
	n = n*sign;
}
int main()
{
	int T, N, K, d;
	inp(T);

	for (int testi = 0; testi < T; testi++)
	{
		inp(N); inp(K);
		list<int> res;
		int friendsToDelete = K; int current, previous;
		inp(current); res.push_front(current);
		previous = current; int size = 1;
		int i = 1;
		while (i < N & friendsToDelete > 0)
		{
			inp(current);
			i++;
			while (previous < current & friendsToDelete > 0 & size > 0)
			{
				res.erase(res.begin());
				size--;
				friendsToDelete--;
				if (size != 0)
					previous = *(res.begin());
			}
			res.push_front(current);
			previous = *res.begin();
			size++;
		}
		while (i < N)
		{
			inp(current);
			res.push_front(current);
			i++;
		}
		printListiBackwards(res, N - K);
	}
	return 0;
}
