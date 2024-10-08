class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int alice = 0;
        int bob = 0;
        vector<int> temp;
        for(int i = 0; i<nums.size()-1; i++){
            alice = nums[i];
            bob = nums[i+1];
            i++;
            temp.push_back(bob);
            temp.push_back(alice);
        }
        return temp;
    }
};