#include "functions.hh"

Poly addPolynomials(Poly p1, Poly p2) {
	if (p1.getLength() < p2.getLength()) {
		while (p1.getLength() < p2.getLength()) {
			p1.addToStart(0);
		}
	}
	if (p2.getLength() < p1.getLength()) {
		while (p2.getLength() < p1.getLength()) {
			p2.addToStart(0);
		}
	}
	// now polynomials are of equal length
	Poly p;
	Node *P1 = p1.getHead();
	Node *P2 = p2.getHead();
	while (P1 != NULL) {
		p.append((P1->value) + (P2->value));
		P1 = P1->next;
		P2 = P2->next;
	}
	return p;
}

Poly subtractPolynomials(Poly p1, Poly p2) {
	if (p1.getLength() < p2.getLength()) {
		while (p1.getLength() < p2.getLength()) {
			p1.addToStart(0);
		}
	}
	if (p2.getLength() < p1.getLength()) {
		while (p2.getLength() < p1.getLength()) {
			p2.addToStart(0);
		}
	}
	// now polynomials are of equal length
	Poly p;
	Node *P1 = p1.getHead();
	Node *P2 = p2.getHead();
	while (P1 != NULL) {
		p.append((P1->value) - (P2->value));
		P1 = P1->next;
		P2 = P2->next;
	}

	// now let's clear out any remaining leading zeroes in p. 
	p.deleteLeadingZeroes();
	return p;
}

Poly multiplyPolynomials(Poly p1, Poly p2) {
	Poly p; 
	if (p1.getLength() < p2.getLength()) {
		while (p1.getLength() < p2.getLength()) {
			p1.addToStart(0);
		}
	}
	if (p2.getLength() < p1.getLength()) {
		while (p2.getLength() < p1.getLength()) {
			p2.addToStart(0);
		}
	}
	// now input polynomials are the same size. let's fill the output poly
	// with zeroes
	p.addZeroestoStart(2 * p2.getLength() - 1);
	int i = 0;
	Node* tempP1 = p1.getHead();
	do {
		
		Node* tempP2 = p2.getHead();
		Poly toAdd;
		int j = 0;
			do {
				double next = (tempP1->value)*(tempP2->value);
				toAdd.append(next);
				j++; 
				tempP2 = tempP2->next;
				} while (j <p2.getLength());
		toAdd.addZeroestoStart(i);
		toAdd.addZeroestoEnd(p.getLength() - toAdd.getLength());
		p = addPolynomials(p, toAdd);
		i++;
		tempP1 = tempP1->next;
	} while (i < p1.getLength());


	// now let's clear out any leading zeroes. 
	p.deleteLeadingZeroes(); 
	return p;
}