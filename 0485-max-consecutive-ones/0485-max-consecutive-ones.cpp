class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt = 0;
        int maxcnt = 0;
        for(auto it : nums) {
            if(it == 1) {
                cnt++;
            }

            else if(it == 0){
                maxcnt = max(maxcnt, cnt);
                cnt = 0;
            }
            }
        maxcnt = max(maxcnt, cnt);
        return maxcnt;
        }
    
};