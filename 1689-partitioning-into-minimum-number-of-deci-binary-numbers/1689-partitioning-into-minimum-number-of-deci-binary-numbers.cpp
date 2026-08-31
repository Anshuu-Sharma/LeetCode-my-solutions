class Solution {
public:
    int minPartitions(string n) {
        int m = 0;
        for(int i=0;i<n.length();i++){
            int cur = n[i]-'0';
            if(cur>m){
                m = cur;
            }
            if(m==9){
                break;
            }
        }
        return m;
    }
};