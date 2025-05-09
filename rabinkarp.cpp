#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

const int PRIME = 101; // Prime number for hashing

// Function to calculate hash value
long long calculateHash(const string &str, int len) {
    long long hash = 0;
    for (int i = 0; i < len; i++) {
        hash = hash * PRIME + str[i];
    }
    return hash;
}

// Function to check for banned words using Rabin-Karp
string censorText(const string &text, const unordered_set<string> &bannedWords) {
    string censoredText = text;
    
    for (const string &word : bannedWords) {
        int wordLen = word.size();
        long long wordHash = calculateHash(word, wordLen);
        long long textHash = calculateHash(text, wordLen);
        long long power = 1;

        for (int i = 0; i < wordLen - 1; i++) {
            power *= PRIME;
        }

        // Sliding window to check hashes
        for (int i = 0; i <= (int)text.size() - wordLen; i++) {
            if (textHash == wordHash && text.substr(i, wordLen) == word) {
                censoredText.replace(i, wordLen, string(wordLen, '*')); // Replace with *
            }

            // Rolling hash update
            if (i < (int)text.size() - wordLen) {
                textHash = (textHash - text[i] * power) * PRIME + text[i + wordLen];
            }
        }
    }

    return censoredText;
}

int main() {
    string filename = "banned_words.txt";
    unordered_set<string> bannedWords = {"badword", "hate", "spam"}; // For testing

    string userInput;
    cout << "Enter text: ";
    getline(cin, userInput);

    string filteredText = censorText(userInput, bannedWords);
    cout << "Filtered Text: " << filteredText << endl;

    return 0;
}
