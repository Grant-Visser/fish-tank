#ifndef ANALYSER_H
#define ANALYSER_H
const int DEFAULT_SIZE = 10;
class Analyser
{
	public: 
		Analyser();
		Analyser(int size);
		
		void setMode(bool mode); //Mutator Function
		bool getMode() const; //Accessor Function
		
		void analyse() const;
		void display() const;
		
		~Analyser();
	private:
		void init();
		ModeAnalyser modeA;
		MeanAnalyser meanA;
		bool mode;
		int*data;
		int size;

};

#endif
