#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> rabinKarp(string text, string pattern)
{
    int prime = 101, d = 256;
    int m = pattern.length();
    int n = text.length();
    int patternHash = 0, textHash = 0, h = 1;
    vector<int> results;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (patternHash == textHash)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                results.push_back(i);
        }

        if (i < n - m)
        {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % prime;
            if (textHash < 0)
                textHash += prime;
        }
    }

    for (int i = 0; i < results.size(); i++)
        cout << results[i] << " ";

    return results;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: output.exe <text> <pattern>" << endl;
        return 1;
    }

    string text = argv[1];
    string pattern = argv[2];

    rabinKarp(text, pattern);
    return 0;
}
