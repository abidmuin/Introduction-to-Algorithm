#include <iostream>

void print(int[], int);
void counting_sort(int[], int);
int find_max(int[], int);

int main()
{
	int array[] = {3, 5, 1, 3};
	int array_size = sizeof(array) / sizeof(*array);

	counting_sort(array, array_size);

	return 0;
}

void print(int A[], int n)
{
	for (int i = 0; i < n; i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
}

void counting_sort(int A[], int n)
{
	int max_num = find_max(A, n);
	int count_array[max_num + 1] = {0};

	for (int i = 0; i < n; i++)
		count_array[A[i]]++;

	int old_index = 0;
	for (int j = 0; j < max_num + 1; j++)
	{
		if (count_array[j] > 0)
		{
			while (count_array[j])
			{
				A[old_index] = j;
				old_index++;
				count_array[j]--;
			}
		}
	}
	print(A, n);
}

int find_max(int A[], int n)
{
	int max_num = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] > max_num)
			max_num = A[i];
	}
	return max_num;
}