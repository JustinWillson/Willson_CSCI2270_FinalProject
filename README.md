# Willson_CSCI2270_FinalProject
Final project for CSCI2270
This project will be a French vocab practice tool for my French class and I will be working on my own. 
I will be implementing a hash table to store the different words. Using a hash table will make looking
up words faster. I will also take advangtage of the hash algorithm in order to sort words into 
categories(verb, noun, and adjective). The table will be an array of size 300 and the hundreds 
place in the index will indicate the categorey the word fits into while the other two digits will 
come from the hashing algorithm. 

The program will read from a file given as a command line argument and will build a hash table out of the 
words in the file. On close, the program will rewrite the file in order to perserve how well the user knows
the words in the file.
