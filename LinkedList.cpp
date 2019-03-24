#include <iostream>
using namespace std;

struct Node
{
	string elem;
	Node *next;
};

class LinkedList
{

  public:
	LinkedList() : head(NULL) {}
	bool isEmpty() const { return head == NULL; }
	string front() const;
	string back() const;
	void insertFront(const string &e);
	void removeFront();
	void insertBack(const string &e);
	void removeBack();
	~LinkedList();

  private:
	Node *head;
};

void LinkedList::insertFront(const string &e)
{

	Node *temp = new Node;
	temp->elem = e;
	temp->next = NULL;

	if (isEmpty())
	{

		head = temp;
	}
	else
	{

		temp->next = head;
		head = temp;
	}
}

void LinkedList::removeFront()
{

	if (isEmpty())
		printf("Error! List Empty\n");
	else
	{

		auto temp = head;
		head = head->next;
		delete temp;
		temp = NULL;
	}
}

void LinkedList::insertBack(const string &e)
{

	Node *temp = new Node;
	temp->elem = e;
	temp->next = NULL;

	if (isEmpty())
		head = temp;
	else
	{

		auto temp2 = head;

		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}

		temp2->next = temp;
	}
}

void LinkedList::removeBack()
{

	if (isEmpty())
		printf("Error! List Empty!\n");
	else
	{

		auto temp = head;
		auto temp2 = head->next;

		while (temp2->next != NULL)
		{

			temp = temp->next;
			temp2 = temp2->next;
		}

		if (temp == head)
		{
			head = NULL;
			delete temp;
		}
		else
		{
			temp->next = NULL;
			delete temp2;
			temp2 = NULL;
		}
	}
}

string LinkedList::front() const
{

	if (isEmpty())
	{

		auto error = "Error! List Empty"s;
		return error;
	}
	else
	{

		return head->elem;
	}
}

string LinkedList::back() const
{
	if (isEmpty())
	{
		auto error = "Error! List Empty!"s;
		return error;
	}
	else
	{

		auto temp = head;

		while (temp->next != NULL)
		{

			temp = temp->next;
		}

		return temp->elem;
	}
}

LinkedList::~LinkedList()
{

	while (!isEmpty())
		removeFront();
}

int main()
{

	auto list = new LinkedList{};
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;
	list->insertFront("Elias");
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;
	list->insertFront("Bingi");
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;

	list->insertFront("Boikanyo");
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;

	list->insertBack("Koketso");
	list->insertBack("Madimetsa");
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;

	cout << "Removals" << endl;

	list->removeFront();
	list->removeBack();
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;
	list->removeBack();
	cout << "Front: " << list->front() << endl;
	list->removeBack();
	list->removeBack();
	cout << "Front: " << list->front() << endl;
	list->insertFront("Elias");
	list->insertBack("Bingi");
	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;
	list->removeFront();
	list->removeFront();
	list->removeBack();
	list->removeBack();

	cout << "Front: " << list->front() << endl;
	cout << "Back: " << list->back() << endl;
	return 0;
}
