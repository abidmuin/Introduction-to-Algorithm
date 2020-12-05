#include <iostream>

class node
{
public:
	int data;
	node *prev;
	node *next;
};

class linked_list
{
private:
	node *head;
	node *tail;

public:
	linked_list();
	void create_node(int);
	void traverse_forward();
	void traverse_backward();
	void insert_first(int);
	void insert_before(int, int);
	void insert_after(int, int);
	void delete_first();
	void delete_at(int);
	void delete_last();
};

//Constructor
linked_list::linked_list()
{
	head = NULL;
	tail = NULL;
}

//create node
void linked_list::create_node(int item)
{
	node *temp = new node;
	temp->data = item;
	temp->prev = temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		tail->next = head;
		head->prev = tail;
	}

	std::cout << "Inserting => " << item << std::endl;
}

//traverse forward
void linked_list::traverse_forward()
{
	node *current = new node;
	current = head;
	std::cout << "Traversing forward => ";
	if (current == NULL)
		std::cout << "NULL" << std::endl;
	while (current->next != head)
	{
		std::cout << current->data;
		if (current->next != NULL)
			std::cout << "-";
		current = current->next;
	}
	std::cout << current->data << std::endl;
}

//traverse backward
void linked_list::traverse_backward()
{
	node *current = new node;
	current = tail;
	std::cout << "Traversing backward => ";
	if (current == NULL)
		std::cout << "NULL" << std::endl;
	while (current->prev != tail)
	{
		std::cout << current->data;
		if (current->prev != NULL)
			std::cout << "-";
		current = current->prev;
	}
	std::cout << current->data << std::endl;
}

//insert first
void linked_list::insert_first(int item)
{
	std::cout << "Inserting at head => " << item << std::endl;
	node *temp = new node;
	temp->data = item;
	temp->prev = temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		temp->next = head;
		temp->prev = tail;
		head->prev = temp;
		head = temp;
		tail->next = head;
	}
}

//insert before
void linked_list::insert_before(int old_item, int item)
{
	node *new_item = new node;
	new_item->data = item;
	new_item->prev = new_item->next = NULL;

	node *temp = new node;
	temp = head;

	while (temp != NULL && temp->data != old_item)
		temp = temp->next;

	if (temp == head)
	{
		std::cout << "Inserting => " << item << " before " << old_item << std::endl;
		new_item->next = temp;
		temp->prev = new_item;
		head = new_item;
		head->prev = tail;
		tail->next = head;
		return;
	}

	std::cout << "Inserting => " << item << " before " << old_item << std::endl;

	new_item->prev = temp->prev;
	new_item->next = temp;
	temp->prev = new_item;
	new_item->prev->next = new_item;

	return;
}

//insert after
void linked_list::insert_after(int old_item, int item)
{
	node *new_item = new node;
	new_item->data = item;
	new_item->prev = new_item->next = NULL;

	node *temp = new node;
	temp = head;

	if (temp == NULL)
	{
		std::cout << "Linked list is empty!" << std::endl;
		return;
	}

	while (temp != NULL && temp->data != old_item)
		temp = temp->next;

	if (temp == tail)
	{
		std::cout << "Inserting => " << item << " after " << old_item << std::endl;
		temp->next = new_item;
		new_item->prev = temp;
		tail = new_item;
		tail->next = head;
		head->prev = tail;
		return;
	}

	std::cout << "Inserting => " << item << " after " << old_item << std::endl;

	new_item->next = temp->next;
	new_item->prev = temp;
	new_item->next->prev = new_item;
	temp->next = new_item;
}

//delete first
void linked_list::delete_first()
{
	if (head == NULL)
	{
		std::cout << "Linked list is empty!" << std::endl;
		return;
	}
	std::cout << "Deleting first item" << std::endl;
	node *temp = new node;
	temp = head;
	head = head->next;
	if (head != NULL)
		head->prev = tail;
	tail->next = head;
	delete temp;
}

//delete at
void linked_list::delete_at(int item)
{
	node *temp = new node;
	temp = head;

	while (temp != NULL && temp->data != item)
		temp = temp->next;

	if (temp == NULL)
	{
		std::cout << "List is empty or item doesn't exits!" << std::endl;
		return;
	}

	std::cout << "Deleting item => " << item << std::endl;

	if (temp == head)
		delete_first();

	if (temp == tail)
		delete_last();

	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	delete temp;
}

//delete last
void linked_list::delete_last()
{
	std::cout << "Deleting last item" << std::endl;
	node *temp = new node;
	temp = tail;
	tail = tail->prev;
	if (tail != NULL)
		tail->next = head;
	head->prev = tail;
	delete temp;
}

int main()
{
	linked_list test_obj;
	// test_obj.create_node(1);
	// test_obj.create_node(2);
	// test_obj.create_node(3);
	// test_obj.create_node(4);
	// test_obj.create_node(5);
	// test_obj.create_node(6);
	// test_obj.create_node(7);
	// test_obj.create_node(8);
	// test_obj.create_node(9);
	// test_obj.create_node(10);
	// test_obj.traverse_forward();
	// test_obj.traverse_backward();

	test_obj.create_node(3);
	test_obj.create_node(4);
	test_obj.insert_first(2);
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	test_obj.insert_before(2, 1);
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	test_obj.insert_after(3, 239);
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	test_obj.delete_first();
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	test_obj.delete_at(3);
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	test_obj.delete_last();
	test_obj.traverse_forward();
	test_obj.traverse_backward();

	return 0;
}