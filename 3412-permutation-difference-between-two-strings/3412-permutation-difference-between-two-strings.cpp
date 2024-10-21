class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            int a = i;
            int b = t.find(s[i]);
            ans += abs(a - b);
        }
        return ans;
    }
};