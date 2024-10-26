class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans(2,0);

        int n = 1;
        int temp = 0;

        for(char it : s){
            if(temp + widths[it - 'a'] <= 100){
                temp += widths[it - 'a'];
            }
            else {
                n++;
                temp = widths[it - 'a'];
            }
        }
        ans[0] = n;
        ans[1] = temp;            
        return ans;
    }
};