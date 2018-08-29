/*
    Name:
    Data:
    Description:
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
