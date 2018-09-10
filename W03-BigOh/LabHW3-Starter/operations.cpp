/*
    Example algorithms to analyze.
*/
#include <vector>
#include <cstdlib>

using namespace std;


// Adds vector a and b and put the result in result.
void addVectors(const vector<int> &a, 
               const vector<int> &b,
                     vector<int> &result){
    // Make sure result is long enough
    while(result.size() < min(a.size(), b.size())){
        result.push_back(0);
    }
    // Now do the calculation
    for(unsigned i = 0; i < min(a.size(), b.size()); i++){
        result.at(i) = a.at(i) + b.at(i);
    }                    
}

// Sorts the given vector
void bubbleSort1(vector<int> &a){
    if(a.size() <= 1) return;
    for(unsigned pass = 0; pass < a.size(); pass++){   
      for(unsigned i = 0; i < a.size() - 1; i++){
          if(a.at(i) > a.at(i + 1)){
              // Flip!
              int temp = a.at(i);
              a.at(i) = a.at(i+1);
              a.at(i+1) = temp;
          }
      }   
    }
}

// Sorts the given vector
void bubbleSort2(vector<int> &a){
    if(a.size() <= 1) return;
    for(unsigned pass = 0; pass < a.size(); pass++){   
      for(unsigned i = 0; i < a.size() - 1 - pass; i++){
          if(a.at(i) > a.at(i + 1)){
              // Flip!
              int temp = a.at(i);
              a.at(i) = a.at(i+1);
              a.at(i+1) = temp;
          }
      }   
    }
}

// Sorts the given vector
void bubbleSort3(vector<int> &a){
    if(a.size() <= 1) return;
    for(unsigned pass = 0; pass < a.size(); pass++){   
      bool did_flip = false;
      for(unsigned i = 0; i < a.size() - 1 - pass; i++){
          if(a.at(i) > a.at(i + 1)){
              // Flip!
              int temp = a.at(i);
              a.at(i) = a.at(i+1);
              a.at(i+1) = temp;
              did_flip = true;
          }
      }
      if(!did_flip){ // Done if there weren't any changes in this pass!
          return;
      }
    }
}

// Returns true if there aren't any repeated values in the vector
bool noDups(const vector<int> &a){
    for(unsigned i = 0; i < a.size() - 1; i++){
        int value = a[i];
        // see if value is in the rest of the vector
        for(unsigned j = i + 1; j < a.size(); j++){
            if(a[j] == value){
                return false;
            }
        }
    }
    return true;
}

long long fib(int n){
    if( n <= 1) return 1;
    return fib(n - 1) + fib(n - 2);
}