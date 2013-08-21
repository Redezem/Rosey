#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <boost/math/special_functions/factorials.hpp>

typedef struct {
	int indexno;
	char *symbols;
} lexalpha;


class megaLexx{
public:
	megaLexx();
	void getLexicon();
	void printOutWords();
private:
	lexalpha lexyboi;
	int wordsize;
	std::string inFile;
	std::string outFile;
	void recursiveStringBuilder(int,std::vector<char> ); //not sure if going to do this. Want to look at VS datastructs.
};