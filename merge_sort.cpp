#include <iostream>
#include <climits>

void print(int A[], int);
void merge_sort(int A[], int, int);
void merge(int A[], int, int, int);

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int array[] = {-10, -3, 20, 18, 9};
	int array_size = sizeof(array) / sizeof(*array);

	std::cout << "Given array : ";
	print(array, array_size);
	std::cout << std::endl;

	merge_sort(array, 0, array_size - 1);

	std::cout << "Sorted array : ";
	print(array, array_size);

	return 0;
}

void print(int A[], int a_size)
{
	for (int i = 0; i < a_size; i++)
		std::cout << A[i] << " ";
}

void merge_sort(int A[], int l, int r)
{
	if (l < r)
	{
		int m = l + ((r - l) / 2);
		merge_sort(A, l, m);
		merge_sort(A, m + 1, r);

		merge(A, l, m, r);
	}
}

void merge(int A[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m;
	//Dynamically array allocation
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];

	//For ascending order
	// L[n1] = INT_MAX;
	// R[n2] = INT_MAX;

	//For descending order
	L[n1] = INT_MIN;
	R[n2] = INT_MIN;

	for (int i = 0; i < n1; i++)
		L[i] = A[l + i];

	for (int j = 0; j < n2; j++)
		R[j] = A[m + 1 + j];

	int x = 0, y = 0, z = l;

	//Ascending order
	// while (z <= r)
	// {
	// 	if (L[x] <= R[y])
	// 	{
	// 		a[z] = L[x];
	// 		x++;
	// 	}
	// 	else
	// 	{
	// 		a[z] = R[y];
	// 		y++;
	// 	}
	// 	z++;
	// }

	//Descending order
	while (z <= r)
	{
		if (L[x] >= R[y])
		{
			A[z] = L[x];
			x++;
		}
		else
		{
			A[z] = R[y];
			y++;
		}
		z++;
	}
}