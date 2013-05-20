#include "Mendel.h"

Mendel::Mendel(char* inName)
{
	importFile(inName);
}

void Mendel::Process()
{
	probabilityOfDominant=0.0;
	probabilityOfDominant=dAndB();
	probabilityOfDominant=probabilityOfDominant+dAndR();
	probabilityOfDominant=probabilityOfDominant+bAndR();
	probabilityOfDominant=probabilityOfDominant+dAndD();
	probabilityOfDominant=probabilityOfDominant+bAndB();
	probabilityOfDominant=probabilityOfDominant+rAndR();
	printf("And the answer is: %f\n",probabilityOfDominant);
}

void Mendel::importFile(char* inName)
{
	FILE* f;

	f=fopen(inName, "r");
	if(f==NULL)
	{
		printf("No file 'in.txt' detected. Switching to manual entry.\n");
		printf("HomoZ Dom?: ");
		scanf("%d",&homoDominant);
		printf("HomoZ Rec?: ");
		scanf("%d",&homoRecessive);
		printf("HeteroZ?: ");
		scanf("%d",&heteroBoth);
	}
	else
	{
		fscanf(f,"%d %d %d",&homoDominant, &heteroBoth, &homoRecessive);
	}
	total=homoDominant+heteroBoth+homoRecessive;
	printf("Imported HomoD: %d HetB: %d HomoR: %d\n-----\nTotal: %d\n",homoDominant, heteroBoth,homoRecessive,total);
	total=(homoDominant*heteroBoth)+(heteroBoth*homoRecessive)+(homoDominant*homoRecessive)+(homoDominant*homoDominant)/2.0+(heteroBoth*heteroBoth)/2.0+(homoRecessive*homoRecessive)/2.0;
	printf("Total possible combinations: %d", total);
}

double Mendel::dAndB()
{
	double prob;

	prob=(double)(homoDominant*heteroBoth);
	prob=prob/(double)total;
	prob=1*prob; //Definitely gonna get the dominant phenotype
	
	return prob;
}

double Mendel::dAndR()
{
	double prob;

	prob=(double)(homoDominant*homoRecessive);
	prob=prob/(double)total;
	prob=1*prob; //Also definitely gonna get that dominant phenotype

	return prob;
}

double Mendel::bAndR()
{
	double prob;

	prob=(double)(heteroBoth*homoRecessive);
	prob=prob/(double)total;
	prob=0.5*prob; //half probability. Brutal.

	return prob;
}

double Mendel::dAndD()
{
	double prob;

	prob=(double)(homoDominant*homoDominant);
	prob=prob/((double)total*2.0);//important, halves the data. Frank and Beth is the same as Beth and Frank!
	prob=1*prob; //yeah, always.

	return prob;
}

double Mendel::bAndB()
{
	double prob;

	prob=(double)(heteroBoth*heteroBoth);
	prob=prob/((double)total*2.0);
	prob=0.75*prob; //three quarters;

	return prob;
}

double Mendel::rAndR()
{
	double prob;

	prob=0.0; //bygone conclusion. there are no dominant genes to carry.
	
	return prob;
}
