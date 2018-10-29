/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the BST classes
*/
#include "gtest/gtest.h"

#include "Trie.h"



/*  // Code to remind you what unit tests look like.
TEST(size, 0){
  LIST a;
  EXPECT_EQ(a.size(), 0);
}
*/

TEST(numNodes, 1){
  Trie a;
  EXPECT_EQ(a.numNodes(), 1);
}

TEST(numNodes, 2){
  Trie a;
  a.insert("a");
  EXPECT_EQ(a.numNodes(), 2);
}

TEST(numNodes, 3){
  Trie a;
  a.insert("ab");
  EXPECT_EQ(a.numNodes(), 3);
}

TEST(numNodes, 4){
  Trie a;
  a.insert("ab");
  a.insert("ac");
  EXPECT_EQ(a.numNodes(), 4);
}

TEST(size, 0){
  Trie a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size, 1){
  Trie a;
  a.insert("bill");
  EXPECT_EQ(a.size(), 1);
}

TEST(size, 1dup){
  Trie a;
  a.insert("bob");
  a.insert("bob");
  EXPECT_EQ(a.size(), 1);
}

TEST(size, 2){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  EXPECT_EQ(a.size(), 2);
}

TEST(size, 4){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  EXPECT_EQ(a.size(), 4);
}

TEST(size, 4wMixedCaps){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("BILL");
  a.insert("mary");
  a.insert("greg");
  a.insert("GreG");
  EXPECT_EQ(a.size(), 4);
}

TEST(insert, valid){
  Trie a;
  EXPECT_EQ(a.insert("zebra"), true);
}

TEST(insert, invalidspace){
  Trie a;
  EXPECT_EQ(a.insert(" "), false);
}

TEST(insert, invalidexclaimation){
  Trie a;
  EXPECT_EQ(a.insert("bob!"), false);
}

TEST(find, there1){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  EXPECT_EQ(a.find("greg"), true);
}

TEST(find, there2){
  Trie a;
  a.insert("bob");
  a.insert("a");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  EXPECT_EQ(a.find("a"), true);
}

TEST(find, notthereToLong){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  EXPECT_EQ(a.find("grege"), false);
}

TEST(find, notthereToShort){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  EXPECT_EQ(a.find("gre"), false);
}

TEST(getAllWords, 0){
  Trie a;
  vector<string> ret = a.getAllWords();
  EXPECT_EQ(ret.size(), 0);
}

TEST(getAllWords, 5resultsize){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  vector<string> ret = a.getAllWords();
  EXPECT_EQ(ret.size(), 4);
}

TEST(getAllWords, 5){
  Trie a;
  a.insert("a");
  a.insert("apple");
  a.insert("arc");
  a.insert("blob");
  vector<string> ret = a.getAllWords();
  unsigned matches = 0;
  for(unsigned i = 0; i < ret.size(); i++){
      string word = ret[i];
      if(word == "a")matches++;
      if(word == "apple")matches++;
      if(word == "arc")matches++;
      if(word == "blob")matches++;
  }
  EXPECT_EQ(matches, 4);
}

TEST(copyconstructor, 1){
  Trie a;
  a.insert("a");
  a.insert("apple");
  a.insert("arc");
  a.insert("blob");
  Trie b(a);
  a.insert("blobs");
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(b.size(), 4);
  EXPECT_EQ(a.find("blobs"), true);
  EXPECT_EQ(b.find("blobs"), false);
  EXPECT_EQ(b.find("a"), true);
}


TEST(assignment, 1){
  Trie a;
  a.insert("a");
  a.insert("apple");
  a.insert("arc");
  a.insert("blob");
  Trie b;
  b.insert("zebras");
  b = a;
  a.insert("blobs");
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(b.size(), 4);
  EXPECT_EQ(a.find("blobs"), true);
  EXPECT_EQ(b.find("blobs"), false);
  EXPECT_EQ(b.find("zebras"), false);
  EXPECT_EQ(b.find("arc"), true);
}

TEST(assign, self){
  Trie a;
  a.insert("bob");
  a.insert("bill");
  a.insert("mary");
  a.insert("greg");
  a = a;
  EXPECT_EQ(a.find("greg"), true);
  EXPECT_EQ(a.size(), 4);
}





