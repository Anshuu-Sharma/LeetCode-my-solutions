class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        // Map user ID -> set of unique active minutes
        unordered_map<int, unordered_set<int>> userMinutes;
        
        for (const auto& log : logs) {
            userMinutes[log[0]].insert(log[1]);
        }
        
        vector<int> ans(k, 0);
        for (const auto& [userId, minutesSet] : userMinutes) {
            int uam = minutesSet.size();
            // 1-indexed UAM maps to 0-indexed ans array
            if (uam <= k) {
                ans[uam - 1]++;
            }
        }
        
        return ans;
    }
};