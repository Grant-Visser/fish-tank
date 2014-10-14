#include"Analyser.h"
#include<cstdlib>
#include<iostream>
using namespace std;
Analyser::Analyser()
		{
			size = DEFAULT_SIZE;
			init();
		}
Analyser::Analyser(int size)
		{
			this->size = size;//if it is a pointer we use an arrow, if it is not we use the dot.
			init();
		}
		
void Analyser::setMode(bool mode)
	{	
		this->mode = mode;
	}		//Mutator Function
bool Analyser::getMode() const //Accessor Function
	{
		return mode;
	}	
void Analyser::analyse() const
{
	if(mode==true)
		modeA.analyse(data,size);
	else	
		meanA.analyse(data,size);
}
void Analyser::display() const
{
	for(int i = 0; i < size; i++)
	{
		cout<<data[i]<< " "<<endl;
	}
{
	
~Analyser::Analyser()
{
	delete [] data;
	data = NULL; //Not useful.
}
void Analyser::init()
{
	data = new int[size];
	for (int i = 0; i< size; i++)
	{
		data[i] = rand() % 11;
	}
	mode = true;
}
