#ifndef MYSORT_H
#define MYSORT_H
/* Name: Paul Talaga
   Date: 11/16/2018
   Desc: Various sort methods
*/
#include <iostream>
#include <vector>


using namespace std;

template <class T>
void print(const vector<T> &thing){
    cout << "  ";
    for(unsigned i = 0; i < thing.size(); i++){
        cout << thing[i] << " ";
    }
    cout << endl;
}



template <class T>
vector<T> bubbleSort(const vector<T> &orig){
    vector<T> ret(orig); 
    if(ret.size() <= 1) return ret;
    for(unsigned pass = 0; pass < ret.size(); pass++){   
      bool did_flip = false;
      for(unsigned i = 0; i < ret.size() - 1 - pass; i++){
          if(ret.at(i) > ret.at(i + 1)){
              // Flip!
              T temp = ret.at(i);
              ret.at(i) = ret.at(i+1);
              ret.at(i+1) = temp;
              did_flip = true;
          }
      }
      if(!did_flip){ // Done if there weren't any changes in this pass!
          return ret;
      }
    }
    return ret;
}


template <class T>
vector<T> quickSort(const vector<T> &orig){
    // Fill me in
    return orig;
}


vector<unsigned> countingSort(const vector<unsigned> &orig){
    // Fill me in
    return orig;
}

template <class T>
vector<T> myFastSort(const vector<T> &orig){
    // Fill me in
    return orig;
}



#endif