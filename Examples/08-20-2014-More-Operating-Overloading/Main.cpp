//DataSet.h
#ifndef DATASET_H
#define DATASET_H

class DataSet
{
	public:
		DataSet();//Constructor
		Dataset& operator=(const DataSet& rhs);//Assignment Constructor (overloaded assignment constructor)
		//a=b=c=d etc. No void!
		DataSet(const DataSet& other);//Copy Constructor
		DataSet operator+(int rhs);//other operators (RHS Opperator)
		friend DataSet operator+(int lhs,const DataSet& rhs)		//Has access to the private state of the object they are friend to
		
		~DataSet();//Destructor
	private:
		int* data;
		int length;
};
#endif

//DataSet.cpp
#include"DataSet.h"
using namespace std;
		DataSet::DataSet()//Constructor
		{
			data = NULL;
			length = 0;
		}
		Dataset& DataSet::operator=(const DataSet& rhs)//Assignment Constructor (overloaded assignment constructor)
		//a=b=c=d etc. No void! Allows Chaining of operators
		{
			if (this != &rhs)//What if a = a (self assignment) we're deleting the values to be used!!!
			{
				
				if(data != NULL) 
				{
					delete [] data;
				}
				length = rhs.length;
				if (rhs.data == NULL)
				{
					data = NULL;
				}else
				{
					data = new int [length];
					for (int i = 0; i< length; i++)
					{
						data[i] = rhs.data[i];
					}
				}
			}
			return *this //This is a DataSet reference! It is dereferenced to be returned as DataSet
		}
		DataSet::DataSet(const DataSet& other);//Copy Constructor
		{
			length = other.length;
			if (other.data == NULL)
			{
				data = NULL;
			} else
			{
				data = new int [length];
				for(int i = 0; i<length;i++)
				{
					data[i] = other.data[i]; //Dot because it is not a pointer!
				}
			}
		}
		
		DataSet DataSet::operator+(int rhs)
		{
			DataSet ret;
			ret.length = length+1;
			ret.data = new int [ret.length];
			for (int i = 0; i< length; i++)
			{
				ret.data[i] = data[i];
			}
			ret.data[ret.length-1] = rhs; //Moving the new value appended to the end of it!
			return ret;
		}
		
		DataSet operator+(int lhs,const DataSet& rhs) //Is not a member function and Friend doesn't belong in the public .cpp
		{
			DataSet ret;
			ret.length = 1 + rhs.DataSet; //Look for the change from the LHS addition!
			ret.data = new int [ret.length];
			for (int i =  1;i < ret.length ; i++)
			{
				ret.data[i] = rhs.data[i-1];//Shit, Draw it out!
			}
			ret.data[0] = lhs;
			return ret;
		}
		DataSet::~DataSet()//Destructor
		{
			if(data != NULL)
			{
				delete [] data;
				data = NULL;
			}
		}
		
//Main.cpp
#include"DataSet.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{

	return 0;
}
