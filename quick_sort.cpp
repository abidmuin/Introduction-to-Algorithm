#include <iostream>

void print(int[], int);
void quick_sort(int[], int, int);
int partition(int[], int, int);

int main()
{
	int array[] = {-10, -3, 20, 18, 9};
	int array_size = sizeof(array) / sizeof(*array);

	std::cout << "Given = ";
	print(array, array_size);

	quick_sort(array, 0, array_size-1);

	std::cout << "Sorted = ";
	print(array, array_size);

	return 0;
}

void print(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void quick_sort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}

int partition(int A[], int p, int r)
{
	int pivot = A[r];
	int i = (p - 1);
	for (int j = p; j < r; j++)
	{
		if (A[j] <= pivot)
		{
			i++;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1], A[r]);

	return i + 1;
}