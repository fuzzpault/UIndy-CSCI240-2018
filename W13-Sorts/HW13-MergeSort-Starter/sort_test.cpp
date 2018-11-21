/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"
#include <sys/time.h>

#include <vector>
#include <string>
#include <algorithm> // for next_permutation
#include "sort.h"


double getTimeAsDoubleSeconds(){
  struct timeval now;
  gettimeofday(&now, NULL);
  return (double)now.tv_sec + (double)now.tv_usec / 1000000.0;
}

template <class T>
bool isSorted(const vector<T> &thing){
  if(thing.size() == 0 || thing.size() == 1)return true;
  for(unsigned i = 0; i < thing.size() - 1; i++){
    if( thing[i] > thing[i+1])return false;
  }
  return true;
}

// Heap Sort

TEST(string, empty){
  vector<string> a;
  vector<string> b = heapSort(a);
  EXPECT_TRUE(isSorted(b));
}
 
// Fill more in here if you want!