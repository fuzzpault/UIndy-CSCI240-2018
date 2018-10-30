/* Name: < Fill me in>
   Date: < Fill me in>
   Desc: Unit tests for the BST classes
*/
#include "gtest/gtest.h"

#include "BST.h"

string cleanString(string input){
    // Remove duplicate strings
    string::size_type pos = 0;
    while((pos = input.find("  ", pos)) != string::npos){
        input.replace(pos, 2, " ");
    }
    // Remove beginning space
    while(input[0] == ' ')input.replace(0,1,"");
    // Remove ending space
    while(input[input.length() - 1] == ' ')input.replace(input.length() - 1,1,"");
    return input;
}

/*  // Code to remind you what unit tests look like.
TEST(size, 0){
  LIST a;
  EXPECT_EQ(a.size(), 0);
}
*/

TEST(size, 0){
  BST a;
  EXPECT_EQ(a.size(), 0);
}

TEST(size, 1){
  BST a;
  a.insert("bob");
  EXPECT_EQ(a.size(), 1);
}

TEST(size, 2left){
  BST a;
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ(a.size(), 2);
}

TEST(size, 2right){
  BST a;
  a.insert("bob");
  a.insert("grace");
  EXPECT_EQ(a.size(), 2);
}

TEST(size, 3){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("grace");
  EXPECT_EQ(a.size(), 3);
}

TEST(find, there){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("grace");
  a.insert("margaret");
  EXPECT_EQ(a.find("bob"), true);
  EXPECT_EQ(a.find("alice"), true);
  EXPECT_EQ(a.find("grace"), true);
  EXPECT_EQ(a.find("margaret"), true);
}

TEST(find, not_there){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("grace");
  a.insert("margaret");
  EXPECT_EQ(a.find("bab"), false);
  EXPECT_EQ(a.find("alicee"), false);
  EXPECT_EQ(a.find("gracie"), false);
  EXPECT_EQ(a.find("margret"), false);
}

TEST(height, empty){
  BST a;
  EXPECT_EQ(a.height(), 0);
}

TEST(height, 1node){
  BST a;
  a.insert("alice");
  EXPECT_EQ(a.height(), 0);
}

TEST(height, 2nodes){
  BST a;
  a.insert("alice");
  a.insert("bob");
  EXPECT_EQ(a.height(), 1);
}

TEST(height, ll1){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("grace");
  a.insert("margaret");
  EXPECT_EQ(a.height(), 3);
}

TEST(height, ll2){
  BST a;
  a.insert("margaret");
  a.insert("grace");
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ(a.height(), 3);
}

TEST(height, balance){
  BST a;
  a.insert("grace");
  a.insert("margaret");
  a.insert("alice");
  a.insert("bob");
  EXPECT_EQ(a.height(), 2);
}

TEST(balance, 0){
  BST a;
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 1node){
  BST a;
  a.insert("alice");
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 2nodes){
  BST a;
  a.insert("alice");
  a.insert("bob");
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 3nodes1){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("greg");
  EXPECT_EQ(a.isBalanced(), false);
}

TEST(balance, 3nodes2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 3nodes3){
  BST a;
  a.insert("greg");
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ(a.isBalanced(), false);
}

TEST(balance, 4nodes1){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("clem");
  a.insert("greg");
  EXPECT_EQ(a.isBalanced(), false);
}

TEST(balance, 4nodes2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  a.insert("greg");
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 4nodes3){
  BST a;
  a.insert("clem");
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  EXPECT_EQ(a.isBalanced(), true);
}

TEST(balance, 4nodes4){
  BST a;
  a.insert("greg");
  a.insert("bob");
  a.insert("clem");
  a.insert("alice");
  EXPECT_EQ(a.isBalanced(), false);
}

TEST(preOrder, 0){
  BST a;
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "");
}

TEST(preOrder, 1){
  BST a;
  a.insert("alice");
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "alice");
}

TEST(preOrder, 2){
  BST a;
  a.insert("alice");
  a.insert("bob");
  //cout << "-" << cleanString( a.preOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "alice bob");
}

TEST(preOrder, 3){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("clem");
  //cout << "-" << cleanString( a.preOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "alice bob clem");
}

TEST(preOrder, 3balanced){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  //cout << "-" << cleanString( a.preOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "bob alice clem");
}

TEST(preOrder, 3balanced2){
  BST a;
  a.insert("clem");
  a.insert("alice");
  a.insert("bob");
  //cout << "-" << cleanString( a.preOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.preOrderTraversal() ), "clem alice bob");
}

TEST(inOrder, 0){
  BST a;
  EXPECT_EQ(cleanString( a.inOrderTraversal() ), "");
}

TEST(inOrder, 3){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("clem");
  //cout << "-" << cleanString( a.inOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.inOrderTraversal() ), "alice bob clem");
}

TEST(inOrder, 3balanced2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  //cout << "-" << cleanString( a.inOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.inOrderTraversal() ), "alice bob clem");
}

TEST(inOrder, 3line){
  BST a;
  a.insert("clem");
  a.insert("bob");
  a.insert("alice");
  //cout << "-" << cleanString( a.inOrderTraversal() )  << "-" << endl;
  EXPECT_EQ(cleanString( a.inOrderTraversal() ), "alice bob clem");
}

TEST(copy, 0){
  BST a;
  BST b(a);
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(a.size(), 0);
}

TEST(copy, 1){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  a.insert("mary");
  BST b(a);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.find("bob"), true);
  EXPECT_EQ(b.find("bob"), true);
  EXPECT_EQ(a.find("alice"), true);
  EXPECT_EQ(b.find("alice"), true);
  EXPECT_EQ(a.find("greg"), true);
  EXPECT_EQ(b.find("greg"), true);
  EXPECT_EQ(a.find("mary"), true);
  EXPECT_EQ(b.find("mary"), true);
  a.insert("peter");
  b.insert("steve");
  EXPECT_EQ(a.find("peter"), true);
  EXPECT_EQ(b.find("peter"), false);
  EXPECT_EQ(a.find("steve"), false);
  EXPECT_EQ(b.find("steve"), true);
}

TEST(copy, 2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  a.insert("mary");
  BST b = a;
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.find("bob"), true);
  EXPECT_EQ(b.find("bob"), true);
  EXPECT_EQ(a.find("alice"), true);
  EXPECT_EQ(b.find("alice"), true);
  EXPECT_EQ(a.find("greg"), true);
  EXPECT_EQ(b.find("greg"), true);
  EXPECT_EQ(a.find("mary"), true);
  EXPECT_EQ(b.find("mary"), true);
  a.insert("peter");
  b.insert("steve");
  EXPECT_EQ(a.find("peter"), true);
  EXPECT_EQ(b.find("peter"), false);
  EXPECT_EQ(a.find("steve"), false);
  EXPECT_EQ(b.find("steve"), true);
}

TEST(assignment, 1){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  a.insert("mary");
  BST b;
  b.insert("jake");
  b.insert("liz");
  EXPECT_EQ(b.size(), 2);
  b = a;
  EXPECT_EQ(a.find("jake"), false);
  EXPECT_EQ(b.find("jake"), false);
  EXPECT_EQ(a.find("liz"), false);
  EXPECT_EQ(a.find("liz"), false);
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(b.size(), 4);
  EXPECT_EQ(a.find("bob"), true);
  EXPECT_EQ(b.find("bob"), true);
  EXPECT_EQ(a.find("alice"), true);
  EXPECT_EQ(b.find("alice"), true);
  EXPECT_EQ(a.find("greg"), true);
  EXPECT_EQ(b.find("greg"), true);
  EXPECT_EQ(a.find("mary"), true);
  EXPECT_EQ(b.find("mary"), true);
  a.insert("peter");
  b.insert("steve");
  EXPECT_EQ(a.find("peter"), true);
  EXPECT_EQ(b.find("peter"), false);
  EXPECT_EQ(a.find("steve"), false);
  EXPECT_EQ(b.find("steve"), true);
}

TEST(assignment, self){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("greg");
  a.insert("mary");
  a = a;
  EXPECT_EQ(a.size(), 4);
  EXPECT_EQ(a.find("bob"), true);
  EXPECT_EQ(a.find("alice"), true);
  EXPECT_EQ(a.find("greg"), true);
  EXPECT_EQ(a.find("mary"), true);
}

TEST(large, 1){
  BST a;
  srand(5);  // Initialize srand to a known number.
  for(int i = 0; i < 10000; i++){
    stringstream s;
    s << rand() % 1000;
    a.insert(s.str());
  }
  EXPECT_EQ(a.size(), 10000);
  srand(5);  // Initialize srand to a known number.
  // now verify those numbers are in there
  for(int i = 0; i < 10000; i++){
    stringstream s;
    s << rand() % 1000;
    EXPECT_EQ(a.find(s.str()), true);
  }
}

// Lab/HW 09 Tests

TEST(getMin, 0){
  BST a;
  EXPECT_ANY_THROW( a.getMin() );
}

TEST(getMin, 1){
  BST a;
  a.insert("alice");
  EXPECT_EQ( a.getMin(), "alice" );
}

TEST(getMin, 2){
  BST a;
  a.insert("bruce");
  a.insert("alice");
  EXPECT_EQ( a.getMin(), "alice" );
}

TEST(getMin, 3){
  BST a;
  a.insert("alice");
  a.insert("bruce");
  EXPECT_EQ( a.getMin(), "alice" );
}

TEST(getMin, 4){
  BST a;
  a.insert("bruce");
  a.insert("emily");
  a.insert("chuck");
  a.insert("alice");
  a.insert("dave");
  EXPECT_EQ( a.getMin(), "alice" );
}

TEST(getMax, 0){
  BST a;
  EXPECT_ANY_THROW( a.getMax() );
}

TEST(getMax, 1){
  BST a;
  a.insert("alice");
  EXPECT_EQ( a.getMax(), "alice" );
}

TEST(getMax, 2){
  BST a;
  a.insert("bruce");
  a.insert("alice");
  EXPECT_EQ( a.getMax(), "bruce" );
}

TEST(getMax, 3){
  BST a;
  a.insert("alice");
  a.insert("bruce");
  EXPECT_EQ( a.getMax(), "bruce" );
}

TEST(getMax, 4){
  BST a;
  a.insert("bruce");
  a.insert("emily");
  a.insert("dave");
  a.insert("chuck");
  a.insert("alice");
  EXPECT_EQ( a.getMax(), "emily" );
}

TEST(remove, 0){
  BST a;
  EXPECT_EQ( a.remove("bob"), false );
}

TEST(remove, 1there){
  BST a;
  a.insert("bob");
  EXPECT_EQ( a.remove("bob"), true );
  EXPECT_EQ( a.size(), 0 );
}

TEST(remove, 1notthere){
  BST a;
  a.insert("bob");
  EXPECT_EQ( a.remove("bill"), false );
  EXPECT_EQ( a.size(), 1 );
}

TEST(remove, 2there1){
  BST a;
  a.insert("alice");
  a.insert("bob");
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.size(), 1 );
}

TEST(remove, 2there2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.size(), 1 );
}

TEST(remove, 2notthere1){
  BST a;
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ( a.remove("greg"), false );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 2notthere2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ( a.remove("greg"), false );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 3there1){
  BST a;
  a.insert("alice");
  a.insert("bob");
  a.insert("clem");
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 3there2){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 3there3){
  BST a;
  a.insert("clem");
  a.insert("bob");
  a.insert("alice");
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 3there4){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.remove("bob"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 3there5){
  BST a;
  a.insert("bob");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.remove("clem"), true );
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.size(), 2 );
}

TEST(remove, 7balanced1){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("dave"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced2){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("bob"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced3){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("frank"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced4){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("ginny"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced5){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("eva"), true );
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced6){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("clem"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7balanced7){
  BST a;
  a.insert("dave"); // root
  a.insert("bob"); // left child
  a.insert("frank"); // right child
  a.insert("ginny"); // now all leaves
  a.insert("eva");
  a.insert("alice");
  a.insert("clem");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("clem"), true );
  EXPECT_EQ( a.find("eva"), true);
  EXPECT_EQ( a.find("dave"), true);
  EXPECT_EQ( a.find("alice"), true);
  EXPECT_EQ( a.find("ginny"), true);
  EXPECT_EQ( a.find("bob"), true);
  EXPECT_EQ( a.find("frank"), true);
  EXPECT_EQ( a.size(), 6 );
}

TEST(remove, 7allinlineleft){
  BST a;
  a.insert("alice");
  a.insert("bob"); 
  a.insert("clem");
  a.insert("dave"); 
  a.insert("eva");
  a.insert("frank"); 
  a.insert("ginny"); 
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.size(), 6 );
  EXPECT_EQ( a.remove("ginny"), true );
  EXPECT_EQ( a.size(), 5 );
  EXPECT_EQ( a.remove("eva"), true );
  EXPECT_EQ( a.size(), 4 );
  EXPECT_EQ( a.remove("dave"), true );
  EXPECT_EQ( a.size(), 3 );
  EXPECT_EQ( a.remove("bob"), true );
  EXPECT_EQ( a.size(), 2 );
  EXPECT_EQ( a.remove("clem"), true );
  EXPECT_EQ( a.size(), 1 );
  EXPECT_EQ( a.remove("frank"), true );
  EXPECT_EQ( a.size(), 0 );
  EXPECT_EQ( a.remove("frank"), false );
  EXPECT_EQ( a.size(), 0 );
}

TEST(remove, 7allinlineright){
  BST a;
  a.insert("ginny");
  a.insert("frank"); 
  a.insert("eva");
  a.insert("dave"); 
  a.insert("clem");
  a.insert("bob"); 
  a.insert("alice");
  EXPECT_EQ( a.size(), 7 );
  EXPECT_EQ( a.remove("alice"), true );
  EXPECT_EQ( a.size(), 6 );
  EXPECT_EQ( a.remove("ginny"), true );
  EXPECT_EQ( a.size(), 5 );
  EXPECT_EQ( a.remove("eva"), true );
  EXPECT_EQ( a.size(), 4 );
  EXPECT_EQ( a.remove("dave"), true );
  EXPECT_EQ( a.size(), 3 );
  EXPECT_EQ( a.remove("bob"), true );
  EXPECT_EQ( a.size(), 2 );
  EXPECT_EQ( a.remove("clem"), true );
  EXPECT_EQ( a.size(), 1 );
  EXPECT_EQ( a.remove("frank"), true );
  EXPECT_EQ( a.size(), 0 );
  EXPECT_EQ( a.remove("frank"), false );
  EXPECT_EQ( a.size(), 0 );
}










