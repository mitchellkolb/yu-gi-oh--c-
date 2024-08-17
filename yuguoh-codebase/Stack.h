
#ifndef STACK_H
#define STACK_H


#include<iostream>
#include <string>
using namespace std;


class Stack
{
	private:
		struct StackNode
		{
			string name;
			string type;
			int attack;
			int defense;
			StackNode *next;
		};
		StackNode *top;

	public:
		//Constructor
		Stack()
		{
			top = nullptr;
		}

		//public member function
		bool isEmpty();

		void push(string name, string type, int attack, int defense);

		void pop(string &name, string &type, int &attack, int &defense);

		void peek();

		void clear();

		//Destructor
		~Stack()
		{
			clear();
		}


};


#endif



