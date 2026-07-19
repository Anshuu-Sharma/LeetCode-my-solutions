class Solution {
public:
    int minOperations(int n) {
        /* array is an odd element series
        1 3 5 7

        2 3 5 6
        3 3 5 5
        4 3 5 4
        4 4 4 4

        all final elements will be equal to n
        formula based solution
        you only need to run from 0 to < n/2
        ops += nums[i]-n
        */

        int ops = 0;
        for(int i = 0; i<n/2; i++){
            ops += n - (2*i + 1);
        }
        return ops;
    }
};