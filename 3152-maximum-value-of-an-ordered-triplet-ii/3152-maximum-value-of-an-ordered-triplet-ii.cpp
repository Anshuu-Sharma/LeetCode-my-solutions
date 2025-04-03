class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = nums[0];
        for(int i = 1; i<n-2; i++){
            leftMax[i] = max(leftMax[i-1], nums[i]);
        }

        rightMax[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        long long maxi = INT_MIN;
        for(int i = 1; i<n-1; i++){
            long long l = leftMax[i-1];
            long long r = rightMax[i+1];

            long long curr = (l-nums[i]) * r;
            maxi = max(maxi, curr);
        }

        return maxi >= 0 ? maxi : 0 ;
    }
};