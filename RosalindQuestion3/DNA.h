class DNApair
{
private:
	char standard,compliment;
public:
	void insertPair(char);
	char returnStan();
	char returnComp();

	DNApair* next;
	DNApair* prev;
};

class DNAstack
{
private:
	DNApair* first;
	DNApair* last;
	DNApair* cursor;
	void next();
	void prev();
public:
	DNAstack();
	void push(char);
	void outputStandardGene(FILE*);
	void outputComplimentGene(FILE*);
};
