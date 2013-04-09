// RosalindQuestion3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "DNA.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char theChar;
	FILE* in;
	FILE* out;
	DNAstack theStack;
	
	in=fopen("in.txt","r");
	out=fopen("out.txt","w");

	if(in == NULL || out == NULL)
	{
		printf("critical error\n");
		exit(EXIT_FAILURE);
	}
	theChar=fgetc(in);
	while(theChar!=EOF)
	{
		if(theChar=='a' || theChar=='A' || theChar=='g' || theChar=='G' || theChar=='c' || theChar=='C' || theChar=='t' || theChar=='T')
		{
			theStack.push(theChar);
		}
		theChar=fgetc(in);
	}
	theStack.outputComplimentGene(out);

	return 0;

}

