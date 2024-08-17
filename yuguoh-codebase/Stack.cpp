#include "Stack.h"


//Check to see if the stack is empty by checking top. (Seems kind of self explainitory if you ask me)
bool Stack::isEmpty()
{
	if(top == nullptr)
		return true;
	else
		return false;
}

//Puts a new item on the stack and makes it the top item, cause thats how stacks work.
void Stack::push(string name, string type, int attack, int defense)
{
	StackNode *newNode = new StackNode;

	//Transfers the data
	newNode->name = name;
	newNode->type = type;
	newNode->attack = attack;
	newNode->defense = defense;
	newNode->next = nullptr;

	if(isEmpty())
	{
		top = newNode;
	}
	else
	{
		//top->next = newNode;
		newNode->next = top;
		top = newNode;
	}
}

//Removes the top item and return it so the program can use it. 
void Stack::pop(string &name, string &type, int &attack, int &defense)
{
	StackNode *temp = nullptr;

	if(isEmpty())
	{
		cout << "The stack is empty!\n";
	}
	else
	{
		temp = top;
		top = top->next;
		//Passes the data out from temp
		name = temp->name;
		type = temp->type;
		attack = temp->attack;
		defense = temp->defense;
		//Deletes the used to be top node
		delete temp;
	}
}

//Allows the user to see the entire hand without removing all items like pop would do. 
void Stack::peek()
{
	if(!isEmpty())
		cout << "The top item is " << top->name << endl;
	else
		cout << "The stack it empty :(\n";
}

//Pops all items from the stack and stops when their's nothing left
void Stack::clear()
{
	string name;
	string type;
	int attack;
	int defense;

	while(!isEmpty())
		pop(name,type,attack,defense);
}

