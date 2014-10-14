#include <string>
#include <iostream>
#include <vector>//Vector data type/structure BIG MOTHERFUCKING NB
using namespace std;

class 00Greeter
{
	public:
		00Greeter(); //Always add this no-args constructor.
		~00Greeter();//Destructor
		00Greeter(string name);		
		void setName(string name); //Mutator Method.
		string getName() const;//Accessor method. const because it doesn't change the state.
		void greet() const;
	private: //The default state, this call is redundant
		string name;
		bool isHappy;
}; //Notice the Semi-colon

00Greeter::00Greeter() : ishappy(true) //one method of giving it a variable
{
	name = "John Doe";
}

00Greeter::00Greeter(string name)
{
	this->name = name; //Disambiguation in the member function. a pointer and dereference arrow to the method.
	isHappy = true; //The other method of using constructors.
}
void 00Greeter::greet() const //Scope resolution when referring to classes. This means that this class belongs to the 00Greeter Class.
{
	cout << "Hello World, this is  " << name << endl;
}

int main()
{
	string s;
	s="Hello World";
	cout << s.length << endl; //simple function called as a member function of the string class.
	
	/*At the end of the day you'll be able to make your own member function of a larger class.
	
	Each instance of a class have their own methods that can be used. Instance variables are also independent to every class.
	Every object has it's own instance of data. This is referred to the state of the object.
	
	The correct way to modify the state of a class is an accessor function and a mutator to change states.
	a Constant function is a member function that cannot modify member variables.
	
	When you define a class in C++ there is no order where you create or supply variables.
	
	*/
	00Greeter hey("Cumberdale Arnolds");
	hey.greet();
	
	vector<int> a; //How to create a vector
	a.push_back(5); //Adding size to a vector
	a[0]=100; // using the index operator on a vector.
	cout << a.length << endl; // You can ask a vector what it is!
	
}

string 00Greeter::getName() const
{
	return name;
}//Accessor method. const because it doesn't change the state.

void 00Greeter::setName(string name); //Mutator Method.
{
	this->name = name;
}

/*
	creating a class without a constructor is called a free constructor.
	and creating a constructor without any arguments is a no arguments constructor.
	
	Classes can have multiple constructors.
	
*/
