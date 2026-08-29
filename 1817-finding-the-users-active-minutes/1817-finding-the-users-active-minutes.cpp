class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(logs.begin(), logs.end());
        
        vector<int> ans(k, 0);
        int n = logs.size();
        int i = 0;
        
        while (i < n) {
            int userId = logs[i][0];
            int uam = 0;
            
            // Process all logs for the current user
            while (i < n && logs[i][0] == userId) {
                uam++;
                int currTime = logs[i][1];
                // Skip duplicate active minutes for the same user
                while (i < n && logs[i][0] == userId && logs[i][1] == currTime) {
                    i++;
                }
            }
            
            if (uam <= k) {
                ans[uam - 1]++;
            }
        }
        
        return ans;
    }
};