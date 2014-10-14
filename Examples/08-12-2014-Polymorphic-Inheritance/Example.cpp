#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	Animal(string name);
	string getName() const;
	virtual void makeSound() = 0;
private:
	string name;
};

Animal::Animal() : name("Anon")
{
}

Animal::Animal(string name)
{
	this->name = name;
}

string Animal::getName() const
{
	return name;
}

class Cat : public Animal
{
public:
	virtual void makeSound();
};

void Cat::makeSound()
{
	cout << "Meow" << endl;
}

class Dog : public Animal
{
public:
	virtual void makeSound();
};

void Dog::makeSound()
{
	cout << "Woof" << endl;
}


void makeNoise(Animal* ap)
{
	ap->makeSound();
}

int main()
{
	srand(time(0));
	Animal* a = NULL;
	if(rand() % 2)
	{
		a = new Cat;
	} else
	{
		a = new Dog;
	}
	makeNoise(a);
	return 0;
}
