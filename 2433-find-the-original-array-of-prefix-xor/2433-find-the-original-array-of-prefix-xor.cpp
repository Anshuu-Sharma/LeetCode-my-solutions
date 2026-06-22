class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        // Initialize the answer array with the same size as pref
        vector<int> ans(n); 
        
        // The first element is always the same
        ans[0] = pref[0];
        
        // Traverse the array starting from the second element
        for (int i = 1; i < n; i++) {
            ans[i] = pref[i] ^ pref[i - 1];
        }
        
        return ans;
    }
};
