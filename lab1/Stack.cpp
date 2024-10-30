#include"stack.h"

static string StackID = "0";

Stack::Stack()
{
	spointer = nullptr;
}

Stack::~Stack()
{
	while (!isEmpty())
	{
		DNode* temp = spointer;
		spointer = spointer->prev;
		if (spointer) 
		{
			spointer->next = nullptr;
		}
		string res = temp->data;
		delete temp;
		len--;
	}
}

void Stack::SPUSH(string elem)
{
	DNode* newNode = new DNode(elem);
	newNode->prev = spointer;
	if (spointer) 
	{
		spointer->next = newNode;
	}
	spointer = newNode;
	len++;
}

string Stack::SPOP()
{
	if (isEmpty())
	{
		return "Пустой стек\n";
	}
	DNode* temp = spointer;
	spointer = spointer->prev;
	if (spointer) 
	{
		spointer->next = nullptr;
	}
	string res = temp->data;
	delete temp;
	len--;
	return res;
}

string Stack::SGET(int index)
{
	index = mod(index, len);
	DNode* current = spointer;
	int currentIndex = 0;

	while (current != nullptr)
	{
		if (currentIndex == index)
		{
			return current->data;
		}
		current = current->next;
		currentIndex++;
	}
	return "Index out of range.";
}

void Stack::PRINT()
{
	if (isEmpty())
	{
		cout << "Пустой стек\n";
		return;
	}
	DNode* current = spointer;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->prev;
	}
	cout << "- вершина \n";
}