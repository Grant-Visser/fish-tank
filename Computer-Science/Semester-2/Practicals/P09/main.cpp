#include"DLLWrapper.h"
#include"ErrorHandling.h"
#include<iostream> 
#include<cstdlib>
#include<fstream>

using namespace std;

int main()
{
	const int Rows =5;
	const int Cols = 7;
	DLLWrapper thing("pirateLibrary.dll", "generateMap", "displayMap");
	int** map =  thing(Rows,Cols);
	thing(Rows,Cols, map);
	system("Pause");
	//File Ops
	ofstream outfile;
	outfile.open("data.txt", ios::in | ios::out);
	try	
	{
		if (outfile.fail())
			throw FileOpeningException();
	}
	catch (FileOpeningException& e)
	{
		cerr << "File could not be opened!" << endl;
		exit(-4);
	}
	catch (...)
	{
		cerr << "Something weird happened!" << endl;
		exit(-5);
	}
	
	try 
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int k = 0; k < Cols; k++)
			{
				outfile << map[i][k];
				if (outfile.fail())
					throw FileManipException();
			}
			outfile << endl;
		}
	}
	catch (FileManipException& e)
	{
		cerr << "Error in Writing to File!" << endl;
		exit(-6);
	}
	catch (...)
	{
		cerr << "That's not supposed to happen! :(" <<endl;
		exit(-5);
	}
	
	return 0;
}
