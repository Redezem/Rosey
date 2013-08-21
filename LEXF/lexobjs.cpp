#include "lexobjs.hpp"


void megaLexx::getLexicon()
{
	std::fstream inFPoint;
	char ifchar;
	std::cout << "Input file location: ";
	std::getline(std::cin, inFile);
	std::cout << "Getting..." << inFile <<"\n";
	std::cout.flush();
	try{
		inFPoint.open(inFile,std::fstream::in);
	}catch(std::exception e){
		std::cout << "Ho shit bro, you done goof'd " << "\n";
		std::cout.flush();
		exit(EXIT_FAILURE); //BAMF fail.
	}
	std::cout << "got\n";
	std::cout.flush();
	ifchar=inFPoint.get();
	while(ifchar != '\n' && ifchar != EOF)
	{
		std::cout << "ifchar is " << ifchar <<"\n";
		std::cout.flush();
		if(ifchar != ' ')
		{
			lexyboi.symbols[lexyboi.indexno]=ifchar;
			lexyboi.indexno++;
		}
		ifchar=inFPoint.get();
	}
	inFPoint >> wordsize; //in theory.... this works.
	inFPoint.close();
}

megaLexx::megaLexx()
{
	//need to make everything blank
	inFile = "";
	outFile = "out.txt";
	lexyboi.indexno=0;
	lexyboi.symbols = new char[10];
}

void megaLexx::printOutWords()
{
	std::vector<char> metaVec;
	recursiveStringBuilder(wordsize,metaVec);
}

void megaLexx::recursiveStringBuilder(int InSize, std::vector<char> InVect)
{
	if(InSize==0)
	{
		std::fstream OutStream;
		int i,size;
		size=InVect.size();
		OutStream.open(outFile,std::fstream::app);
		for(i=0;i<size;i++)
		{
			OutStream << InVect[i];
		}
		OutStream << "\n";
		OutStream.close();
	}
	else
	{
		int i;
		InSize--;
		for(i=0;i<lexyboi.indexno;i++)
		{
			InVect.push_back(lexyboi.symbols[i]);
			recursiveStringBuilder(InSize,InVect);
			InVect.pop_back();
		}
	}
}