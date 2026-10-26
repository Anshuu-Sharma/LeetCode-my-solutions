class Solution {
public:
    bool threeFibonacciSum(int n) {
        // just maintain 3 variables
        int num1 = 0;
        int num2 = 1;
        int num3 = 1;
        int curr = 0;
        while(curr<=n){
            if(num1 + num2 + num3 == n) return true;

            curr = num3 + num2;
            num1 = num2;
            num2 = num3;
            num3 = curr;
        }

        return false;


    }
};