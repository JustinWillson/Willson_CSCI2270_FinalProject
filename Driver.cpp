#include <iostream>
#include "WordTable.h"
using namespace std;
void showMenu();

int main(int argc, char* argv[]){
    WordTable* myTable = new WordTable;
    myTable->addFromFile(argv[1]);
    cout << "added words" << endl;
    string userInput = "0";
    
    while( userInput != "6" ){
        showMenu();
        cin >> userInput;
        if (userInput == "1"){
            myTable->printTable();
        } else if (userInput == "2") {
            string word;
            cout << "Please input a word in french" << endl;
            cin.ignore();
            getline(cin, word);
            
            myTable->englishFromFrench(word);
        } else if (userInput == "3") {
            myTable->practiceNouns();
        } else if (userInput == "4") {
            myTable->practiceNouns();
        } else if (userInput == "5") {
            myTable->practiceNouns();
        } else if (userInput == "6"){
            cout << "Goodbye!" << endl;
        } else {
            cout << "INVALID INPUT" << endl;
        }
    }
    
}

void showMenu(){
    cout << "=====Main Menu=====" << endl;
    cout << "1. Print Table" << endl;
    cout << "2. Lookup word" << endl;
    cout << "3. Practice Nouns" << endl;
    cout << "4. Practice Verbs" << endl;
    cout << "5. Practice Adjectives" << endl;
    cout << "6. Quit" << endl;
}
