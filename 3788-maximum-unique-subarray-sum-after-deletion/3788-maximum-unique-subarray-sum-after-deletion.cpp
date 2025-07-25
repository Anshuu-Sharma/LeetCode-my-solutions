class Solution {
 public:
  int maxSum(vector<int>& nums) {
    int maxi = ranges::max(nums);
    if (maxi <= 0) return maxi;

    unordered_set<int> st(nums.begin(), nums.end());


    // return accumulate(numsSet.begin(), numsSet.end(), 0,
                    //   [](int acc, int num) { return acc + max(0, num); });

    int sum = 0;
    while(!st.empty()){
        int num = *st.begin();st.erase(num);
        if(num>0) sum+=num;
    }

    return sum;
  }
};
