#include <iostream>
#include <algorithm>
#include <boost/math/special_functions/factorials.hpp>

int getInsertNum(char*);
double getPermutes(int);
void printPermutations(int);
int* getPermArr(int);

int main(int argc, char** argv)
{
	int insertNum;
	if(argc>1)
	{
//	insertNum = getInsertNum(argv[1]);
	insertNum = 7;
	printPermutations(insertNum);
	}
	return 0;
}

void printPermutations(int numz)
{
	int* permuteArr, i;
	std::cout << getPermutes(numz) << "\n";
	permuteArr = getPermArr(numz);
	do
	{
		for(i=0;i<numz;i++)
		{
			std::cout << permuteArr[i] << " ";
		}
		std::cout << "\n";

	}while (std::next_permutation(permuteArr,permuteArr+numz) );
	return;
}

int getInsertNum( char* argv)
{
	int extractedNum;

	
	extractedNum=(int)argv[0];


	return extractedNum;
}

double getPermutes(int innum)
{
	double outNum;

	outNum = boost::math::factorial<double>((double)innum);

	return outNum;
}

int* getPermArr(int inNum)
{
	int* permArr,i;

	permArr = new int[inNum];
	for(i=0;i<inNum;i++)
	{
		permArr[i]=i+1;
	}
	return permArr;
}
