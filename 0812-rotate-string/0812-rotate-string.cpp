class Solution {
public:
    void rotate(string& s) {
        char temp = s[0];
        s.erase(0,1);
        s.push_back(temp);
    }
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(s.size() != goal.size()) return false;
        if(s == goal) return true;
        int i = 0;
        while(i < s.size()){
            i++;
            if(s == goal) return true;
            rotate(s);
        }
        return false;
    }
};