struct Student //Name of your new data type.
{
	double st1;
	double st2;
	double arrPracs[10];
	Double (*calcPCM)(Student* self);
}; //You Need the Semi-Colon

int impPCM(Student* self)
{
	for totprac = 0.0;
	for(int i = 0; i <10; i++)
	{
		totprac += self ->pracs[i];
	}
	double aveprac = totprac / 10;
	double pcm = st2 * (50/70.0) + aveprac * (20/70.0);
	
}

struct Student
{
	double st1;
	double st2;
	double arrPracs[10];
}Bob, Thandi, Thravesh; //You Need the Semi-Colon and can use A comma separated list to start adding cases of that.

Student genStudent()
{
	Student student;
	student.st1 = rand() % 101;
	student.st2 = rand() % 101;
	for(int i = 0; i < 10; i++)
	{
		student.arrPracs[i] = rand() % 101; 
	}
	return student;
}

int Main()
{
	Student CSC1B[344]; //Static
	Student* csc1b = new Student [344]; //Dynamic
	delete [] csc1b;
	
	Student* sp = new Student;
	(*sp).st1 = 100;
	sp->st1=100;//This and the one above do the same thing.
	return 0;
	
	//Functional Variables
	
}
