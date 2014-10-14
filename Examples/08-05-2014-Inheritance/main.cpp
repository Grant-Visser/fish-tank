//There is a is-a relationship and a ocmponent base type
//Has-a Relationship to the solar panels and engines

//You should make an array or container of component. an array of objects.
//You need a new concept: 

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Person
{
	public:
	
		virtual void doAct() = 0;
};

class Student : public Person
{
	public:
		virtual void doAct();
};

void Student::doAct()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Study " << endl;
	}
	cout << "GREAT SUCCESS!!!!!!!!!!!!" << endl;
}

class LazyStudent: public Student
{
	public:
		virtual void doAct();
};

void LazyStudent::doAct()0
{
	for(int i = 0; i< 10; i++)
	{
		cout << "Goof Off " << endl;
	}
	cout << "FAIL!!!!!!!!!!!!" << endl;
}

int main()
{
	/*Student s;
	Person* p =&s; //person pointer. a place in memory where people are going to exist. whatever person you find there will behave as it's actual type and not it's person type
	p->doAct(); //The person still acts as a person, not a student as was assigned. Problem.
	*/
	srand(time(NULL));
	Person** people = new Person *[10]; //Not a 2D array of person objects because it has a pure virtual function	
	for(int i = 0; i<10; i++)
	{
		if(rand()%2)
			people[i] = new Student;
		else
			people[i] = new LazyStudent;
	}
	for(int i = 0; i < 10; i++)
	{
		people[i]->doAct(); // need to use the arrow to dereference to whatever type of person is in that slot in the array.
	}
	return 0;
}
