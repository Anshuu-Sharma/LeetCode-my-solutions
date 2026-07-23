class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxel=*max_element(nums.begin(),nums.end());
        vector<int> max_index;
        // storing all indices of maxel 
        for(int i=0;i<n;i++) if(nums[i]==maxel) max_index.push_back(i);
        //check  if there are atleast total k maxel
        if(max_index.size()<k) return 0;
        // Adding n for last subarray case
        max_index.push_back(n);
        // Using low high to selact subarray of k size
        int low=0,high=k-1;
        long long countmax=0;
        while(high<max_index.size()-1){
            countmax+=1LL*(max_index[low]+1)*(max_index[high+1]- max_index[high]);
            low++;
            high++;
        }
        return countmax;
    }
};