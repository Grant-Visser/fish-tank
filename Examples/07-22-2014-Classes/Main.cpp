//Function Pointers. 
//Hello World analogue
#include<string>
#include<iostream>
#include<cstdlib>

using namespace std;

struct Greeter
{
	string name;
	void (*greet)(Greeter* self);
};

void greetImp(Greeter* self)
{
	cout << "Hello World! I am " << self->name << endl;
}

Greeter* makeGreeter(string name)
{
	Greeter* greeter = new Greeter;
	greeter->name = name;
	greeter-> greet =&greetImp;
	return greeter;
}

int main ()
{
	Greeter* g= makeGreeter("Gandalf");
	g->greet(g);
	delete(g);
	system("Pause");
	return 0;
}

