#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool compareWordLength(const string& word1, const string& word2) {
    if (word1.size() == word2.size()) {
        return word1 < word2;
    } else {
        return word1.size() < word2.size();
    }
}

bool isCompoundWord(const string& word, const unordered_set<string>& wordSet, vector<bool>& validPrefix) {
    int wordSize = word.size();

    for (int i = 0; i < wordSize; ++i) {
        string currentPrefix = word.substr(0, i + 1);

        if (wordSet.count(currentPrefix) && (i == wordSize - 1 || validPrefix[i])) {
            validPrefix[wordSize - 1] = true;
            return true;
        }
    }

    return false;
}

void findLongestCompoundWords(const vector<string>& inputWords) {
    vector<string> words = inputWords;
    sort(words.begin(), words.end(), compareWordLength);

    unordered_set<string> wordSet(words.begin(), words.end());

    string longestCompoundWord, secondLongestCompoundWord;

    for (int i = words.size() - 1; i >= 0; --i) {
        const string& currentWord = words[i];

        vector<bool> validPrefix(currentWord.size(), false);

        if (isCompoundWord(currentWord, wordSet, validPrefix)) {
            if (longestCompoundWord.empty()) {
                longestCompoundWord = currentWord;
            } else if (secondLongestCompoundWord.empty()) {
                secondLongestCompoundWord = currentWord;
            } else {
                break;
            }
        }
    }

    cout << "Longest compound word: " << longestCompoundWord << endl;
    cout << "Second longest compound word: " << secondLongestCompoundWord << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Input handling
    vector<string> inputWords;
    string currentWord;

    while (cin >> currentWord) {
        inputWords.push_back(currentWord);
    }

    // Find and display longest and second longest compound words
    findLongestCompoundWords(inputWords);

    return 0;
}
