#include <iostream>
#include <cstring>
using namespace std;

#define NO_OF_CHARS 256

// Function to build the bad character table
void badCharHeuristic(string pattern, int size, int badChar[NO_OF_CHARS]) {
    
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (int i = 0; i < size; i++)
        badChar[(int)pattern[i]] = i;
}

// Boyer Moore Search Function
void boyerMooreSearch(string text, string pattern) {

    int m = pattern.size();
    int n = text.size();

    int badChar[NO_OF_CHARS];

    badCharHeuristic(pattern, m, badChar);

    int shift = 0;  // shift of the pattern with respect to text

    while (shift <= (n - m)) {

        int j = m - 1;

        // Keep reducing index j while characters match
        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        // If pattern is present
        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;

            shift += (shift + m < n) ? 
                     m - badChar[text[shift + m]] : 1;
        }
        else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }
}

// Driver Code
int main() {
    
    string text = "ABAAABCD";
    string pattern = "ABC";

    boyerMooreSearch(text, pattern);

    return 0;
}