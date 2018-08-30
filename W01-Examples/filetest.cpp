/*
    Name:
    Data:
    Description:
*/

#include <iostream> // gives us cout
#include <fstream>  // allows us to read/write a file
#include <string>   // allows us to use C++ strings
#include <vector>   // allows us to use the vector STL (standard template library)

using namespace std;

int main(){
    cout << "Stuff" << endl;
    
    ifstream inFile;
    string word;
    int word_count = 0;

    inFile.open("dictionary.txt");
    while(inFile){
        getline(inFile, word);
        //cout << word << endl;
        word_count++;
    }
    
    cout << "There were " << word_count << " words" << endl;
    
    inFile.close();
    return 0;
}
