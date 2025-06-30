// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. Return the output in any order.

 

// Example 1:

// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: s = "3z4"
// Output: ["3z4","3Z4"]
 

// Constraints:

// 1 <= s.length <= 12
// s consists of lowercase English letters, uppercase English letters, and digits.
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

void backtrack(string& s, int index, vector<string>& result) {
    if (index == s.length()) {
        result.push_back(s);
        return;
    }

    backtrack(s, index + 1, result);

    if (isalpha(s[index])) {
        char original = s[index];

        // Toggle case using toupper/tolower
        if (islower(s[index]))
            s[index] = toupper(s[index]);
        else
            s[index] = tolower(s[index]);

        backtrack(s, index + 1, result);

        // Backtrack to original character
        s[index] = original;
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> result;
    backtrack(s, 0, result);
    return result;
}
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<string> result = letterCasePermutation(s);

    cout << "Letter case permutations:\n";
    for (const string& perm : result) {
        cout << perm << endl;
    }

    return 0;
}
