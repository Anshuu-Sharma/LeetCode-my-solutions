class Solution {
public:

    vector<int> adder(vector<int> arr){
        vector<int> temp;
        for(int i = 0; i<arr.size()-1; i++){
            temp.push_back((arr[i] + arr[i+1]) % 10);
        }
        return temp;
    }
    int triangularSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (nums.size() == 1) return nums[0];

        vector<int> temp = adder(nums);

        while (temp.size() > 1) {
            temp = adder(temp);
        }
        return temp[0];

    }
};