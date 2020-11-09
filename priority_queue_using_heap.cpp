#include <iostream>
#include <climits>

/* Priority Queue
---------------------------------------------
1. build_heap()
2. maximum() or minimum()
3. extract_max() or extract_min()
*/

void print(int[], int);
void build_heap(int[], int);
void min_heapify(int[], int, int);
int extract_min(int[]);
int heap_size = 0;

int main()
{
	int array[] = {-10, -3, 20, 18, 9};
	int array_size = sizeof(array) / sizeof(*array);
	heap_size = array_size;

	std::cout << "Given = ";
	print(array, array_size);

	build_heap(array, array_size);

	std::cout << "Sorted = ";
	print(array, array_size);

	std::cout << extract_min(array) << std::endl;
	std::cout << extract_min(array) << std::endl;
	std::cout << extract_min(array) << std::endl;
	std::cout << extract_min(array) << std::endl;
	std::cout << extract_min(array) << std::endl;
	std::cout << extract_min(array) << std::endl;

	return 0;
}

//Prints the array
void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

//Builds heap structures from given array
void build_heap(int a[], int n)
{
	for (int i = n / 2; i > 0; i--)
		min_heapify(a, n, i);
}

void min_heapify(int a[], int n, int i)
{
	int smallest = i;
	int left = 2 * i;
	int right = (2 * i) + 1;

	if (left <= n && a[left - 1] < a[smallest - 1])
		smallest = left;
	if (right <= n && a[right - 1] < a[smallest - 1])
		smallest = right;

	if (smallest != i)
	{
		std::swap(a[i - 1], a[smallest - 1]);
		min_heapify(a, n, smallest);
	}
}

int extract_min(int a[])
{
	//Heap underflow
	if (heap_size < 1){
		std::cout << "Heap underflow!" << std::endl;
		return INT_MAX;
	}

	int minimum = a[0];
	a[0] = a[heap_size - 1];
	heap_size--;

	min_heapify(a, heap_size, 1);

	return minimum;
}