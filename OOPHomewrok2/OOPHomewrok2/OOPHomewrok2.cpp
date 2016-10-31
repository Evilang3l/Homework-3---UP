// OOPHomewrok2.cpp : Defines the entry point for the console application.
//

#include "Egg.h"
#include "Basket.h"
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

Basket* baskets = nullptr;
int currentBasketCount = 0;
Egg* eggs = nullptr;
int currentEggsCount = 0;

void CreateEgg();
void PutEgg(Basket&);
void DeleteEgg(Basket&);
void CreateBasket();
void AccessBasket();
int GetBasketIndex();
void LoadBasket();

int main()
{

	cout << "Allowed commands \n ce [Creates egg] \n ab [Acesses basket from it's name] \n cb [Creates a basket] \n finish[Finishes the program] \n sb [Saves basket in a binary file with it's name] \n lb [Loads a bakset from a binary file with the basket ower's name] \n report [MAkes report txt file for a basket] \n";
	bool isProgramFinished = false;

	do
	{
		cout << "Input a command: ";

		char* input = new (nothrow) char[7];
		cin.getline(input, 7);

		if (!strcmp(input, "ce"))
		{
			CreateEgg();
		} 
		else if (!strcmp(input, "cb"))
		{
			CreateBasket();
		}
		else if (!strcmp(input, "ab"))
		{
			AccessBasket();
		}
		else if (!strcmp(input, "report"))
		{
			int openedBasket = GetBasketIndex();
			if (openedBasket >= 0)
			{
				baskets[openedBasket].reportBasket();
			}
			else
			{
				cout << "No such basket! \n";
			}
		}
		else if (!strcmp(input, "sb"))
		{
			int index = GetBasketIndex();
			if (index >= 0)
			{
				baskets[index].serializeBasket();
			}
			else
			{
				cout << "No such basket! \n";
			}
		}
		else if (!strcmp(input, "lb"))
		{
			LoadBasket();
		}
		else if (!strcmp(input, "finish"))
		{

			isProgramFinished = true;
			return 0;
		}
		else
		{
			cout << "Wrong command!" << endl;
		}

		delete[] input;
	} while (!isProgramFinished);

	return 0;
}

void CreateEgg()
{
	int eggSize = 0;
	cout << "What will be the egg size? ";
	cin >> eggSize;
	cin.ignore(256, '\n');

	cout << "Input egg name: ";
	char* eggName = new (nothrow) char[eggSize + 1];
	cin.getline(eggName, eggSize + 1);

	if (eggs == nullptr)
	{
		currentEggsCount = 1;
		eggs = new (nothrow) Egg[currentEggsCount];
		eggs[0].setName(eggName);

	}
	else
	{
		Egg* eggsTmp = new (nothrow) Egg[currentEggsCount + 1];

		for (int i = 0; i < currentEggsCount; i++)
		{
			eggsTmp[i].setName(eggs[i].getName());
		}

		eggsTmp[currentEggsCount].setName(eggName);

		eggs = eggsTmp;
		eggsTmp = nullptr;
		delete[] eggsTmp;
		currentEggsCount++;
	}
}

void CreateBasket()
{
	cout << "Input basket owner's name: ";
	char* ownerName = new char[256];

	cin.getline(ownerName, 256);

	if (baskets == nullptr)
	{
		currentBasketCount = 1;
		baskets = new (nothrow) Basket[currentBasketCount];
		baskets[0].setOwner(ownerName);

	}
	else
	{
		Basket* basketsTmp = new (nothrow) Basket[currentBasketCount + 1];

		for (int i = 0; i < currentBasketCount; i++)
		{
			basketsTmp[i].setOwner(baskets[i].getOwner());
		}

		basketsTmp[currentBasketCount].setOwner(ownerName);

		baskets = basketsTmp;
		basketsTmp = nullptr;
		delete[] basketsTmp;
		currentBasketCount++;
	}

	cout << "Allowed commands for the basket: \n pe [Puts egg in the basket] \n de [Removes egg from the basket] \n finish [Finishes with the creation of the basket] \n";

	bool isBasketFinished = false;

	do
	{
		cout << "Input a command: ";

		char* input = new (nothrow) char[7];
		cin.getline(input, 7);

		if (!strcmp(input, "pe"))
		{
			PutEgg(baskets[currentBasketCount - 1]);
		}
		else if (!strcmp(input, "de"))
		{
			DeleteEgg(baskets[currentBasketCount - 1]);
		}
		else if (!strcmp(input, "finish"))
		{
			isBasketFinished = true;
		}
		else
		{
			cout << "Wrong command!" << endl;
		}

		delete[] input;
	} while (!isBasketFinished);
}

void PutEgg(Basket& basket)
{
	int eggSize = 0;
	cout << "What will be the egg size? ";
	cin >> eggSize;
	cin.ignore(256, '\n');

	cout << "Input egg name: ";
	char* eggName = new (nothrow) char[eggSize + 1];
	cin.getline(eggName, eggSize + 1);

	basket.pushEgg(eggName);
}

void DeleteEgg(Basket& basket)
{
	int eggSize = 0;
	cout << "What will be the egg size? ";
	cin >> eggSize;
	cin.ignore(256, '\n');

	cout << "Input egg name: ";
	char* eggName = new (nothrow) char[eggSize + 1];
	cin.getline(eggName, eggSize + 1);

	basket.popEgg(eggName);
}

void AccessBasket()
{
	int openedBasket = GetBasketIndex();

	if (openedBasket >= 0)
	{
		cout << "Allowed commands for the basket: \n pe [Puts egg in the basket] \n de [Removes egg from the basket] \n finish [Finishes with the moderation of the basket] \n";

		bool isBasketFinished = false;

		do
		{
			cout << "Input a command: ";

			char* input = new (nothrow) char[7];
			cin.getline(input, 7);

			if (!strcmp(input, "pe"))
			{
				PutEgg(baskets[openedBasket]);
			}
			else if (!strcmp(input, "de"))
			{
				DeleteEgg(baskets[openedBasket]);
			}
			else if (!strcmp(input, "finish"))
			{
				isBasketFinished = true;
			}
			else
			{
				cout << "Wrong command!" << endl;
			}

			delete[] input;
		} while (!isBasketFinished);
	}
	else
	{
		cout << "No such basket!" << endl;
	}
}

int GetBasketIndex()
{
	cout << "Input basket owner's name: ";
	char* basketName = new (nothrow) char[256];
	cin.getline(basketName, 256);

	int openedBasket = -1;

	if (baskets != nullptr)
	{
		for (int i = 0; i < currentBasketCount; i++)
		{
			if (!strcmp(basketName, baskets[i].getOwner()))
			{
				openedBasket = i;
			}
		}
	}

	return openedBasket;
}

void LoadBasket()
{
	cout << "Input basket owner's name: ";
	char* ownerName = new char[256];

	cin.getline(ownerName, 256);

	if (baskets == nullptr)
	{
		currentBasketCount = 1;
		baskets = new (nothrow) Basket[currentBasketCount];
		baskets[0].deserializeBasket(ownerName);

	}
	else
	{
		Basket* basketsTmp = new (nothrow) Basket[currentBasketCount + 1];

		for (int i = 0; i < currentBasketCount; i++)
		{
			basketsTmp[i].setOwner(baskets[i].getOwner());
		}

		basketsTmp[currentBasketCount].deserializeBasket(ownerName);

		baskets = basketsTmp;
		basketsTmp = nullptr;
		delete[] basketsTmp;
		currentBasketCount++;
	}
}