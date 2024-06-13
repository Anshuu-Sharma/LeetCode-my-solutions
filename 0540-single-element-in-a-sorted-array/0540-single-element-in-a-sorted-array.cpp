class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int first = 0;
        int second = 1;
    while(first != nums.size()){
            if(nums.size()<3){
                return nums[first];
            }
            if(nums[first] == nums[second]) {
                first += 2;
                second += 2;
            }
            else{
            return nums[first];
                        }
        }
    return nums[first];
    }
};