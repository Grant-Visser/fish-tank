#ifndef MODEANALYSER_H
#define MODEANALYSER_H
class ModeAnalyser
{
public:
	void analyser(int* data, int size);
private:
	bool isUnique(int symbol, int* data, int size);
	int countOccourences(int symbol, int* data, int size);
	int findMax(int* data, int size);
};

#endif
