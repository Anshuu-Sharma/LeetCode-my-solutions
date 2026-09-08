// class Solution {
// public:
//     int fact(int i){
//         if (i <= 1) return 1;
//         else return i*fact(i-1);
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = fact(nums.size());

//         vector<vector<int>> ans;

//         vector<int> temp = nums;
//         for(int i = 0; i<n; i++){
//             next_permutation(temp.begin(), temp.end());
//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };
class Solution {
public:
    void perms(int i,vector<vector<int>>& res,vector<int>& nums){
        if(i==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            perms(i+1,res,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        perms(0,res,nums);
        return res ;
    }
};