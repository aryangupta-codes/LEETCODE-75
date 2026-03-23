#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::swap

class Solution {
public:
    bool isVowel(char c) {
        c = (c >= 'A' && c <= 'Z') ? c + 32 : c;
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    std::string reverseVowels(std::string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (!isVowel(s[i])) {
                i++;
                continue;
            }
            if (!isVowel(s[j])) {
                j--;
                continue;
            }

            std::swap(s[i], s[j]);
            i++;
            j--; // Crucial: move the right pointer too!
        }
        return s;
    }
};

// ADD THIS MAIN FUNCTION
int main() {
    Solution sol;
    std::string test = "IceCreAm";
    std::cout << "Result: " << sol.reverseVowels(test) << std::endl;
    return 0;
}