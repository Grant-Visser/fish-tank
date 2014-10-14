#ifndef DATASET_H
#define DATASET_H
#inlcude "DataSet.imp"

const int FAIL = -1;
const int DEFAULT_SIZE = 10;

template <typename T>
class DataSet //Of type T
{
public:
	DataSet();
	DataSet(int size);
	DataSet(const DataSet<T>& other);//copy const
	
	DataSet& operator=(const DataSet<T>& rhs);
	
	T operator[](int index);
	
	~DataSet(); //The 3 Amigos
private:
	void allocData(int size);
	T* data ; //Accessors method determines the access to the state of the attribute
	int size;
};
#endif
