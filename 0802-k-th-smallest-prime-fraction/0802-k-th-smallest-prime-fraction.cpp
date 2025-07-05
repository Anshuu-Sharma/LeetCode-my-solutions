class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double , pair<int, int>>> pq;
        int n = arr.size();

        for(int i = 0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                double frac = (double)arr[i] / arr[j];
                pq.push({-1*(frac), {i,j}});
            }
        }
        // k--;
        while(--k) pq.pop();

        int i = arr[pq.top().second.first];
        int j = arr[pq.top().second.second];

        return {i, j};

    }
};