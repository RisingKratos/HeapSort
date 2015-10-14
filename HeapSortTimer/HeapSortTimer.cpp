#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[200000000];

void heapify(int pos, int n) {
	while (2 * pos + 1 < n) {

		int t = 2 * pos + 1;
		if (2 * pos + 2 < n && arr[2 * pos + 2] >= arr[t])
		{
			t = 2 * pos + 2;
		}
		if (arr[pos] < arr[t]) {
			swap(arr[pos], arr[t]);
			pos = t;
		}
		else break;

	}
}

void BuildHeap(int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		heapify(i, n);
	}
}
void heapSort(int n)
{
	BuildHeap(n);
	while (n>0)
	{
		swap(arr[0], arr[n - 1]);
		n--;
		heapify(0, n);
	}
}

int main()
{
	srand(time(NULL));
	int n;
	cin >> n;
	//test on the machine
	//n approximately is 500000
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand()%1000;
	}
	int timeSum = 0;
	cout << endl << "Time: ";
	for (int i = 0; i < 100; ++i) 
	{
		if (i % 12 == 0) 
		{
			cout << endl;
		}
		clock_t time = clock();
		heapSort(n);
		time = clock() - time;
		cout << (double)time / CLOCKS_PER_SEC << " ";
		timeSum += (double)time / CLOCKS_PER_SEC;
	}

	cout << timeSum / 100 << endl;
	return 0;
}
