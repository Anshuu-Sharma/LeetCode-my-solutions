class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;

        for(auto it:points) {
            int sum = it[0] * it[0] + it[1] * it[1];

            pq.push({sum, it});
        }
        vector<vector<int>> ans;
        for(int i = 0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};