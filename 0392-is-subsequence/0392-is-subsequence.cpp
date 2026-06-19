class Solution {
public:
    bool helper(int ind1, int ind2, string s, string t){
        if(ind1<0) return true;
        if(ind2<0 && ind1 >= 0) return false;

        if(s[ind1] == t[ind2]) return helper(ind1-1, ind2-1, s, t);
        else{
            return helper(ind1, ind2-1, s, t);
        }

    }
    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        return helper(n1-1,n2-1,s,t);
    }
};