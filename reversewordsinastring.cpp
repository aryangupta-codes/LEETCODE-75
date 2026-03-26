#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseRange(string &s, int i, int j) {
        while (i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }

    string reverseWords(string s) {
        int n = s.length();
        int w = 0;
        int r = 0;

        while (r < n) {
            while (r < n && s[r] == ' ') r++;
            if (r < n && w > 0) s[w++] = ' ';
            while (r < n && s[r] != ' ') {
                s[w++] = s[r++];
            }
        }
        
        s.erase(s.begin() + w, s.end());
        int len = s.length();

        reverseRange(s, 0, len - 1);

        int start = 0;
        for (int end = 0; end <= len; end++) {
            if (end == len || s[end] == ' ') {
                reverseRange(s, start, end - 1);
                start = end + 1;
            }
        }

        return s;
    }
};

// This main function is what was missing!
int main() {
    Solution sol;
    
    string test1 = "the sky is blue";
    cout << "Input: \"" << test1 << "\" -> Output: \"" << sol.reverseWords(test1) << "\"" << endl;

    string test2 = "  hello world  ";
    cout << "Input: \"" << test2 << "\" -> Output: \"" << sol.reverseWords(test2) << "\"" << endl;

    string test3 = "a good   example";
    cout << "Input: \"" << test3 << "\" -> Output: \"" << sol.reverseWords(test3) << "\"" << endl;

    return 0;
}