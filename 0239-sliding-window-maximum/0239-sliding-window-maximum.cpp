class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotonic increasing deque 
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }

            if(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            dq.push_back(i);
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }

        return ans;


    }
};