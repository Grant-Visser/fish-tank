//if (s1.equals(s2))
//as oppsed to if(s1==s2) //Using opperands in code with custom data types.
//This is called opperator overloading.
//you define a function with an arbirary name that would behave like the == Opperator.

//Header
//ujstring.h
#ifndef UJSSTRING_H
#define UJSSTRING_H
enum UJStringError
{
  NULL_C_STRING
};

class UJString
{
public:
  UJString();
  UJString(const char* cs);
  UJString(const UJString&other);//Copy constructor

  bool operator==(const UJString& other); //Everytime you pass the UJString as a parameter, you copy it. It you use reference you just pass a memory address. You use the const to disable editing the reference
	//Think of it as being called opperator =='
  bool operator!=(const UJString& other);
  ~UJString();
private:
  void makeContents(int length);
  char* contents;
  int length;
};
#endif


//Lib.cpp
#include "UJstring.h"
#include<iostream>
#include<cstdlib>
#include<cString>

UJString::UJString()
  {
   makeContents(1) 
   contents[0] = '\0';
  }
  UJString::UJString(const char* cs)
  {
      if (cs == NULL)
      {
	 cerr << "Null c-String!" << endl;
	 exit(NULL_C_STRING);
      }
      //Finding the size of the cString
      makeContents(strlen(cs));
      for (int i = 0; i < length; i++)
      {
	  contents[i] = cs[i];
      }
  }
  UJString::UJString(const UJString&other)//Copy constructor
  {
    //Make me like the other one, the other one is determined by his contents
    makeContents(other.length);
    for (int i = 0; i< length; i++)
    {
      contents[i] = other.contents[i];
    }
  }
  
  UJString::~UJString()
  {
     delete [] contents;
  }
  
  bool UJString::operator==(const UJString& other)
  {
    if(length != other.length)
      return false;
    for(int i = 0; i < length; i++)
    {
	if(contents[i] != other.contents[i])
	  return false;
    }
    return true;
  }
  
  bool operator!=(const UJString& other)
  {
      return !((*this) == other);
  }

//Main 
#include"UJString"
#include<iostream>
using namespace std;
int main()
{
  UJString hello("Hello");
  UjString world("World");
  UJString hello2("Hello");
  if(hello == world)
  {
     cout << "Hello is World" << endl;
  } else
  {
      cout << "Hello Is not World" << endl;
  }
  if (hello == hello2)
  {
    cout << "Hello is Hello" << endl;
  }else
  {
    cout << "Hello is not hello" << endl; 
  }
  UJString work("work");
  if (work != world)
  {
    cout << "Work Is not the world"<< endl;
  }else
  {
   cout << "Work is the world" << endl; 
  }
  return 0;
  
}
