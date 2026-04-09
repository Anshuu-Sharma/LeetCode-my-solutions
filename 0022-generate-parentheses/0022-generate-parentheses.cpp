class Solution {
public:
    void helper(int leftPairsLeft, int rightPairsLeft, string s, vector<string>& ans, int n) {
        if(leftPairsLeft == 0 && rightPairsLeft == 0) {
            ans.push_back(s);
            return;
        }

        if(leftPairsLeft>0) helper(leftPairsLeft-1, rightPairsLeft, s + '(',  ans, n);
        if(rightPairsLeft>0 && (n-leftPairsLeft)>(n-rightPairsLeft)) helper(leftPairsLeft, rightPairsLeft-1, s + ')',  ans, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, "", ans, n);

        return ans;
    }
};