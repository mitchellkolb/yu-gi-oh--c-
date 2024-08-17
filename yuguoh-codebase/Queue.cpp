#include "Queue.h"


bool Queue::isEmpty()
{
	if(front == nullptr) // i had it both rear and front equal to nullptr
		return true;
	else
		return false;

}


//Enqueue - new item is added to the queue
void Queue::enqueue(string name, string type, int attack, int defense)
{
	Qnode *newNode = new Qnode;

	newNode->name = name;
	newNode->type = type;
	newNode->attack = attack;
	newNode->defense = defense;
	newNode->next = nullptr;

	if(isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}

}

//Dequeue - front node is removed from the queue and sent out to be used. 
void Queue::dequeue(string &name, string &type, int &attack, int &defense)
{
	Qnode* temp = nullptr;

	if(isEmpty())
	{
		cout << "The queue is empty!\n";
	}
	else
	{
		name = front->name;
		type = front->type;
		attack = front->attack;
		defense = front->defense;

		temp = front;
		front = temp->next;
		delete temp;
	}


}

//Removes all the node from the queue
void Queue::clear()
{
	string name;
	string type;
	int attack;
	int defense;

	while(!isEmpty())
		dequeue(name,type,attack,defense);
}


//Regular functions
void menu(int &pass_num)
{
	int menus = 0;
	while (menus < 50)
	{
		int choice;
		cout << "\n1. Create Players\n2. Add Cards to Player\n3. Battle Other Player\n";
		cin >> choice;
		if (choice == 1)
		{
			system("clear");
			menus += 1;
			cout << "\nPlayer 1 and Player 2 have been created with a deck. You can now battle!\n";
		}
		else if (choice == 2)
		{
			system("clear");
			ofstream oFile("Yu_Gi_Oh_Card_list.csv", ios::app);
			string name;
			int num;
			
			cout << "\nPlease enter the name of the card you want to add.\n";
			getline(cin, name);
			getline(cin, name);
			cout << "Press enter to continue:\n";
			oFile << name << ",";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nPlease enter the type of the card you want to add.\n";
			getline(cin, name);
			cout << "Press enter to continue:\n";
			oFile << name << ",";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			cout << "\nPlease enter the attack power of the card you want to add.\n";
			cin >> num; 
			oFile << num << ",";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			cout << "\nPlease enter the defense power of the card you want to add.\n";
			cin >> num; 
			oFile << num << endl;
			menus += 1;
		}
		else if (choice == 3)
		{
			if(menus < 1)
			{
				cout << "You need to create the players in option 1 first to play.\n";
				cout << "Press enter to continue:\n";
                cin.ignore();
				cin.ignore();
			}
			system("clear");
			if(menus >= 1)
			{
				if(menus >= 2)
				{
					pass_num = (menus - 1);
				}
				cout << "The game will start now.\n";
				cout << "Press Enter to Continue\n";
				cin.ignore();
				cin.ignore();
				menus = 51;
			}
		}
	}
}

void haveIwon(int &life)
{
	if(life <= 0)
	{
		life = -1;
	}
}



