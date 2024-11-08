class Solution {
private: 
    vector<vector<int>> ans;
public:
    void dp_helper(vector<int>& candidates, int target,int ind, vector<int> arr){
        if(ind < 0) return;
        if(target == 0) {
            ans.push_back(arr);
            return;
        }


        dp_helper(candidates, target, ind - 1, arr);
        if(target >= candidates[ind]) {
            arr.push_back(candidates[ind]);
            dp_helper(candidates, target - candidates[ind], ind, arr);
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dp_helper(candidates, target, candidates.size()-1, {});
        return ans;
    }
};