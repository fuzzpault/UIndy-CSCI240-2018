/* Name: Paul Talaga
   Date: 10/16/2018
   Desc: Testing file
*/
#include <iostream>
#include "BST.h"


string cleanString(string input){
    // Remove duplicate strings
    string::size_type pos = 0;
    /*while((pos = input.find("  ", pos)) != string::npos){
        input.replace(pos, 2, " ");
    }*/
    // Remove beginning space
    while(input[0] == ' ')input.replace(0,1,"");
    // Remove ending space
    while(input[input.length() - 1] == ' ')input.replace(input.length() - 1,1,"");
    return input;
}

int main(){
  // Fill me in to experiment
  cout << "-" << cleanString("     hello  this has   multiple spaces  ")  << "-" << endl;
  
  return 0;
}