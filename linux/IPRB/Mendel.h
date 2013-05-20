#include <stdio.h>
#include <stdlib.h>

class Mendel
{
	private:
		int homoDominant, heteroBoth, homoRecessive;
		int total;
		double probabilityOfDominant;
		void importFile(char*);
		double dAndB();
		double dAndR();
		double bAndR(); // may have to add crosses with themselves. We'll see. You will need to update total in this case.
		double dAndD();
		double bAndB();
		double rAndR();
	public:
		Mendel(char*);
		void Process();
};
