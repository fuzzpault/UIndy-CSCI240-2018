/**
 * Created by Kalpathi Subramanian, 1/30/18
 * Paul Talaga 10/10/2018
 * krs@uncc.edu
 */

#include "Bridges.h"
#include "BSTElement.h"
#include <sstream>

using namespace std;
using namespace bridges;

string toString(int a){
	stringstream s;
	s << a;
	return s.str();
}

BSTElement<int, int>* insert (BSTElement<int, int>* rt, BSTElement<int, int> *new_el);

int main () {

	// note: you must fill in with your Bridges credentials
	Bridges::initialize(11, "<username>", "<insert key>");
	// create a few tree nodes with integer data

	BSTElement<int,int> *el0 = new BSTElement<int,int>(1,1);
	BSTElement<int,int> *el1 = new BSTElement<int,int>(2,2);
	BSTElement<int,int> *el2 = new BSTElement<int,int>(3,3);
	BSTElement<int,int> *el3 = new BSTElement<int,int>(4,4);
	BSTElement<int,int> *el4 = new BSTElement<int,int>(5,5);

	// Set the labels
	el0->setLabel( toString( el0->getKey() ) );
	el1->setLabel( toString( el1->getKey() ) );
	el2->setLabel( toString( el2->getKey() ) );
	el3->setLabel( toString( el3->getKey() ) );
	el4->setLabel( toString( el4->getKey() ) );

	//  link the elements
	insert(el0, el1);
	insert(el0, el2);
	

	Bridges::setDataStructure(el0);
	Bridges::visualize();
}

// Insert new_el node into a tree rooted in rt
BSTElement<int, int>* insert (BSTElement<int, int>* rt, BSTElement<int, int> *new_el) {
	if (rt == nullptr)
		return new_el;
	else if (new_el->getKey() < rt->getKey())
		rt->setLeft(insert(rt->getLeft(), new_el));
	else
		rt->setRight(insert(rt->getRight(), new_el));

	return rt;
}