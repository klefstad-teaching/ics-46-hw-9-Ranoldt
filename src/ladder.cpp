#include "ladder.h"

void error(string word1, string word2, string msg) {
    cerr << "Word 1: " << word1 << ", Word 2: " << word2 << " - " << msg << endl;
}

void load_words(set<string> & world_list, const string& file_name) {
    ifstream inFile(file_name);
    if (!inFile) {throw runtime_error("Can't open input file");}
    for (string word; inFile >> word;) {world_list.insert(word);}
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int str1_len = str1.length(); int str2_len = str2.length();
    if (abs(str1_len - str2_len) > d) return false;

    int diff = 0; int i = 0; int j = 0;
    while (i < str1_len && j < str2_len) {
        if (str1[i] != str2[j]) {
            ++diff;
            if (diff > d) return false;

            if (str1_len > str2_len) {++i;}
            else if (str1_len < str2_len) {++j;}
            else {++i; ++j;}
        } else {++i; ++j;}
    }
    return diff <= d;
}


vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> lq;
    lq.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!lq.empty()) {
        vector<string> ladder = lq.front();
        lq.pop();
        string last_word = ladder.back();
        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    lq.push(new_ladder); 
                }
            }
        }
    }
    return vector<string>();
}

void print_word_ladder(const vector<string>& ladder) {
    if (!ladder.empty()) {
        cout << "Word ladder found: ";
        for (string  word: ladder) {
            cout << word << " ";
        }
        cout << endl;
    } else {
        cout << "No word ladder found." << endl;
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");


    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}