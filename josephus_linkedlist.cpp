#include<iostream>
struct node
{
	int payload;
	node* next;
	node(int payload)
	{
		this->payload = payload;
	}
};
class joseph_circle
{
	node* tail;
	node* eliminate_ptr;
public:
	joseph_circle()
	{
		tail = nullptr;
	}
	void add(int value)
	{
		if (tail == nullptr)
		{
			tail = new node(value);
			tail->next = tail;
		}
		else
		{
			node* new_node = new node(value);
			new_node->next = tail->next;
			tail->next = new_node;
			tail = new_node;
		}
	}
	void eliminate(int step)
	{
		node* p = tail;
		while (p != nullptr && p->next != p)
		{
			for (int i = 0;i < step - 1;i++)
			{
				p = p->next;
			}
			node* eliminate_node = p->next;
			p->next = p->next->next;
			if (eliminate_node == tail)
				tail = p;
			std::cout << "deleting:" << eliminate_node->payload << std::endl;
			delete eliminate_node;
			output();
		}
	}
	void output()
	{
		node* p = tail;
		while (p != nullptr)
		{
			p = p->next;
			std::cout << p->payload << " ";
			if (p == tail)
				break;
		}
		std::cout << std::endl;
	}
};
int main()
{
	joseph_circle circle;
	for (int i = 0;i < 6;i++)
	{
		circle.add(i);
	}
	circle.eliminate(3);
	return 0;
}