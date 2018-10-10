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

int main () {

	// note: you must fill in with your Bridges credentials
	Bridges::initialize(1, "<username here>" , "<key here>");

	// create a few tree nodes with integer data

	BSTElement<int,int> *el0 = new BSTElement<int,int>(1,1);
	BSTElement<int,int> *el1 = new BSTElement<int,int>(2,2);
	BSTElement<int,int> *el2 = new BSTElement<int,int>(3,3);

	// Set the labels
	el0->setLabel( toString( el0->getKey() ) );
	el1->setLabel( toString( el1->getKey() ) );
	el2->setLabel( toString( el2->getKey() ) );

	//  link the elements
	el0->setLeft(el1);
	el0->setRight(el2);
	

	Bridges::setDataStructure(el0);
	Bridges::visualize();
}