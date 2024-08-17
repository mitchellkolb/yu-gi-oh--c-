
#ifndef QUEUE_H
#define QUEUE_H


#include<iostream>
#include <string>
#include <fstream>
using namespace std;


class Queue
{
	private:
		struct Qnode
		{
			string name;
			string type;
			int attack;
			int defense;
			Qnode *next;
		};

		Qnode *front;
		Qnode *rear;
	public:
		//Constructor
		Queue()
		{
			front = nullptr;
			rear = nullptr;
		}

		//public member function
		void clear();

		void enqueue(string name, string type, int attack, int defense);

		void dequeue(string &name, string &type, int &attack, int &defense);

		bool isEmpty();

		//Destructor

		~Queue()
		{
			clear();
		}


};

//Regular functions
void menu(int &pass_num);
void haveIwon(int &life);


#endif




