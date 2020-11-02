#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vec_size = 0;
	cout << "Vector size = ";
	cin >> vec_size;
	vector<int> v1, v2;
	cout << "Vector elements: ";
	for (int i = 0; i < vec_size; i++)
	{
		int temp = 0;
		cin >> temp;
		v1.push_back(temp);
	}
	v2 = v1;

	//Ascending order
	for (int j = 1; j < v1.size(); j++)
	{
		int key = 0, k = 0;
		key = v1[j];
		k = j - 1;
		//going left from key untill '0' index
		while (k >= 0 && v1[k] > key)
		{
			v1[k + 1] = v1[k];
			k--;
		}
		v1[k + 1] = key;
	}
	for (int l = 0; l < v1.size(); l++)
		cout << v1[l] << " ";

	//Descending order
	for (int m = 1; m < vec_size; m++)
	{
		int key = v2[m];
		int n = m - 1;
		//going left from key untill '0' index
		while (n >= 0 && v2[n] < key)
		{
			v2[n + 1] = v2[n];
			n--;
		}
		v2[n + 1] = key;
	}
	for (int o = 0; o < v2.size(); o++)
		cout << v2[o] << " ";

	return 0;
}