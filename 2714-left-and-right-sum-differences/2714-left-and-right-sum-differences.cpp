class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(); 
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);

        for(int i = 0; i<n; i++)
        {
            if(i<n-1) leftsum[i+1] = leftsum[i] + nums[i]; 
            int j = n-i-1;
            if(j>0) rightsum[j-1] = rightsum[j] + nums[j];
        }

        for(int i = 0; i<n; i++){
            ans.push_back(abs(rightsum[i] - leftsum[i]));
        }

        return ans;
    }
};