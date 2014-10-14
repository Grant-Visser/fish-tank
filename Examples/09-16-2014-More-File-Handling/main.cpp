#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct Person
{
	int id;
	double age;
	char name[25];
};

int main()
{
	fstream fPeople;
	fPeople.open("people.dat", ios::binary | ios::in | ios::out | ios::app);
	
	Person me {9458769, 31.8, "Mr SoAndSo"}; //This is pretty cool!
	/*me.id = 9458769;
	me.age= 31.8;
	char*name = (char*)("Mr. SoAndSo");
	strcpy(me.name,name, strlen(name);*/
	fPeople.write(reinterpret_cast<char*>(&me), sizeof(Person)); //Reinterpret to char* from the address in memory of me
	
	/*Person you;
	you.id = 94230233;
	you.age = 20.1;
	you.name = "Bright McSpark";
	fPeople.write(reinterpret_cast<char*>(&you), sizeof(Person));
	fPeople.close();*/
	
	fstream in("people.dat", ios::binary | ios::in | ios::out | ios::app);
	int index = 1;
	in.seekg(index*sizeof(Person), ios::beg); //seek to get location;
	Person p;
	in.read(reinterpret_cast<char*>(&p), sizeof(Person));
	cout<< p.name<< endl;
	in.close();
	
	fstream fSize("people.dat", ios::binary | ios::in | ios::out | ios::app);
	fSize.seekg(0, ios::end);
	int size_in_bytes = fSize.tellg(); //Important!!
	cout << "Number of Records: " << size_in_bytes/sizeof(Person) << endl;
	
	fSize.close();
	return 0;
}
