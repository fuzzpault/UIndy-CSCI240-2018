/* Name: Paul Talaga
   Date: 1/30/17
   Desc: Testing file for the Rational class.
*/
#include <iostream>
#include "VList.h"

int main(){
  // Example usage of the Rational class
  
  VList a;
  cout << a.size() << " = 0" << endl;
  a.push_back(5);
  cout << a.size() << " = 1" << endl;
  cout << a.at(0) << " = 5" << endl;
  a.at(0) = 10;

  cout << a.at(0) << " = 10" << endl;
  
  cout << a.getAsString() << endl;
  
  
  
  return 0;
}