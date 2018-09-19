/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Rational Class
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

