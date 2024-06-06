class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int sum;
        for(int i = 0; i<(nums.size() - 1); i++){

            for(int j = i+1; j<nums.size(); j++){
                sum = nums[i]+ nums[j];
                if(sum == target) {
                    ans.push_back(i); 
                    ans.push_back(j);
                    }  
            }
        }
    return ans;
    }

};