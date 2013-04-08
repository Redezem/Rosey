// RosalindQuestion2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	char charofdoom='d';
	
	FILE* in, *out;

	fopen_s(&in,"in.txt","r");
	fopen_s(&out,"out.txt","w");

	while(charofdoom!=EOF)
	{
		charofdoom=fgetc(in);
		switch(charofdoom)
		{
		case 'A':
		case 'a':
			fputc('A',out);
			break;
		case 'C':
		case 'c':
			fputc('C',out);
			break;
		case 'G':
		case 'g':
			fputc('G',out);
			break;
		case 'T':
		case 't':
			fputc('U',out);
			break;
		case ' ':
		case '\n':
		case EOF:
			break;
		default:
			printf("UNEXPECTED CHAR DETECTED!  %c\n",charofdoom);
			break;
		}
	}

	return 0;
}

