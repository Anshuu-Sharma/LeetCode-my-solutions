class Solution {
public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        while(num.length()){
            if((num.back()-'0')%2==0) num.pop_back();
            else break;
        }
        return num;
    }
};