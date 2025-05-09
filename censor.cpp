#include <iostream>
#include <fstream>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <cctype>

using namespace std;

const int PRIME = 101;
const int BASE = 256;

// Function to compute Rabin-Karp hash
int computeHash(const string &str, int length) {
    int hash = 0;
    for (int i = 0; i < length; i++) {
        hash = (hash * BASE + str[i]) % PRIME;
    }
    return hash;
}

// Convert string to lowercase
string toLowerCase(const string &str) {
    string lowerStr = str;
    for (char &ch : lowerStr) {
        ch = tolower(ch);
    }
    return lowerStr;
}

// Function to censor banned words using Rabin-Karp
string censorText(const string &inputText, const unordered_set<string> &bannedWords) {
    string censoredText = inputText;  // Original text copy
    string lowerText = toLowerCase(inputText); // Lowercase for matching

    for (const string &banned : bannedWords) {
        string lowerBanned = toLowerCase(banned);
        int wordLength = lowerBanned.length();
        int textLength = lowerText.length();

        if (wordLength > textLength) continue;

        int bannedHash = computeHash(lowerBanned, wordLength);
        int textHash = computeHash(lowerText.substr(0, wordLength), wordLength);
        int basePower = 1;

        for (int i = 1; i < wordLength; i++) {
            basePower = (basePower * BASE) % PRIME;
        }

        for (int i = 0; i <= textLength - wordLength; i++) {
            if (textHash == bannedHash && lowerText.substr(i, wordLength) == lowerBanned) {
                for (int j = i; j < i + wordLength; j++) {
                    censoredText[j] = '*';
                }
            }
            if (i < textLength - wordLength) {
                textHash = (textHash + PRIME - (lowerText[i] * basePower) % PRIME) % PRIME;
                textHash = (textHash * BASE + lowerText[i + wordLength]) % PRIME;
            }
        }
    }
    return censoredText;
}

// Load banned words from file
unordered_set<string> loadBannedWords(const string &filename) {
    unordered_set<string> bannedWords;
    ifstream file(filename);
    string word;

    if (!file) {
        cerr << "Error: Cannot open " << filename << endl;
        return bannedWords;
    }

    while (file >> word) {
        bannedWords.insert(word);
    }

    file.close();
    return bannedWords;
}

int main() {
    unordered_set<string> bannedWords = loadBannedWords("banned_words.txt");

    string userInput;
    getline(cin, userInput); // Read input from Node.js

    string output = censorText(userInput, bannedWords);
    cout << output << endl; // Output censored text to Node.js
    return 0;
}
