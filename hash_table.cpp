#include <iostream>
#include <list>

class hash_table
{
private:
	int capacity;
	std::list<int> *table;

public:
	hash_table(int);
	void insert_item(int, int);
	void search_item(int);
	void delete_item(int);
	bool check_prime(int);
	int get_prime(int);
	int hash_function(int);
	void display_hash();
	~hash_table();
};

//Constructor
hash_table::hash_table(int size)
{
	this->capacity = size;
	table = new std::list<int>[capacity];
}

//insert_item
void hash_table::insert_item(int key, int data)
{
	int index = hash_function(key);
	table[index].push_back(data);
}

//search_item
void hash_table::search_item(int key)
{
	bool element_exists = false;
	int index = hash_function(key);
	std::list<int>::iterator it;

	for (it = table[index].begin(); it != table[index].end(); it++)
	{
		if (*it == key)
		{
			element_exists = true;
			std::cout << "The element => " << key << " is present in the hash table" << std::endl;
			return;
		}
	}
	std::cout << "The element => " << key << " is not present in the hash table" << std::endl;
}

//delete_item
void hash_table::delete_item(int key)
{
	int index = hash_function(key);

	std::list<int>::iterator it;
	for (it = table[index].begin(); it != table[index].end(); it++)
	{
		if (*it == key)
			break;
	}

	if (it != table[index].end())
		table[index].erase(it);
}

//check_prime
bool hash_table::check_prime(int n)
{
	if (n == 1 || n == 0)
		return false;
	for (int i = 2; i < n / 2; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

//get_prime
int hash_table::get_prime(int n)
{
	if (n % 2 == 0)
		n++;
	while (!check_prime(n))
		n += 2;
	return n;
}

//hash_function
int hash_table::hash_function(int key)
{
	return (key % capacity);
}

//display_hash
void hash_table::display_hash()
{
	for (int i = 0; i < capacity; i++)
	{
		std::cout << "table[" << i << "]";
		for (int j : table[i])
			std::cout << " --> " << j;
		std::cout << std::endl;
	}
}

//destructor
hash_table::~hash_table()
{
	delete[] table;
}

int main()
{
	int key[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int data[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int size = sizeof(key) / sizeof(*key);

	hash_table ht(10);

	for (int i = 0; i < size; i++)
		ht.insert_item(key[i], data[i]);

	ht.search_item(5);
	ht.display_hash();

	return 0;
}