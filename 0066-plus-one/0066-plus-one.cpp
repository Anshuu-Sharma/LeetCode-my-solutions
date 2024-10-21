class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        bool carry = 1;
        for(int i = n - 1; i>=0; i--){
            if(digits[i] == 9){
                if(carry == 1){
                    digits[i] = 0;
                    carry = 1;
                }
            }
            else{
                if(carry){
                    digits[i]++;
                    carry = 0;
                }
            }
        }
        if(carry){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};