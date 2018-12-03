/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Min Heap
*/
#include "gtest/gtest.h"

#include "HashTable.h"



/*  // Code to remind you what unit tests look like.
TEST(size, 0){
  LIST a;
  EXPECT_EQ(a.size(), 0);
}
*/

TEST(size, 0){
  HashTable a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size, 1){
  HashTable a;
  a.insert("bob");
  EXPECT_EQ(a.size(), 1);
}

TEST(size, 2){
  HashTable a;
  a.insert("bob");
  a.insert("bill");
  EXPECT_EQ(a.size(), 2);
}

TEST(size, 2dup){
  HashTable a;
  a.insert("bob");
  a.insert("bill");
  a.insert("bob");
  EXPECT_EQ(a.size(), 2);
}

TEST(contains, 1there){
  HashTable a;
  a.insert("bob");
  EXPECT_EQ(a.contains("bob"), true);
}

TEST(contains, 1not){
  HashTable a;
  a.insert("bob");
  EXPECT_EQ(a.contains("bobs"), false);
}

TEST(contains, mixed1){
  HashTable a;
  a.insert("bob");
  a.insert("donuts");
  EXPECT_EQ(a.contains("bob"), true);
  EXPECT_EQ(a.contains("donuts"), true);
  EXPECT_EQ(a.contains("bill"), false);
}



