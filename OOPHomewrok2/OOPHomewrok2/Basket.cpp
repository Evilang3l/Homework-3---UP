#include "Basket.h"

//Интерфейсът е примерен и в случай на опит за счуване, това става лесно.
//Моля да ме извините, че не е направен като хората, но се съсредоточих
//повече върху методите на класа. :(

Basket::Basket()
{
	owner = nullptr;
	eggs = nullptr;
	size = 0;
	capacity = 0;
}

Basket::Basket(const Basket& other)
{
		copyObject(other.getOwner(), other.eggs, other.size, other.capacity);
}

Basket::Basket(const char* ownerTmp, const Egg* eggsTmp, unsigned sizeTmp, unsigned capacityTmp)
{
	copyObject(ownerTmp, eggsTmp, sizeTmp, capacityTmp);
}

Basket& Basket::operator=(const Basket& other)
{
	if (this != &other)
	{
		clearObject();
		copyObject(other.owner, other.eggs, other.size, other.capacity);
	}

	return *this;
}

Basket::~Basket()
{
	clearObject();
}

void Basket::setOwner(const char* ownerTmp)
{
	delete[] owner;
	int ownerSize = strlen(ownerTmp) + 1;
	owner = new (std::nothrow) char[ownerSize];
	strcpy(owner, ownerTmp);
}

const char* Basket::getOwner() const
{
	return owner;
}

void Basket::addEgg(const Egg egg)
{
	if ((size + 1) >= capacity)
	{
		size++;
		capacity = size + size / 4;
	}

	Egg* eggsTmp = new (std::nothrow) Egg[capacity];

	if (size - 1 != 0)
	{
		for (unsigned i = 0; i < size - 1; i++)
		{
			eggsTmp[i] = eggs[i];
		}

		eggsTmp[size - 1] = egg;
	}
	else
	{
		eggsTmp[0] = egg;
	}

	eggs = eggsTmp;
	eggsTmp = nullptr;
	delete[] eggsTmp;
}

void Basket::removeEgg(const Egg egg)
{
	if (size > 0)
	{
		if (eggs != nullptr)
		{
			int indexOfEgg = eggExists(egg);
			if (indexOfEgg >= 0)
			{
				if (size - 1 > 0)
				{
					if (capacity > (size - 1) * 2)
					{
						capacity = (size - 1) + (size - 1) / 4;
					}

					Egg* eggsTmp = new (std::nothrow) Egg[capacity];

					for (int i = 0; i < indexOfEgg; i++)
					{
						eggsTmp[i] = eggs[i];
					}

					for (unsigned i = indexOfEgg + 1; i < size; i++)
					{
						eggsTmp[i - 1] = eggs[i];
					}

					size--;

					eggs = eggsTmp;
					eggsTmp = nullptr;
					delete[] eggsTmp;
				}
				else
				{
					eggs = nullptr;
				}
			}
		}
		else
		{
			std::cout << "No eggs in the basket! Can't remove any! \n";
		}
	}
	else
	{
		std::cout << "No eggs in the basket! Can't remove any! \n";
	}
}

void Basket::serializeBasket()
{
	if (capacity != 0 && size != 0)
	{
		capacity = size;
		if (eggs != nullptr)
		{
			copyEggs(size, capacity);
			saveBasket(Basket(owner, eggs, size, capacity));
		}
	}
}

void Basket::deserializeBasket(const char* input)
{

	Basket load = loadBasket(input);
	if (load.getOwner() != nullptr)
	{
		setOwner(load.getOwner());
		size = load.size;
		capacity = load.capacity;
		eggs = load.eggs;

		if (capacity == size)
		{
			capacity = size + size / 4;
			copyEggs(size, capacity);
		}
	}
}

void Basket::copyObject(const char* ownerTmp, const Egg* eggsTmp, unsigned sizeTmp, unsigned capacityTmp)
{
	owner = new char[strlen(ownerTmp) + 1];
	strcpy(owner, ownerTmp);
	eggs = new (std::nothrow) Egg[capacityTmp];

	if (eggsTmp != nullptr)
	{
		for (unsigned i = 0; i < sizeTmp; i++)
		{
			eggs[i] = eggsTmp[i];
		}

		size = sizeTmp;
		capacity = capacityTmp;
	}
	else
	{
		eggs = nullptr;

		size = 0;
		capacity = 0;
	}
}

void Basket::clearObject()
{
	delete[] owner;
	delete[] eggs;
}

int Basket::eggExists(const Egg egg)
{
	int index = -1;
	if (eggs != nullptr)
	{
		bool exists = false;
		for (unsigned i = 0; i < size; i++)
		{
			if (egg == eggs[i])
			{
				exists = true;
				index = i;
				break;
			}
		}
	}
	if (index == -1)
	{
		std::cout << "No such egg in the basket! \n";
	}

	return index;
}

void Basket::copyEggs(unsigned sizeTmp, unsigned capacityTmp)
{
	if (eggs != nullptr)
	{
		Egg* eggsTmp = new (std::nothrow) Egg[capacityTmp];

		for (unsigned i = 0; i < sizeTmp; i++)
		{
			eggsTmp[i] = eggs[i];
		}

		eggs = eggsTmp;
		eggsTmp = nullptr;
		delete[] eggsTmp;
	}
}

void Basket::pushEgg(const char* eggName)
{
	unsigned sizeOfEgg = strlen(eggName) + 1;
	Egg eggTmp(eggName, sizeOfEgg);

	addEgg(eggTmp);
}

void Basket::popEgg(const char* eggName)
{
	unsigned sizeOfEgg = strlen(eggName) + 1;
	Egg eggTmp(eggName, sizeOfEgg);

	removeEgg(eggTmp);
}

void Basket::saveBasket(const Basket& basket)
{
	if (basket.eggs != nullptr)
	{
		int sizeOfName = strlen(basket.getOwner());
		const char* basketName = basket.getOwner();
		char* basketFileName = new char[sizeOfName + 4];

		for (int i = 0; i < sizeOfName; i++)
		{
			basketFileName[i] = basketName[i];
		}

		basketName = nullptr;
		delete[] basketName;

		basketFileName[sizeOfName] = '.';
		basketFileName[sizeOfName + 1] = 'd';
		basketFileName[sizeOfName + 2] = 'a';
		basketFileName[sizeOfName + 3] = 't';
		basketFileName[sizeOfName + 4] = '\0';

		std::ofstream basketFile;
		basketFile.open(basketFileName, std::ios::app | std::ios::binary);

		if (basketFile.is_open())
		{
			//Записва колко е голямо името и след това самото име
			int nameSize = strlen(basket.getOwner()) + 1;
			basketFile.write((const char*)& nameSize, sizeof(int));
			
			for (int i = 0; i < nameSize; i++)
			{
				basketFile.write((const char*)& basket.getOwner()[i], sizeof(char));
			}

			//Записва колко яйца има, след това за всяко яйце - колко голямо е името му и след това самото име
			basketFile.write((const char*)& size, sizeof(int));

			for (unsigned i = 0; i < size; i++)
			{
				int eggNameSize = strlen(basket.eggs[i].getName()) + 1;
				basketFile.write((const char*)& eggNameSize, sizeof(int));
				const char* eggName = basket.eggs[i].getName();
				for (int k = 0; k < eggNameSize; k++)
				{
					basketFile.write((const char*)& eggName[k], sizeof(char));
				}
			}

			basketFile.write((const char*)& capacity, sizeof(int));
		}
		else
		{
			std::cout << "Could not create file " << basketFileName << std::endl;
		}
	}
	else
	{
		std::cout << "The basket you are trying to save is empty!" << std::endl;
	}
}

Basket Basket::loadBasket(const char* basketNameInput)
{
	int sizeOfName = strlen(basketNameInput);
	const char* basketName = basketNameInput;
	char* basketFileName = new char[sizeOfName + 4];

	for (int i = 0; i < sizeOfName; i++)
	{
		basketFileName[i] = basketName[i];
	}

	basketName = nullptr;
	delete[] basketName;

	basketFileName[sizeOfName] = '.';
	basketFileName[sizeOfName + 1] = 'd';
	basketFileName[sizeOfName + 2] = 'a';
	basketFileName[sizeOfName + 3] = 't';
	basketFileName[sizeOfName + 4] = '\0';

	std::ifstream basketFile;
	basketFile.open(basketFileName);

	if (basketFile.is_open())
	{
		unsigned currFileG = 0;
		basketFile.seekg(0, std::ios::beg);
		int ownerNameSize = 1;
		basketFile.read((char*)&ownerNameSize, sizeof(int));
		currFileG += sizeof(int);

		char* ownerName = new (std::nothrow) char[ownerNameSize];
		for (int i = 0; i < ownerNameSize; i++)
		{
			basketFile.seekg(currFileG, std::ios::beg);
			basketFile.read((char*)&ownerName[i], sizeof(char));
			currFileG += sizeof(char);
		}

		basketFile.seekg(currFileG, std::ios::beg);

		basketFile.read((char*)& size, sizeof(int));
		currFileG += sizeof(int);
		basketFile.seekg(currFileG, std::ios::beg);

		Egg* eggsTmp = new (std::nothrow) Egg[size];
		for (unsigned i = 0; i < size; i++)
		{
			int eggNameSize = 1;
			basketFile.read((char*)& eggNameSize, sizeof(int));
			currFileG += sizeof(int);

			char* eggName = new char[eggNameSize];

			for (int k = 0; k < eggNameSize; k++)
			{
				basketFile.seekg(currFileG, std::ios::beg);

				basketFile.read((char*)& eggName[k], sizeof(char));
				currFileG += sizeof(char);
			}

			basketFile.seekg(currFileG, std::ios::beg);
			eggsTmp[i].setName(eggName);
		}

		basketFile.read((char*)& capacity, sizeof(int));

		Basket result = Basket(ownerName, eggsTmp, size, capacity);

		return result;
	}
	else
	{
		std::cout << "There is no such basket in the files!" << std::endl;
		return Basket();
	}
}

void Basket::reportBasket()
{
	int sizeOfName = strlen(getOwner());
	const char* basketName = getOwner();
	char* basketFileName = new char[sizeOfName + 11];

	basketFileName[0] = 'r';
	basketFileName[1] = 'e';
	basketFileName[2] = 'p';
	basketFileName[3] = 'o';
	basketFileName[4] = 'r';
	basketFileName[5] = 't';
	basketFileName[6] = '_';

	for (int i = 7; i < sizeOfName + 7; i++)
	{
		basketFileName[i] = basketName[i - 7];
	}

	basketName = nullptr;
	delete[] basketName;

	basketFileName[sizeOfName + 7] = '.';
	basketFileName[sizeOfName + 8] = 't';
	basketFileName[sizeOfName + 9] = 'x';
	basketFileName[sizeOfName + 10] = 't';
	basketFileName[sizeOfName + 11] = '\0';

	std::ofstream reportFile(basketFileName, std::ios::trunc);

	if (reportFile.is_open())
	{
		reportFile << "Basket owner: " << owner << std::endl;
		reportFile << "Eggs is basket" << std::endl;
		for (unsigned i = 0; i < size; i++)
		{
			reportFile << i + 1 << ". " << eggs[i].getName() << std::endl;
		}
	}
}