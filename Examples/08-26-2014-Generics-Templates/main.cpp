//Do not share
//An abstract data type separates logical properties from actual implementation
//Abstraction might not even involve OOP, removing the unnecessary details of the problem to be as general as possible.

//Don't get confused between generics and generalisation.
//A generic 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DataSet.h"
#include <vector>

using namespace std;

/*int TestMax(int a, int b)
{
	if (a>=b)
		return a;
	else 
		return b;
} 

//Now what if we want to calculate the max of two doubles or chars

char TestMax(char a, char b)
{	
	if (a>=b)
		return a;
	else	
		return b;
}

//Impractical

Student TestMax(Student a, Student b)
{
	if (a>=b)
		return a;
	else	
		return b;
}*/

//Better but still dicey, we need to fix this.
//Code repetition. It's called a code smell. It is a sign that something is going wrong

//We should make a template for this max function where only the types change. That would be clever.
//Template Function (Generics)

template <typename T>

T UJMax(T a, T b)
{
	if (a>=b)
		return a;
	else	
		return b;
}

//This works FTW

int main()
{
	cout << UJMax(1,2) << endl;
	cout << UJMax('a', 'A') << endl;
	string s1("Hello"), s2("World");
	cout << UJMax(s1,s2) << endl;
	//This is called static polymorphism. Occurs at compile time due to the context (data types used!)
	//The other polymorphism is called Fancy Dynamic polymorphism.'
	system("Pause");
	//Vectored stuff'
	srand(time(NULL));
	int size = rand() % 11;
	//int * i = new int[size];
	vector<int> v(size); //type integer + initial size [size];
	for (int i = 0; i< size ; i++)
	{
		v[i] = i;
	}
	for (int i = 0; i< size ; i++)
	{
		cout << v[i] << endl;
	}
	
	//using our library
	DataSet ds(size);
	for (int i = 0; i< size ; i++)
	{
		ds[i] = i;
	}
	for (int i = 0; i< size ; i++)
	{
		cout << ds[i] << endl;
	}	
	
	return 0;
}
