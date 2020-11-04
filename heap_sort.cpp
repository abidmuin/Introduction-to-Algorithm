#include <iostream>

/* Heap sort steps
--------------------------------------------------------------------------------
1. Build heap from unordered array.
2. Find max element from array.
3. Swap elements A[heap_size] with A[0], now max element is at the end of array.
4. Discard node n from heap, decrementing heap size.
5. New root may violate max heap but children are max heaps, call max_heapify().
*/

void print(int a[], int);
void build_heap(int a[], int);
void heap_sort(int a[], int);
void max_heapify(int a[], int, int);

int main()
{
	int array[] = {17, 9, 20, 11, 200, 35};

	int array_size = sizeof(array) / sizeof(*array);

	heap_sort(array, array_size);

	print(array, array_size);

	return 0;
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void build_heap(int a[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		max_heapify(a, n, i);
}

void heap_sort(int a[], int n)
{

	build_heap(a, n);

	//Heap sort
	for (int i = n; i >= 1; i--)
	{
		std::swap(a[0], a[i - 1]);

		//Max heapify
		max_heapify(a, i - 1, 1);
	}
}

void max_heapify(int a[], int n, int i)
{
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left <= n && a[left - 1] > a[largest - 1])
		largest = left;

	if (right <= n && a[right - 1] > a[largest - 1])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i)
	{
		std::swap(a[i - 1], a[largest - 1]);
		max_heapify(a, n, largest);
	}
}