#include "WordTable.h" 
 
 //We initialize the table to hold all blank words
 //We also hold the location of the original blank word to avoid memory leaks
 WordTable::WordTable(){
     blankWord = new word;
     blankWord.french = "";
     blankWord.english = "";
     blankWord.type = "";
 }
 
//Here we delete all the elements in the table as well as the
//blank word we created when we initalized the class
WordTable::~WordTable(){
    
    
    delete blankWord;
}


//the next three methods allow the user to practice different types of speech
void WordTable::practiceNouns(){
    
}

void WordTable::practiceVerbs(){
    
}

void WordTable::practiceAdjectives(){
    
}

//Calculates the index to put a word at given the word in french and the type of speech
//TYPE CONVERSIONS
//Noun: 0**
//Verb: 1**
//Adjective: 2**
int WordTable::getIndex(std::string wordFrench, std::string type){
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
void WordTable::addWord(std::string french, std::string english, std::string type){
    word* thisWord = new word;
    word->french = french;
    word->english = english;
    word->type = type;
    
    int index = getIndex(french, type);
    
    if(WordTable[index]->french == ""){
        WordTable[index] = thisWord;
    } else {
        word* current = WordTable[index];
        while(current->next != NULL){
            current = current->next;
        }
        
        current->next = thisWord;
    }
}

//adds a list of words to the table from a file
//the file must be a list of entries int the form:
//french,english,type
void WordTable::addFromFile(std::string filename){
    ifstream file;
    file.open(filename);
    
}

std::string WordTable::englishFromFrench(std::string french){
    
}

//prints all items in the table
//mostly used for debugging
void WordTable::printTable(){
    
}