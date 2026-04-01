#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int first = INT_MAX;
        int second = INT_MAX;

        for (int n : nums) {
            if (n <= first) {
                first = n;
            } else if (n <= second) {
                second = n;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> input = {2, 1, 5, 0, 4, 6};
    
    if (sol.increasingTriplet(input)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}