class Solution {
public:
    bool helper(vector<int>& arr, int ind, vector<int>& vis) {
        
        if(ind < 0 || ind >= arr.size()) return false;

        if(arr[ind] == 0) return true;

        if(vis[ind]) return false;

        vis[ind] = 1;

        return helper(arr, ind - arr[ind], vis) ||
               helper(arr, ind + arr[ind], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(), 0);

        return helper(arr, start, vis);
    }
};