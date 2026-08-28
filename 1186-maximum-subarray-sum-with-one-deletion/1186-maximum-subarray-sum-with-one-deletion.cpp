class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        int onedelete = arr[0];
        int ans = arr[0];
        int n = arr.size();
        for(int i = 1; i<n; i++){
            int newNodelete = max(arr[i], nodelete+arr[i]);
            int newOnedelete = max(onedelete+arr[i], nodelete);
            nodelete = newNodelete;
            onedelete = newOnedelete;
            ans = max(ans, max(nodelete, onedelete));
        }
        return ans;
    }
};