#ifndef DLLWRAPPER_H
#define DLLWRAPPER_H
#include <cstdlib>
#include <windows.h>
#include "ErrorHandling.h"

typedef  int** (*IntPPIntInt)(int, int);
typedef  void (*VoidIntIntIntPP)(int,int,int**);

class DLLWrapper
{
public:
	DLLWrapper();
	DLLWrapper(char* Name, char* Function1, char* Function2);
	int** operator()(int Rows, int Cols);
	void operator()(int Rows, int Cols, int** World);
	~DLLWrapper();
private:
	HINSTANCE handle;
	DLLWrapper(const DLLWrapper& other);
	void* operator new(size_t size); 
	IntPPIntInt Func1 = NULL;
	VoidIntIntIntPP Func2 = NULL;
};

#endif
