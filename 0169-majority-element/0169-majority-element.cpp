class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int cnt = 0;
        int el;
        for(int i = 0;i<nums.size();i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
    return el;
    }

};