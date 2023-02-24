#include "iostream"

using namespace std;

class	Node
{
Node 		*next; 
int		val;
friend class	Linked_List;

public:
	Node()
	{
		val = 0;
		next = NULL;
	}
	Node(int v)
	{
		val = v;
		next = NULL;
	}
	Node(int v, Node *p)
	{
		val = v;
		next = p;
	}
};

class	Linked_List
{
Node	*head;
int	size;

public:
	Linked_List()
	{
		head = new Node();
		size = 0;
	}
	
	void	append(int);
	void	show() const;
	// inline int len()
	int	len()
	{
		return (size);
	}
};

void	Linked_List::append(int val)
{
	Node	*node = new Node(val);

	if (!size)
		head->next = node;
	else
	{
		Node	*temp = head;

		while (temp->next)
			temp = temp->next; 
		temp->next = node;
	}
	++size;
}

void	Linked_List::show() const
{
	Node	*tmp = head->next;

	cout << "[";
	while (tmp != NULL)
	{
		cout << tmp->val << "," << ends;
		tmp = tmp->next;
	}
	cout << "\b\b]" << endl;
}

int	main()
{
	Linked_List a;

	a.append(1);
	a.append(2);
	a.append(3);
	a.append(4);
	
	a.show();
	cout << "Length: "<< a.len() << endl;

	a.append(5);
	a.append(6);
	a.append(7);
	a.show();

	cout << "Length: "<< a.len() << endl;
}
