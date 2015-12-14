#include<iostream>
struct node
{
	int data;
	node* next;
	node(int payload)
	{
		this->data=payload;
		next=nullptr;
	}
};

class linkedlist
{
public:
	node* head;
	node* tail;
	linkedlist()
		:head(nullptr),tail(nullptr)
	{};

	void push_back(int value)
	{
		if(empty())
		{
			head=tail=new node(value);
		}
		else
		{
			node* new_node=new node(value);
			tail->next=new_node;
			tail=tail->next;
		}
	}

	int front()
	{
		if(empty())
			throw "this list is empty.";
		return head->data;
	}

	void pop_front()
	{
		if(empty())
			throw "this list is empty.";
		node* first_node=head;
		head=head->next;
		delete first_node;
	}

	bool empty()
	{
		return head==nullptr;
	}

	void output()
	{
		node* iterator=head;
		while(iterator)
		{
			std::cout<<iterator->data<<" ";
			iterator=iterator->next;
		}
		std::cout<<std::endl;
	}
};
linkedlist merge(linkedlist a,linkedlist b)
{
	linkedlist result;
	while(!(a.empty()&&b.empty()))
	{
		if(b.empty())
		{
			result.push_back(a.front());
			a.pop_front();
		}
		else if(a.empty())
		{
			result.push_back(b.front());
			b.pop_front();
		}

		else if(a.front()>b.front())
		{
			result.push_back(b.front());
			b.pop_front();
		}

		else
		{
			result.push_back(a.front());
			a.pop_front();			
		}
	}
	return result;
}
int main()
{
	linkedlist a,b;
	a.push_back(4);
	a.push_back(7);
	a.push_back(10);
	b.push_back(2);
	b.push_back(3);
	b.push_back(9);
	b.push_back(29);

	linkedlist result=merge(a,b);
	result.output();
	return 0;
}