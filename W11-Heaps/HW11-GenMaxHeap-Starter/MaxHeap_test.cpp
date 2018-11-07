/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"
#include <sys/time.h>

#include "MaxHeap.h"

// Example tests

TEST(size, string1){
  MaxHeap<string> a;
  a.push("hi");
  EXPECT_EQ(a.size(), 1);
}

TEST(top, unsigned1){
  MaxHeap<unsigned> a;
  a.push(5);
  a.push(30);
  a.push(28);
  EXPECT_EQ( a.top(), 30);
}

TEST(pop, char1){
  MaxHeap<char> a;
  a.push('g');
  a.push('q');
  a.push('z');
  EXPECT_EQ( a.top(), 'z');
  a.pop();
  EXPECT_EQ( a.top(), 'q');
}

// This next test is for the extra credit where an arbitrary type can be used,
// Which requires a custom less than and == operator.
/*
// A struct to contain a first and last name.
struct Name_t{
  string first;
  string last;
};

// Is name a less than b?  Check last names first.
bool lessThan(Name_t a, Name_t b){
  if(a.last < b.last)return true;
  if(a.last > b.last)return false;
  if(a.first < b.first)return true;
  return false;
}
// Required so gtest can verify two Name_ts are the same.
bool operator==(const Name_t a, const Name_t b){
  return a.first == b.first && a.last == b.last;
}

TEST(pop, names){
  MaxHeap<Name_t> a(lessThan);
  Name_t greg = {"Greg", "Lawson"};
  Name_t bob  = {"Bob", "Lawson"};
  Name_t alice = {"Alice", "Peterson"};
  a.push( greg );
  a.push( bob  );
  a.push( alice );
  EXPECT_EQ( a.top(), alice);
  a.pop();
  EXPECT_EQ( a.top(), greg);
}

*/

// Fill me in.






