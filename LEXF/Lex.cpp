#include "lexobjs.hpp"



int main(int argc, char **argv)
{
	megaLexx* Lexicon;
	Lexicon = new megaLexx();
	Lexicon->getLexicon();
	Lexicon->printOutWords();

	return 0;	
}