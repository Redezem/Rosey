#include <stdio.h>
#include <stdlib.h>

struct GeneString
{
	char *label;
	double gcCont;
};

char* getLabel(FILE* f)
{
	char c, *outStr;
	int i;
	
	outStr=(char*)malloc(sizeof(char)*15);
	c=' ';
	i=0;
	
	while(c!='\n' && c!=EOF)
	{
		c=getc(f);
		outStr[i]=c;
		i++;
	}
	
	return outStr;
}

double getGCCont(FILE* f, int* areWeDoneYet)
{
	char c;
	double outint, totes;
	
	c=' ';
	outint=0;
	totes=0;
	while(c!='>'&&c!=EOF)
	{
		c=getc(f);
		if(c=='G' || c=='C' || c=='g' || c=='c')
		{
			outint++;
		}
		if(c=='G' || c=='C' || c=='A' || c=='T' || c=='g' || c=='c' || c=='a' || c=='t')
		{
			totes++;
		}
	}
	if(c==EOF)
	{
		*areWeDoneYet=1;
	}
	outint=outint/totes;
	return outint;
}

int main(int argc, char** argv)
{
	struct GeneString StringofStrings[10], *Genetik;
	int i,e;
	double n;
	FILE* f;
	
	f=fopen("infile", "r");
	if(f==NULL)
	{
		printf("where is infile?!\n");
		exit(EXIT_FAILURE);
	}

	getc(f); //get the first arrow.
	
	for(i=0;i<10;i++)
	{
		StringofStrings[i].label=" ";
		StringofStrings[i].gcCont=0.0;
	}
	
	i=0;
	e=0;
	while(i!=1)
	{
		Genetik=(struct GeneString*)malloc(sizeof(struct GeneString));
		Genetik->label=getLabel(f);		
		Genetik->gcCont=getGCCont(f, &i);
		StringofStrings[e]=*Genetik; //assumably that means it copies across...
		free(Genetik);
		Genetik=NULL;
		e++;
		//hope to god that this does not happen more than 10 times
	}
	e=0;
	for(i=0;i<10;i++)
	{
		if(StringofStrings[i].gcCont>e)
		{
			n=StringofStrings[i].gcCont;
		}
	}
	for(i=0;i<10;i++)
	{
		if(StringofStrings[i].gcCont==n)
		{
			printf("%s%f\n",StringofStrings[i].label,StringofStrings[i].gcCont*100.0);
		}
	}
	return 0;
}
