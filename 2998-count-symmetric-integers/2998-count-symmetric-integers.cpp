class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low; i<=high; i++){
            string num = to_string(i);
            int len = num.size();
            if((len % 2 == 0)){
                    int l_half = 0;
                    int r_half = 0;
                for(int j = 0; j<len/2; j++){
                    l_half += (num[j] - '0');
                    r_half += (num[j + (len/2)] - '0');
                }
                if(l_half == r_half) ans++;
            }
        }
        return ans;
    }
};