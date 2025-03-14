#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Word 1: " << word1 ", Word 2: " << word2 << " - " << msg << endl;
}

void load_words(set<string> & world_list, const string& file_name) {
    ifstream inFile(file_name);
    if (!inFile) {throw runtime_error("Can't open input file");}
    for (string word; inFile >> word;) {world_list.insert(word);}
}

