class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> temp;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = nums1.size()-1;
        int j = nums2.size()-1;
        while(i>=0 && j>=0) {
            if(nums1[i] == nums2[j]) {
               temp.insert(nums1[i]);
               i--;j--;
            }
            else if(nums1[i] > nums2[j])i--;
            else j--;
        }
        
        for(int it : temp) {
            ans.push_back(it);
        }
        return ans;
    }
};