//FIBBONACCI SEQUENCER DOHICKYMAGIG
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	long long int i,repTime,toProd, totalnumber, numWab,numTee,numPre;
	
	repTime=100;
	toProd=100;

	numWab=numTee=numPre=0;
		
	while(toProd>5 || repTime>40)
	{
	cout << "Input number of rabbits per gen (<=5): ";
	cin >> toProd;
	cout << "Input number of generations (<=40): ";
	cin >> repTime;
	}
	
	
	
	for(i=0;i<repTime;i++)
	{
		if(numWab==0 && numPre==0 && numTee==0)
		{
			numTee=1;
		}else{
			numWab+=numTee;
			numTee=0;
			numTee+=toProd*numPre;
			numWab+=numPre;
			numPre=0;
			numPre+=numWab;
			numWab=0;
		}
		cout << "Cycle complete\n";
	}
	
	i=numWab+numPre+numTee;
	
	cout << "Num of Rabbits is " << i << "\n";
	return 0;
}
