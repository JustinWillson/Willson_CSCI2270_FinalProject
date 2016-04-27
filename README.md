# Willson_CSCI2270_FinalProject
Final project for CSCI2270

PROJECT SUMMARY:
This project will be a French vocab practice tool for my French class and I will be working on my own. 
I will be implementing a hash table to store the different words. Using a hash table will make looking
up words faster. I will also take advangtage of the hash algorithm in order to sort words into 
categories(verb, noun, and adjective). The table will be an array of size 300 and the hundreds 
place in the index will indicate the categorey the word fits into while the other two digits will 
come from the hashing algorithm. The program will read from a file given as a command line argument
and will build a hash table out of the words in the file.

HOW TO RUN:
To run the program, you first must compile it with g++ using the following commands
    $ g++ -std=c++11 WordTable.cpp -c
    $ g++ -std=c++11 WordTable.o

This will generate an executable titled a.out. Finally to run the program with the example file use the
command:
    $ ./a.out TestFile.txt

Now, you can choose which type of speech to practice, you can look up a word, or you can print out the contents
of the table. The menu functions just like the programs we have made throughout the semester.

DEPENDENCIES:
The only dependency for this program is having g++ installed, however, it is still possible to compile the
program without g++, just not with the commands given.

SYSTEM REQUIREMENTS:
The only system requirement is Linux, however, once again it is still possible to compile on other systems,
just not with the instructions provided.

GROUP MEMBERS:
none

CONTRIBUTORS:
none

OPEN ISSUES:
Hopefully none, but it has not been fully tested
