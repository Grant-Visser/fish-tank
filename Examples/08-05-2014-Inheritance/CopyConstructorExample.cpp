#include<iostream>
#include<cstdlib>

using namespace std;

class Sequence
{
	public:
		Sequence();
		Sequence(int size);
		Sequence(const Sequence& original); //Copy constructor
		int getAt(int index);
		void setAt(int Index, int Value);
		virtual void generate();
		virtual ~Sequence(); //Tag as virtual to get expected results.
	protected: //we want these to be visuble to the children and not everything or nothing
		int* data;
		int size;
};
Sequence::Sequence()
{
	size = 10;
	data = new int[size];
}
Sequence::Sequence(int size)
{
	this->size = size;
	data = new int[size];
}
int Sequence::getAt(int index)
{
	if((index >= 0) && (index < size))
		return data[index];
	else
		exit(-1);
}
void Sequence::setAt(int Index, int Value)
{
	if((index >= 0) && (index < size))
		data[index] = Value ;
	else
		exit(-2);
}

Sequence(const Sequence& original)
{
	size = original.size;
	data = new int[size];
	for (int i = 0; i< size;i++)
		data[i] = original.data[i];
}

void Sequence::generate()
{
	
}

Sequence::~Sequence()
{
	cout << "IN Destructor" << endl;
	delete [] data;
}

class CountingSequence: public Sequence
{
	public: 
		void generate();
};

void CountingSequence::generate()
{
	for(int i = 0; i< size; i++)
		data[i] = i+1;
}

void change(CountingSequence seq)
{
	seq.setAt(0,1337);
}
int main()
{
	/*CountingSequence s1;
	change(s1);
	cout << s1.getAt(0) << endl;
	//Destructor run twice. Value 1337 is not passed into the array by reference. You have to create a deep copy where you copy the size and data.
	*/
	Sequence* sp = new CountingSequence;
	 delete sp ;
	return 0;
{
