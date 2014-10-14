#include"ModeAnalyser.h"
using namespace std;
void ModeAnalyser::analyser(int* data, int size)
{
	int* unique = new int[size];
	int numUniques = 0;
	for(int i = 0; i < size; i++)
	{
		if(isUnique(data[i],data, size))
		{
			unique[numUniques] = data[i];
			numUniques++;
		}
	}
	int* counts = new int[numUniques+1];
	
	for(int i = 0; i<numUniques; I++)
	{
		counts[i] = countOccourences(uniques[i], data, size);
	}
	int maxCount = findMax(counts, numUniques+1);
	
	for(int i = 0; i <= numUniques, i++)
	{
		if(counts[i]==maxCount)
		cout<<uniques[i]<<" " << endl;
	}
	
	delete [] counts;
	delete [] unique;
}

bool ModeAnalyser::isUnique(int symbol, int* data, int size)
{
	for(int i = 0; i < size;i++)
	{
		if (array[i]==symbol)
			return false;
		return true;
	}
}

int ModeAnalyser::countOccourences(int symbol, int* data, int size)
{
	 int intReturn = 0;
	 for(int i = 0; i < size;i++)
	 {
		if(data[i]==symbol)
		{
			intReturn++;
		}
		return intReturn;
	 }
}

int ModeAnalyser::findMax(int* data, int size)
{
	int max = data[0];
	for(int i = 1; i< size; i++)
	{
		if(data[i]>=max)
		max = data[i];
	}
	return max;
}
