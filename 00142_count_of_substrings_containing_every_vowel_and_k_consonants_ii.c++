#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
using namespace std;

string word;
int k;

void init() {
    cin >> word >> k;
}

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long atLeastK(string& word, int k) {
    int n = word.size();
    long long ans = 0;
    int consonants = 0;
    int left = 0;
    unordered_map<char, int> vowel_map;

    for (int right = 0; right < n; right++) {
        if (isVowel(word[right])) {
            vowel_map[word[right]]++;
        } else {
            consonants++;
        }

        while (vowel_map.size() == 5 && consonants >= k) {
            ans += n - right;
            if (isVowel(word[left])) {
                vowel_map[word[left]]--;
                if (vowel_map[word[left]] == 0) {
                    vowel_map.erase(word[left]);
                }
            } else {
                consonants--;
            }
            left++;
        }
    }
    return ans;
}

long long countOfSubstrings(string word, int k) {
    return atLeastK(word, k) - atLeastK(word, k + 1);
}

int main() {
    init();

    cout << countOfSubstrings(word, k) << endl;

    return 0;
}

// 3306. Count of Substrings Containing Every Vowel and K Consonants II
// Daily question: 10/03/2025 - Medium