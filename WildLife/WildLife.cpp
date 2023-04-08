#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Травоядные
class Herbivore abstract
{
public:
	virtual string GetName() abstract;
	virtual void EatGrass() abstract;
	virtual int getWeight() abstract;
	virtual bool getLife() abstract;
	virtual void Kill() abstract;
};

// Плотоядные
class Carnivore abstract
{
public:
	virtual string GetName() abstract;
	virtual void Eat(Herbivore* herbivore) abstract;
	virtual int getPower() abstract;
	virtual bool getLife() abstract;
};

// Wildebeest  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой,
// а также реализует интерфейс Herbivore

class Wildebeest : public Herbivore
{
	string name = "Wildebeest ";

	int weight = rand() % 100 ;

	bool life = true;

public:
	void Kill() override
	{
		life = false;
	}
	string GetName() override
	{
		return name;
	}
	void EatGrass() override
	{
		if (life)
		{
			weight = weight + 10;
		}
		else
		{
			life = false;
		}

	}
	int getWeight() override
	{
		return weight;
	}
	bool getLife() override
	{
		return life;
	}
};

// Bison  - определяет объект-продукт, создаваемый соответствующей конкретной фабрикой,
// а также реализует интерфейс Herbivore

class Bison : public Herbivore
{

	string name = "Bison ";

	int weight = rand() % 100 * 5;

	bool life = true;

public:
	void Kill() override
	{
		life = false;
	}
	string GetName() override
	{
		return name;
	}
	void EatGrass() override
	{
		if (life)
		{
			weight = weight + 10;
		}
		else
		{
			life = false;
		}

	}
	int getWeight() override
	{
		return weight;
	}
	bool getLife() override
	{
		return life;
	}
};

class Elk : public Herbivore
{
	string name = "Elk ";

	int weight = rand() % 100 * 3;

	bool life = true;

public:
	void Kill() override
	{
		life = false;
	}
	string GetName() override
	{
		return name;
	}
	void EatGrass() override
	{
		if (life)
		{
			weight = weight + 10;
		}
		else
		{
			life = false;
		}
	}
	int getWeight() override
	{
		return weight;
	}
	bool getLife() override
	{
		return life;
	}
};

class Tiger : public Carnivore
{
	string name = "Tiger ";

	int power = rand() % 100 * 3;

	bool life = true;

public:
	string GetName() override
	{
		return name;
	}
	void Eat(Herbivore* h) override
	{
		if (h->getWeight() < power)
		{
			power = power + 10;

			h->Kill();
		}
		else
		{
			power = power - 10;

			if (power < 10)
			{
				power = 0;

				life = false;
			}
		}
	}
	int getPower() override
	{
		return power;
	}
	bool getLife() override
	{
		return life;
	}
};

class Lion : public Carnivore
{
	string name = "Lion ";

	int power = rand() % 100 * 3;

	bool life = true;

public:
	string GetName() override
	{
		return name;
	}
	void Eat(Herbivore* h) override
	{
		if (h->getWeight() < power)
			{
				power = power + 10;

				h->Kill();
			}
		else
		{
			power = power - 10;

			if (power < 10)
			{
				power = 0;

				life = false;
			}
		}
	}
	int getPower() override
	{
		return power;
	}
	bool getLife() override
	{
		return life;
	}
};


class Wolf : public Carnivore
{
	string name = "Wolf ";

	int power = rand() % 100 * 2;

	bool life = true;

public:
	string GetName() override
	{
		return name;
	}
	void Eat(Herbivore* h) override
	{
		if (h->getWeight() < power)
		{
			power = power + 10;

			h->Kill();
		}
		else
		{
			power = power - 10;

			if (power < 10)
			{
				power = 0;
				life = false;
			}
		}
	}
	int getPower() override
	{
		return power;
	}
	bool getLife() override
	{
		return life;
	}
};

class Nutrition abstract
{
public:
	virtual void Eat() abstract;
	virtual void EatGrass() abstract;
};

// класс абстрактной фабрики
class Continent abstract
{
public:
	virtual Herbivore* CreateHerbivore() abstract;
	virtual Carnivore* CreateCarnivore() abstract;
};


//Africa - реализует операции, создающие конкретные объекты-продукты

class Africa : public Continent
{
public:
	Herbivore* CreateHerbivore() override
	{
		return new Wildebeest();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Lion();
	}
};

//NorthAmerica - реализует операции, создающие конкретные объекты-продукты
class NorthAmerica : public Continent
{
public:
	Herbivore* CreateHerbivore() override
	{
		return new Bison();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Wolf();
	}
};

class Eurasia : public Continent
{
public:
	Herbivore* CreateHerbivore() override
	{
		return new Elk();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Tiger();
	}
};

void Print(vector<Herbivore*> h, vector<Carnivore*> c)
{
	vector<Carnivore*>::iterator iterC;

	Carnivore* carnivore;

	vector<Herbivore*>::iterator iterH;

	Herbivore* herbivore;

	iterH = h.begin();

	for (iterC = c.begin(); iterC != c.end(); iterC++)
	{
		carnivore = *iterC;

		if (iterH != h.end())
		{
			herbivore = *iterH;

		if (carnivore->getLife())
		{
			if (carnivore->getPower() > herbivore->getWeight())
			{
				cout << carnivore->GetName() << " had " << carnivore->getPower() << " but eat " << herbivore->GetName();

				carnivore->Eat(herbivore);

				cout << " Its power increased to " << carnivore->getPower() << " now. ";
			}
			else
			{
				cout << carnivore->GetName() << " had " << carnivore->getPower() << " but lost " << herbivore->GetName() << ". ";

				carnivore->Eat(herbivore);

				if (!carnivore->getLife())

					cout << carnivore->GetName() << "is dead! ";

				else

					cout << " Its power decreased to " << carnivore->getPower() << " now. ";
			}
		}
		else cout << carnivore->GetName() << "is dead! ";

		if (herbivore->getLife())
		{
			cout << herbivore->GetName() << " had " << herbivore->getWeight() << " but eat green grass and become ";

			herbivore->EatGrass();

			cout << herbivore->getWeight() << ". ";
		}
		else cout << herbivore->GetName() << "is dead! ";
	}

		iterH++;

		cout <<	endl << endl;
	}
}


class Client
{
	Herbivore* herbivore;
	Carnivore* carnivore;

	vector<Herbivore*> herb;
	vector<Carnivore*> carv;

public:
	Client(Continent* factory)
	{
		herbivore = factory->CreateHerbivore();
		carnivore = factory->CreateCarnivore();

		herb.push_back(factory->CreateHerbivore());
		carv.push_back(factory->CreateCarnivore());

		Print(herb, carv);
	}
	void NutritionCarnivores()
	{
		carnivore->GetName();
		carnivore->Eat(herbivore);
	}
	void MealsHerbivores()
	{
		herbivore->GetName();
		herbivore->EatGrass();
	}
};

void ClientFunc(Continent* factory)
{
	Client* client = nullptr;
	client = new Client(factory);
	client->MealsHerbivores();
	client->NutritionCarnivores();
	delete client;
}





int main()
{	//сделать 2 вектора указателей  на базовые классы травоядных и протоядных
	//рандомный вес животных
	//отвязать конкретных травоядных от плотоядных, сделать выбор животных в main
	srand(time(0));

	while (true)
	{
		system("cls");

		Continent* factory = new Africa();
		ClientFunc(factory);
		delete factory;

		factory = new NorthAmerica();
		ClientFunc(factory);
		delete factory;

		factory = new Eurasia();
		ClientFunc(factory);
		delete factory;

		system("pause");
	}
	return 0;
}
