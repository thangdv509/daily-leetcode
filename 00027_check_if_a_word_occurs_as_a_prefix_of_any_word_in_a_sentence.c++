#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string sentence;
string searchWord;

void init() {
    getline(cin, sentence);
    cin >> searchWord;
}

int isPrefixOfWord(string sentence, string searchWord) {
    istringstream stream(sentence);
    string word;
    int index = 1;
    while (stream >> word) {
        if(word.find(searchWord) == 0) {
            return index;
        }
        index ++;
    }

    return -1;
}


int main() {
    init();
    int res = isPrefixOfWord(sentence, searchWord);
    cout << res << endl;
    return 0;
}

// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
// Daily question: 02/12/2024 - Easy