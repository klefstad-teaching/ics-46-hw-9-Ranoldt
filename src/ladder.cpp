#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Word 1: " << word1 ", Word 2: " << word2 << " - " << msg << endl;
}

void load_words(set<string> & world_list, const string& file_name) {
    ifstream inFile(file_name);
    if (!inFile) {throw runtime_error("Can't open input file");}
    for (string word; inFile >> word;) {world_list.insert(word);}
}

bool is_adjacent(const string& word1, const string& word2) {
    int len = word1.length();
    if (len != word2.length()) {return false;}

    int diff = 0;
    for (int i = 0; i < len; ++i) {
        if (word1[i] != word2[i]) {++diff;}
    }
    return difference == 1;
}