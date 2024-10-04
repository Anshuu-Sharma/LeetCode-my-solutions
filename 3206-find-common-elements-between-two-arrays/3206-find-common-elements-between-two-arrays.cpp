class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

        int a1 = 0;
        int a2 = 0;
       

        vector<int> hash_nums2(101,0);
        for(int it : nums2){
            hash_nums2[it]++;
        }

        vector<int> hash_nums1(101,0);
        for(int it : nums1){
            hash_nums1[it]++;
        }

        for(int it : nums1){
            if(hash_nums1[it] != 0 && hash_nums2[it] != 0){
                a1 += hash_nums1[it];
                a2 += hash_nums2[it];
                hash_nums1[it] = 0;
                hash_nums2[it] = 0;
            }
        }

        return {a1, a2};

    }
};