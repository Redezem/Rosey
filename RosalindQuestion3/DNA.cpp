#include "DNA.h"
#include <stdio.h>

//DNApair Function
void DNApair::insertPair(char inChar)
{
	switch(inChar)
		{
		case 'A':
		case 'a':
			standard='A';
			compliment='T';
			break;
		case 'C':
		case 'c':
			standard='C';
			compliment='G';
			break;
		case 'G':
		case 'g':
			standard='G';
			compliment='C';
			break;
		case 'T':
		case 't':
			standard='T';
			compliment='A';
			break;
		case ' ':
		case '\n':
		case EOF:
			break;
		default:
			printf("UNEXPECTED CHAR DETECTED!  %c\n",inChar);
			break;
		}
}
char DNApair::returnComp()
{
	return compliment;
}
char DNApair::returnStan()
{
	return standard;
}

//DNA Stack function

DNAstack::DNAstack()
{
	cursor=NULL;
	first=NULL;
	last=NULL;
}

void DNAstack::next()
{
	if(cursor==NULL)
	{
		if(first==NULL)
		{
			printf("Error: list empty and next given D:\n");
			return;
		}else{
			cursor=first;
			return;
		}
	}
}