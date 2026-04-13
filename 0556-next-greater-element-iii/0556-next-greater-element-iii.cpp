#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        
        // finding next_permutation of the number which gives just next greater element
        if (!next_permutation(s.begin(), s.end())) {
            return -1;
        }
        
        // converting to long long and checking if its greater than INT_MAX
        long long ans = stoll(s);
        
        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};
