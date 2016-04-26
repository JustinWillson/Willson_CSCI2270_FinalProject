#include "WordTable.h" 
using namespace std;
 
 //We initialize the table to hold all blank words
 //We also hold the location of the original blank word to avoid memory leaks
 WordTable::WordTable(){
     blankWord = new word;
     blankWord->french = "";
     blankWord->english = "";
     blankWord->type = "";
     
     for (int i = 0; i < 300; i++){
         wordTable[i] = blankWord;
     }
 }
 
//Here we delete all the elements in the table as well as the
//blank word we created when we initalized the class
WordTable::~WordTable(){
    for(int i = 0; i < 300; i++){
        if ( wordTable[i]->french != "" ){
            word* temp = wordTable[i];
            while(temp != NULL){
                word* toDelete =  temp;
                temp = temp->next;
                delete toDelete;
            }
        }
    }
    delete blankWord;
}


//the next three methods allow the user to practice different types of speech
void WordTable::practiceNouns(){
    string input;
    int score;
    int count;
    for(int i = 0; i< 100; i++){
        if (wordTable[i]->french != ""){
            word* temp = wordTable[i];
            while(temp != NULL){
                cout << "What is " << temp->french << " in English." << endl;
                getline(cin, input);
                if(input == temp->english){
                    score++;
                }
                count++;
                temp = temp->next;
            }
        } 
    }

    cout<< "On nouns, you got " << score << " correct out of " << count << endl;
}

void WordTable::practiceVerbs(){
    string input;
    int score;
    int count;
    for(int i = 100; i< 200; i++){
        if (wordTable[i]->french != ""){
            word* temp = wordTable[i];
            while(temp != NULL){
                cout << "What is " << temp->french << " in English." << endl;
                getline(cin, input);
                if(input == temp->english){
                    score++;
                }
                count++;
                temp = temp->next;
            }
        } 
    }

    cout<< "On verbs, you got " << score << " correct out of " << count << endl;
    
}

void WordTable::practiceAdjectives(){
    string input;
    int score;
    int count;
    for(int i = 200; i< 300; i++){
        if (wordTable[i]->french != ""){
            word* temp = wordTable[i];
            while(temp != NULL){
                cout << "What is " << temp->french << " in English." << endl;
                getline(cin, input);
                if(input == temp->english){
                    score++;
                }
                count++;
                temp = temp->next;
            }
        } 
    }

    cout<< "On adjectives, you got " << score << " correct out of " << count << endl;
    
}

//Calculates the index to put a word at given the word in french and the type of speech
//TYPE CONVERSIONS
//Noun: 0**
//Verb: 1**
//Adjective: 2**
int WordTable::getIndex(string wordFrench, string type){
    int sum;
    int typeNum;
    
    if(type == "n"){
        typeNum = 0;
    } else if(type == "v"){
        typeNum = 1;
    } else if(type == "adj"){
        typeNum = 2;
    }
    
    for (int i = 0; i<wordFrench.size(); i++){
        sum += wordFrench.at(i);
    }
    
    return sum%100 + 100*typeNum;
}

//adds a single word to the table, used by the addFromFile() method
void WordTable::addWord(string french, string english, string type){
    word* thisWord = new word;
    thisWord->french = french;
    thisWord->english = english;
    thisWord->type = type;
    
    int index = getIndex(french, type);
    cout << "here is stuff at index ." << wordTable[index]->french << "." << wordTable[index]->english << "."  <<endl;
    cout << "build word also here is index: " << index << endl;
    if(wordTable[index]->french == ""){
        cout << "before insert" << endl;
        wordTable[index] = thisWord;
        cout << "got through first if statement" << endl;
    } else {
        cout << "entered other else?? " << endl;
        word* current = wordTable[index];
        while(current->next != NULL){
            current = current->next;
        }
        
        current->next = thisWord;
    }
}

//adds a list of words to the table from a file
//the file must be a list of entries int the form:
//french,english,type
void WordTable::addFromFile(string filename){
    ifstream file;
    file.open (filename);
    string line;
    cout << "opened file in function" << endl;
    while( getline(file, line) ){
        cout << "entered wile loop" << endl;
        string french;
        string english;
        string type;
        
        stringstream ss(line);
        getline(ss, french, ',');
        getline(ss, english, ',');
        getline(ss, type, ',');
        cout << "stringstreamed..." << endl;
        
        addWord(french, english, type);
        cout << "added word to hash table" << endl;
    }  
}

void WordTable::englishFromFrench(string french){
    //while we don't know if the word is a noun or not, we start as a noun
    //so we can increment it by 100 until we find the word
    int index = getIndex(french, "n");
    string english;
    bool found = false;
    
    //we increment index by 100 each pass through the loop until it points to an
    //index not in the hash table
    while(index < 300 && !found){
        word* current = wordTable[index];
        while (current->next != NULL && !found) {
            if(current->french == french){
                found = true;
                english = current->english;
            }
            current = current->next;
        }
        index+=100;
    }
    
    if ( !found ){
        cout << "Word not found, please try again" << endl;
    } else {
        cout << french << " : " << english << endl;
    }
}

//prints all items in the table
//mostly used for debugging
void WordTable::printTable(){
    for(int i = 0; i < 300; i++){
        if (wordTable[i]->french != ""){
            word* temp = wordTable[i];
            while(temp != NULL){
                cout << "French: " << temp->french << " ... English: " << temp->english << endl;
                temp = temp->next;
            }
        }
    }
}
