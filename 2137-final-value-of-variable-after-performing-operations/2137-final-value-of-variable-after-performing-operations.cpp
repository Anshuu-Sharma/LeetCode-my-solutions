class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(auto it : operations){
            if(it[1] == '+') cnt++;
            else cnt--;
        }
        return cnt;
    }
};