
#include<iostream>
#include "New.h"

using namespace std;

int main()
{
	List<char> l;
	for (char letter = 'a'; letter< 'z';letter ++)
	{
		l.insertLast(letter);
	}
	char vowels[] = {'a', 'e', 'i', 'o', 'u', '\0'};
	char *cp = &vowels[0];
	while (cp != '\0')
	{
		cout << *cp<< endl;
		cp++;
	}	
	cout << l << endl;
	
}
