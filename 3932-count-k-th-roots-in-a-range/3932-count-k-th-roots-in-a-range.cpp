class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return r-l+1;
        int count = 0;

        int range = (l+r)/2;
        for(int i = 0; i<=range; i++){
            int temp = pow(i,k);
            if(temp > r) break;
            if(temp >= l && temp <= r){
                count++;
            }
        }
        return count;
    }
};