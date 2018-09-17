/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the Rational Class
*/
#include "gtest/gtest.h"
#include "VList.h"


TEST(size, 0){
  VList a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size, 1){
  VList a;
  a.push_back(5);
  EXPECT_EQ(a.size(), 1);
}

