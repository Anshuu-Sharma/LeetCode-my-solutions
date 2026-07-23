class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        /*
        sum/k >= threshold
        as k is always fixed, so we just need to find: sum >= threshold*k
        */

        int targetSum = threshold*k;
        int ans = 0;
        int left = 0;
        int right = k-1;
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        int n = arr.size();
        if(k>n) return ans;
        while(right<n){
            if(sum >= targetSum) ans++;
            if(right+1<n) {
                sum -= arr[left];
                left++;
                right++;
                sum += arr[right];
            }
            else break;
        }
        return ans;
    }
};