#include<iostream>
#include<cstdlib>
using namespace std;

//Constants
enum ErrorCode
{
	NUMBER_OUT_OF_RANGE = 1, //Notice the comma!
	INVALID_COMMANDLINE_ARGUMENTS,
	EXECUTE_OP_IMP_FAILURE,
	MAILBOX_OUT_OF_RANGE;
}

//Prototyping and structures
struct Operation
{
	int Instruction;
	int Data;
};

struct LittleManComputer
{
	Operation Mailboxes[100];
	int calculator;
	int pc;
	void (*run) (LittleManComputer* self);
	void (*executeOp)(LittleManComputer* self);
	void (*setOp)(LittleManComputer* self, int index, Operation op);
};

Operation convertToOp(unsigned int number);
void runImp(LittleManComputer* self);
void executeOpImp(LittleManComputer* self);
LittleManComputer* makeLMC();
void (*setOpImp)(LittleManComputer* self, int index, Operation op);

int main ()
{
	//Introduction
	cout << "This is a little man computer example.\nSo much pain is going to be felt whilst coding this.\n \nDownload the example program from EVE." << endl;
	system("Pause");
	//End Introduction
	LittleManComputer comp = makeLMC();
	comp->run(comp);
	return 0;
}

Operation convertToOp(unsigned int number)
{
	if (number < 0)
	{
		exit(NUMBER_OUT_OF_RANGE);
		if (number > 902)
		{
			exit(NUMBER_OUT_OF_RANGE);
		}
	}
	Operation op;
	int digit = number / 100;
	op.instruction = digit
	op.data = 
	switch(digit)
	{
		case 0: //HALT
		{
			
			break;
		}
		case 1: //ADD
		{
			break;
		}
		case 2: //SUBTRACT
		{
			break;
		}
		case 6:
		{
			self->pc = op.data;
			breakl
		}
		case 7:
		{
			if (self->calculator == 0)
				self->pc = op.data;
		}
	}
}

void runImp(LittleManComputer* self)
{
	while(true)
	{
		self->executeOp(self);
		self->pc++;
	}
}
void executeOpImp(LittleManComputer* self)
{
	Operation op = self->mailboxes[self->pc];
	if (self->pc > 99)
	{
		exit(MAILBOX_OUT_OF_RANGE);
	}
	switch(op.Instruction)
	{
		case 0: 
			exit(EXECUTE_OP_IMP_FAILURE);
		break;
		case 9:
			if  (op.data ==1)
			{
				cout << self->calculator<<endl;
			} else if (op.data == 2 )
			{
				cin >> self->calculator;
			}
		break;
	}
}
LittleManComputer makeLMC()
{
	LittleManComputer lmc = new LittleManComputer;
	lmc->run = &runImp;
	lmc->executeOp = &executeOpImp;
	lmc->setOp = &setOpImp;
	lmc-> calculator = 0;
	lmc->pc=0;
}

void (*setOp)(LittleManComputer* self, int index, Operation op)
{

}
