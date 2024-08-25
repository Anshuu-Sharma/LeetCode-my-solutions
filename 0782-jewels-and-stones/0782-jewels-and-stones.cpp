class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int> char1(256,0);
        for(auto it : jewels){
            char1[it] = 1;
        }

        int cnt = 0;
        for(auto it : stones){
            if(char1[it] == 1){
                cnt++;
            }
        }
        return cnt;
        
    }
};