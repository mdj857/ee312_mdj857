#include <stdlib.h>
class Node{
	
public:
	double value;
	Node* next;
	Node(double v, Node* n);
};

class Poly{

public:
	Poly();
	Node* getHead();
	void Poly::setHead(Node *n);
	int getLength();
	void print();
	void append(double v);
	void Poly::addZeroestoStart(int z);
	void Poly::addZeroestoEnd(int z);
	void Poly::addToStart(double v);
	void Poly::deleteFirst();
	void Poly::deleteLeadingZeroes();

private: 
	Node* head;
	int length; 
};
