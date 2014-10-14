#include "DataSet.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
int DataSet<T>::allocData(int size)
{
	data = new int [size];
	this->size = size;
}

template <typename T>
DataSet<T>::DataSet()
{
	allocData(DEFAULT_SIZE);
}

template <typename T>
DataSet<T>::DataSet(int size)
{
	allocData(size);
}

template <typename T>
DataSet<T>::DataSet(const DataSet& other)
{
	allocData(other.size);
	for (int i = 1; i < size; i++)
	{
		data[i] = other.data[i];
	}
}	

template <typename T>
DataSet& DataSet<T>::operator=(const DataSet& rhs)
{
	//the element may already exist. some idiot may try to assign me to myself.
	if (this != &rhs) //The address of the RHS
	{
		delete [] data;
		allocData(rhs.size);
		for (int i = 1; i < size; i++)
		{
			data[i] = rhs.data[i];
		}
	}
	return this* ;
}

template <typename T>	
int& DataSet<T>::operator[](int index)
{
	
	if ((index < 0)||(index >= size))
	{
		cerr<< "Fail" << endl;
		exit(FAIL);
	}
	return data[index];
	//Only works for Reading! if it is only int instead of int&
	
}
	
template <typename T>
DataSet<T>::~DataSet() //The 3 Amigos
{
	delete [] data;
	data = NULL;
}
