#include"MeanAnlayser.h"
#include<iostream>
using namespace std;
void MeanAnalyser::analyser(int* data, int size)
{
	int aggregate = 0;
	for(int i = 0; i<size; i++)
		aggregate = agregate + data[i];
	cout<< static_cast <double>aggregate / size<< endl;
}
