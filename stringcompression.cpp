#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count occurrences of the current character
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character to the array
            chars[write++] = currentChar;

            // If count > 1, convert count to string and write each digit
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};

// Optional: Add a main function to test locally in VS Code
int main() {
    Solution sol;
    vector<char> test = {'a','a','b','b','c','c','c'};
    int newLength = sol.compress(test);
    
    cout << "New Length: " << newLength << endl;
    for(int i = 0; i < newLength; i++) {
        cout << test[i];
    }
    return 0;
}