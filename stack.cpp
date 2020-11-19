#include <iostream>

#define stack_size 10

//Class for stack

class stack
{
	int *array;
	int top;
	int capacity;

public:
	stack(int size = stack_size);
	~stack();

	void push(int);
	int pop();
	int peek();
	int size();
	bool is_empty();
	bool is_full();
};

//Constructor
stack::stack(int size)
{
	array = new int[size];
	capacity = size;
	top = -1;
}

//Destructor
stack::~stack()
{
	delete[] array;
}

//Push
void stack::push(int x)
{
	if (is_full())
	{
		std::cout << "Stack overflow!" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << "Pushed=> " << x << std::endl;
	array[++top] = x;
}

//Pop
int stack::pop()
{
	if (is_empty())
	{
		std::cout << "Stack underflow!" << std::endl;
	}
	std::cout << "Popped=> " << peek() << std::endl;
	return array[top--];
}

//Peek
int stack::peek()
{
	if (!is_empty())
		return array[top];
	else
		exit(EXIT_FAILURE);
}

//Size
int stack::size()
{
	return top + 1;
}

//Check if stack is empty or not
bool stack::is_empty()
{
	return top == -1;
	//return size() == 0;
}

//Check if stack is full or not
bool stack::is_full()
{
	return top == capacity - 1;
	//return size() == capacity;
}

int main()
{
	int x = 0;

	stack st;

	x = st.size();
	std::cout << "Size=> " << x << std::endl;

	st.push(3);
	st.push(1);
	st.push(12);
	st.push(23);
	st.push(44);
	st.push(53);
	st.push(0);
	st.push(-1);
	st.push(-42);
	st.push(0);
	st.push(-100);

	x = st.peek();
	std::cout << "Top=> " << x << std::endl;

	st.pop();
	st.pop();

	if (st.is_empty())
		std::cout << "Stack is empty!" << std::endl;
	else
		std::cout << "Stack is not empty!" << std::endl;

	x = st.size();
	std::cout << "Size=> " << x << std::endl;

	if (st.is_full())
		std::cout << "Stack is full!" << std::endl;
	else
		std::cout << "Stack is not full!" << std::endl;

	return 0;
}