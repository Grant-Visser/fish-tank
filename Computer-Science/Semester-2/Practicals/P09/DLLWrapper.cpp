#include "DLLWrapper.h"
#include "ErrorHandling.h"
#include <cstdlib>
#include <windows.h>
#include <iostream>


using namespace std;

	DLLWrapper::DLLWrapper()
	{
		handle = NULL;
		try
		{
			handle = LoadLibrary("Default.dll");
			if (handle)
			{
			
			}else
			throw DLLNameExcpetion ();
		}
		catch (DLLNameExcpetion& e)
		{
			cerr << "DLL not found!" << endl;
			exit(-1);
		}
		catch(...)
		{
			cerr << "Something weird happened"<< endl;
			exit(-1);
		}
	}
	
	DLLWrapper::DLLWrapper(char* Name, char* Function1, char* Function2)
	{

		try
		{
			handle = LoadLibrary(Name);
			if (handle)
			{
				Func1 = (IntPPIntInt)GetProcAddress(handle,Function1);
				Func2 = (VoidIntIntIntPP)GetProcAddress(handle, Function2);
				if (!(Func1 && Func2))
				{
					throw FunctionExtractionException();
				}
			}else
			throw DLLNameExcpetion ();
		}
		catch (DLLNameExcpetion& e)
		{
			cerr << "DLL not found!" << endl;
			exit(-1);
		}
		catch (FunctionExtractionException& e)
		{
			cerr << "Function Extraction Exception!" << endl;
			exit(-2);
		}
		catch(...)
		{
			cerr << "Something weird happened"<< endl;
			exit(-5);
		}
	
	}
	
	int** DLLWrapper::operator()(int Rows, int Cols)
	{
		try 
		{
			int** test = NULL;
			test = Func1(Rows, Cols);
			if (test == NULL)
			{
				throw FunctionInvocationException();
			}
			else return test;
		}
		catch (FunctionInvocationException& e)
		{
			cerr << "Invocation Error!" << endl;
			exit(-3);
		}
		catch(...)
		{
			cerr << "Well, that was strange." << endl;
			exit(-5);
		}
	}
	
	void DLLWrapper::operator()(int Rows, int Cols, int** World)
	{
		Func2(Rows,Cols,World);
	}
	
	DLLWrapper::~DLLWrapper()
	{
		FreeLibrary(handle);
	}
	
	DLLWrapper::DLLWrapper(const DLLWrapper& other)
	{
	}
	
	void* DLLWrapper::operator new(size_t size)
	{
	}
