#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string> 
using namespace std;

class Person
{
	public:
		Person();
		Person(string name, int id);
		friend ostream &operator <<(ostream& lhs, const Person& rhs);
	private:
		int id;
};

Person::Person()
{
	id = 0;
	name = "John Doe";
}
Person::Person(string name, int id)
{
	this -> name = name;
	this -> id = id;
}		

ostream& operator<<(ostream& lhs, const Person& rhs)
{
	lhs << Name << rhs.name << endl;
	lhs << ID << rhs.id << endl;
}

int main()
{
	//Three practicals
	//Hour per practical 40 Marks per practical.
	
	//Wrtiting
	ofstream fout;
	fout.open("RandomText.txt");
	fout << "This is Pedro!" << endl;
	fout.close();
	cout << "Successful Write to File!" << endl;
	system("Pause");
	
	//Reading
	ifstream fin;
	fin.open("RandomText.txt");
	string junk = "";
	//fin.getline(junk, 3); Not practical, we dont know the length
	while (getline(fin, junk) )
	{
		cout << junk << endl;
	}	//This used cpp strings and streams where the string knows it's length!
	fin.close();
	
	//Rewrite and append	
	ofstream fdata("NewData.txt", ios::trunc | ios::app); //Overloaded constructor
	for (int i = 0 ; i < 100000 ; i++)
	{
		fdata << i << " ";
	}
	fdata.close();
	cout << "Successful Write to File!" << endl;
	system("Pause");
	
	//Manip
	ifstream indata;
	indata.open("NewData.txt");
	int total = 0;
	int number = 0, counter = 0;
	double average = 0.0;
	while(indata >> number )
	{
		counter += 1;
		total += number;
	}
	average = total / static_cast<double>(counter) ;
	cout << "Average is: " << average << endl;
	system("pause");
	indata.close();
	
	//output stream for people
	Person  John("John Dunno", 1234);
	ofstream fPerson;
	fPerson << john;
	fPerson.close();
	
	return 0;
}
