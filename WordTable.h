#ifndef WORDTABLE_H
#define WORDTABLE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct word{
    std::string french;
    std::string english;
    std::string type;
    word* next = NULL;
};

class WordTable{
    private:
        word* WordTable[300];
        word* blankWord;
    public:
        WordTable();
        ~WordTable();
        void practiceNouns();
        void practiceVerbs();
        void practiceAdjectives();
        int getIndex(std::string wordFrench);
        void addWord(std::string french, std::string english, std::string type);
        void addFromFile(std::string filename);
        void englishFromFrench(std::string french);
        void printTable();
};



#endif