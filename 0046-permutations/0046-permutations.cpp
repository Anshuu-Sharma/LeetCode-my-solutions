class Solution {
public:
    int fact(int i){
        if (i <= 1) return 1;
        else return i*fact(i-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = fact(nums.size());
        vector<vector<int>> ans;
        vector<int> dummy = nums;
        for(int i = 0; i<n; i++){
        vector<int> temp = dummy;
        next_permutation(temp.begin(), temp.end());
            ans.push_back(temp);
            dummy = temp;
        }

        return ans;
    }
};