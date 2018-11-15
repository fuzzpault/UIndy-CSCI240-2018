/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"
#include <sys/time.h>

#include <vector>
#include <string>
#include "sort.h"


// To make your tests easier, I suggest writing a  function to return 
// true if the given vector is sorted.
bool isSorted(const vector<string> &thing){
  return false;
}

// Example tests

TEST(string, empty){
  vector<string> a;
  vector<string> b = heapSort(a);
  EXPECT_TRUE(isSorted(b));
}

TEST(string, 1){
  vector<string> a;
  a.push_back("bob");
  vector<string> b = heapSort(a);
  EXPECT_TRUE(isSorted(b));
}

// Insert more tests here
