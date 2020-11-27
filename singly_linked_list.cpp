#include <iostream>

//node class
class node
{
public:
	int data;
	node *next;
};

//linked list class
class linked_list
{
private:
	node *head, *tail;

public:
	linked_list();
	void create_node(int);
	void display();
	void insert_first(int);
	void insert_position(int, int);
	void delete_first();
	void delete_position(int);
	void delete_last();
};

//constructor
linked_list::linked_list()
{
	head = NULL;
	tail = NULL;
}

//create_node
void linked_list::create_node(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = tail->next;
	}

	std::cout << "Inserting => " << item << std::endl;
}

//display
void linked_list::display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

//insert_first
void linked_list::insert_first(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->next = head;
	head = temp;

	std::cout << "Inserting => " << item << " at head." << std::endl;
}

//insert_position
void linked_list::insert_position(int position, int item)
{
	node *previous = new node;
	node *current = new node;
	node *temp = new node;

	current = head;

	for (int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}

	temp->data = item;
	previous->next = temp;
	temp->next = current;

	std::cout << "Inserting => " << item << " at " << position << " index." << std::endl;
}

//delete_first
void linked_list::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	std::cout << "Deleting => " << temp->data << std::endl;
	delete temp;
}

//delete_position
void linked_list::delete_position(int position)
{
	node *current = new node;
	node *previous = new node;
	current = head;
	for (int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	std::cout << "Deleting from index => " << position << std::endl;
}

//delete last
void linked_list::delete_last()
{
	node *current = new node;
	node *previous = new node;
	current = head;
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	tail = previous;
	previous->next = NULL;
	delete current;
	std::cout << "Deleting last element." << std::endl;
}

int main()
{
	linked_list test_obj;
	test_obj.create_node(1);
	test_obj.create_node(2);
	test_obj.create_node(3);
	test_obj.create_node(4);
	test_obj.create_node(5);
	test_obj.create_node(6);
	test_obj.create_node(7);
	test_obj.create_node(8);
	test_obj.create_node(9);
	test_obj.create_node(10);
	test_obj.display();

	test_obj.delete_first();
	test_obj.display();

	test_obj.delete_last();
	test_obj.display();

	test_obj.delete_position(3);
	test_obj.display();

	test_obj.insert_first(2473);
	test_obj.display();

	test_obj.insert_position(7, 239);
	test_obj.display();

	return 0;
}