/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the List interface
*/
#include "gtest/gtest.h"
#include "VList.h"

#define LIST VList


TEST(size, 0){
  LIST a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size, 1){
  LIST a;
  a.push_back(5);
  EXPECT_EQ(a.size(), 1);
}

TEST(size, 10){
  LIST a;
  for(int i = 0; i < 10; i++){
    a.push_back(5 * i);
  }
  EXPECT_EQ(a.size(), 10);
}

TEST(at, 1){
  LIST a;
  a.push_back(5);
  EXPECT_EQ(a.at(0), 5);
}

TEST(at, neg1){
  LIST a;
  a.push_back(5);
  EXPECT_EQ(a.at(-1), 5);
}

TEST(at, 2){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
}

TEST(at, neg1double){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  EXPECT_EQ(a.at(-1), 6);
}

TEST(at, change){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.at(1) = 60;
  EXPECT_EQ(a.at(1), 60);
}

TEST(at, push_front1){
  LIST a;
  a.push_front(5);
  EXPECT_EQ(a.at(0), 5);
}

TEST(at, offarray){
  LIST a;
  EXPECT_ANY_THROW( a.at(0) );
}

TEST(at, offarray2){
  LIST a;
  a.push_back(5);
  EXPECT_ANY_THROW( a.at(1) );
  EXPECT_ANY_THROW( a.at(-3) );
}

TEST(at, push_front2){
  LIST a;
  a.push_front(5);
  a.push_front(6);
  EXPECT_EQ(a.at(0), 6);
  EXPECT_EQ(a.at(1), 5);
}

TEST(at, push_front3){
  LIST a;
  a.push_front(5);
  a.push_front(6);
  a.push_front(7);
  EXPECT_EQ(a.at(0), 7);
  EXPECT_EQ(a.at(1), 6);
  EXPECT_EQ(a.at(2), 5);
  EXPECT_EQ(a.size(), 3);
}

TEST(at, count0){
  LIST a;
  a.push_front(5);
  a.push_front(6);
  a.push_front(7);
  EXPECT_EQ(a.count(0), 0);
}

TEST(at, count1){
  LIST a;
  a.push_front(5);
  a.push_front(6);
  a.push_front(7);
  EXPECT_EQ(a.count(5), 1);
}

TEST(at, count2){
  LIST a;
  a.push_front(5);
  a.push_front(5);
  a.push_front(7);
  EXPECT_EQ(a.count(5), 2);
}

TEST(at, count3){
  LIST a;
  a.push_front(5);
  a.push_front(5);
  a.push_front(5);
  EXPECT_EQ(a.count(5), 3);
}

TEST(at, count4){
  LIST a;
  a.push_front(4);
  a.push_front(4);
  a.push_front(5);
  EXPECT_EQ(a.count(5), 1);
}

TEST(at, location1){
  LIST a;
  a.push_front(5);
  a.push_front(4);
  a.push_front(3);
  EXPECT_EQ(a.location(3), 0);
  EXPECT_EQ(a.location(4), 1);
  EXPECT_EQ(a.location(5), 2);
}

TEST(at, location2){
  LIST a;
  EXPECT_ANY_THROW(a.location(3));
}

TEST(at, location3){
  LIST a;
  a.push_back(5);
  EXPECT_ANY_THROW(a.location(3));
}

TEST(string, empty){
  LIST a;
  EXPECT_EQ(a.getAsString(), "[]");
}

TEST(string, single){
  LIST a;
  a.push_back(5);
  EXPECT_EQ(a.getAsString(), "[5]");
}

TEST(string, two){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  EXPECT_EQ(a.getAsString(), "[5,6]");
}

TEST(string, three){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.push_back(-6);
  EXPECT_EQ(a.getAsString(), "[5,6,-6]");
}

//  Tests for HW: remove, copy constructor, assignment operator
//  and destructor will be covered in all tests (valgrind ./test_executable)

TEST(remove, empty){
  LIST a;
  EXPECT_ANY_THROW(a.remove(3));
}

TEST(remove, one){
  LIST a;
  a.push_back(5);
  a.remove(0);
  EXPECT_EQ(a.size(), 0);
}

TEST(remove, neg){
  LIST a;
  a.push_back(5);
  a.remove(-1);
  EXPECT_EQ(a.size(), 0);
}

TEST(remove, bad){
  LIST a;
  a.push_back(5);
  EXPECT_ANY_THROW(a.remove(1));
  EXPECT_ANY_THROW(a.remove(-2));
}

TEST(remove, lastone){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.remove(-1);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(a.at(0), 5);
}

TEST(remove, lasttwo){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.remove(1);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(a.at(0), 5);
}

TEST(remove, first){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.remove(0);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(a.at(0), 6);
}

TEST(remove, firstmany){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(8);
  a.remove(0);
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(a.at(0), 6);
  EXPECT_EQ(a.at(1), 7);
  EXPECT_EQ(a.at(2), 8);
}

TEST(remove, lastmany){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(8);
  a.remove(3);
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
  EXPECT_EQ(a.at(2), 7);
}

TEST(remove, middleone){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(8);
  a.remove(1);
  EXPECT_EQ(a.size(), 3);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 7);
  EXPECT_EQ(a.at(2), 8);
}

TEST(copy, size){
  LIST a;
  a.push_back(5);
  LIST b(a);
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(b.size(), 1);
}

TEST(copy, values){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  LIST b(a);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
  EXPECT_EQ(b.at(0), 5);
  EXPECT_EQ(b.at(1), 6);
}

TEST(copy, deep_copy){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  LIST b(a);
  b.push_back(7);
  b.push_back(8);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
  EXPECT_EQ(b.at(0), 5);
  EXPECT_EQ(b.at(1), 6);
  EXPECT_EQ(b.at(2), 7);
  EXPECT_EQ(b.at(3), 8);
  EXPECT_EQ(a.size(), 2);
  EXPECT_EQ(b.size(), 4);
}

TEST(assignment, one){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  LIST b;
  b.push_back(1);
  EXPECT_EQ(a.size(), 2);
  EXPECT_EQ(b.size(), 1);
  b = a;
  EXPECT_EQ(a.size(), 2);
  EXPECT_EQ(b.size(), 2);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
  EXPECT_EQ(b.at(0), 5);
  EXPECT_EQ(b.at(1), 6);
}

TEST(assignment, selfassign){
  LIST a;
  a.push_back(5);
  a.push_back(6);
  a = a; // a shouldn't change
  EXPECT_EQ(a.size(), 2);
  EXPECT_EQ(a.at(0), 5);
  EXPECT_EQ(a.at(1), 6);
}

