#include "polynomial.hh"
#include <stdio.h>

Node::Node(double v, Node* n){
	value = v;
	next = n;
}

Node* Poly::getHead(){
	return head;
}

int Poly::getLength() {
	return length; 
}
void Poly::setHead(Node *n) {
	head = n;
}
Poly::Poly(){
	Node *x = new Node(0, NULL);
	length = 0; 
}

void Poly::append(double v){
	if (getHead() == NULL) {
		Node* n = new Node(v, NULL); 
		setHead(n);
	}
	else {
		Node* temp = getHead();
		while (temp ->next != NULL) {
			temp = temp->next;
		}
		Node* n = new Node(v, NULL);
		temp->next = n;
		n->next = NULL;
	}
	length++;
}
// takes number of zeroes to add to the front and adds that mant to poly
void Poly::addZeroestoStart(int z) {
	for (int i = 0; i < z; i++) {
		addToStart(0);
	}
}

void Poly::addZeroestoEnd(int z) {
	for (int i = 0; i < z; i++) {
		append(0);
	}
}

void Poly::addToStart(double v){
	Node* n = new Node(v, NULL);
	n->next = getHead();
	setHead(n);
	length++;
}

// deletes first node in polynomial
void Poly::deleteFirst() {
	Node* temp = getHead();
	setHead(temp->next);
	delete temp;
	length--;
}

void Poly::deleteLeadingZeroes() {
	Node *temp = getHead();
	while (temp->next != NULL && temp->value == 0) {
		deleteFirst(); 
		temp = getHead();
	}
}

void Poly::print(){
	Node* temp = getHead();
	while(temp!=0){
		printf(" %.2f-->", temp->value);
		temp = temp->next;
	}
	printf("\n");
}