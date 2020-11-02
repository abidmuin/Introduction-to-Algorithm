#include <iostream>
#include <vector>

int main()
{
	int vec_size = 0;
	std::cout << "Size = ";
	std::cin >> vec_size;
	std::vector<int> v;
	std::cout << "Elements: ";
	for (int i = 0; i < vec_size; i++)
	{
		int temp = 0;
		std::cin >> temp;
		v.push_back(temp);
	}

	//Ascending order
	for (int j = 1; j < v.size(); j++)
	{
		int key = 0, k = 0;
		key = v[j];
		k = j - 1;
		//going left from key untill '0' index
		while (k >= 0 && v[k] > key)
		{
			v[k + 1] = v[k];
			k--;
		}
		v[k + 1] = key;
	}
	std::cout << "Ascending: ";
	for (int l = 0; l < v.size(); l++)
		std::cout << v[l] << " ";
	std::cout << std::endl;

	//Descending order
	for (int m = 1; m < vec_size; m++)
	{
		int key = v[m];
		int n = m - 1;
		//going left from key untill '0' index
		while (n >= 0 && v[n] < key)
		{
			v[n + 1] = v[n];
			n--;
		}
		v[n + 1] = key;
	}
	std::cout << "Descending: ";
	for (int p = 0; p < v.size(); p++)
		std::cout << v[p] << " ";
	std::cout << std::endl;
	return 0;
}