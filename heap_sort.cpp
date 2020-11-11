#include <iostream>

/* Heap sort steps
--------------------------------------------------------------------------------
1. Build heap from unordered array.
2. Find max element from array.
3. Swap elements A[heap_size] with A[0], now max element is at the end of array.
4. Discard node n from heap, decrementing heap size.
5. New root may violate max heap but children are max heaps, call max_heapify().
*/

void print(int[], int);
void heap_sort(int[], int);
void build_heap(int[], int);

void max_heapify(int[], int, int);

int main()
{
	int array[] = {-10, -3, 20, 18, 9};
	int array_size = sizeof(array) / sizeof(*array);

	heap_sort(array, array_size);
	print(array, array_size);

	return 0;
}

//Prints the array
void print(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

//Performs heap sort
void heap_sort(int A[], int n)
{
	build_heap(A, n);

	//Heap sort
	for (int i = n; i > 0; i--)
	{
		std::swap(A[0], A[i - 1]);
		max_heapify(A, i - 1, 1);
	}
}

//Builds heap structures from given array
void build_heap(int A[], int n)
{
	for (int i = n / 2; i > 0; i--)
		max_heapify(A, n, i);
}

void max_heapify(int A[], int n, int i)
{
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left <= n && A[left - 1] > A[largest - 1])
		largest = left;

	if (right <= n && A[right - 1] > A[largest - 1])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i)
	{
		std::swap(A[i - 1], A[largest - 1]);
		max_heapify(A, n, largest);
	}
}