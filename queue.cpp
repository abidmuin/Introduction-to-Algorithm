#include <iostream>

#define queue_size 10

class queue
{
	int *array;
	int capacity;
	int front;
	int rear;
	int count;

public:
	queue(int size = queue_size);
	~queue();

	void enqueue(int);
	void dequeue();
	int peek();
	int size();
	bool is_empty();
	bool is_full();
};

//Constructor
queue::queue(int size)
{
	array = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

//Destructor
queue::~queue()
{
	delete[] array;
}

//Enqueue
void queue::enqueue(int item)
{
	if (is_full())
	{
		std::cout << "Queue overflow!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "Inserting=> " << item << std::endl;
		rear = (rear + 1) % capacity;
		array[rear] = item;
		count++;
	}
}

//Dequeue
void queue::dequeue()
{
	if (is_empty())
	{
		std::cout << "Queue underflow!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		std::cout << "Removing=> " << array[front] << std::endl;
		front = (front + 1) % capacity;
		count--;
	}
}

//Peek
int queue::peek()
{
	if (is_empty())
	{
		std::cout << "Queue underflow!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return array[front];
}

//Size
int queue::size()
{
	return count;
}

//is_full()
bool queue::is_full()
{
	if (size() == capacity)
		return true;
	return false;
}

//is_empty()
bool queue::is_empty()
{
	if (size() == 0)
		return true;
	return false;
}

int main()
{
	int x;
	queue q;
	q.enqueue(5);
	x = q.peek();
	std::cout << x << std::endl;
	q.dequeue();

	return 0;
}