class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> hash(26,0);
        for(int i = 0; i<s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for(int i = 0; i<t.size(); i++) {
            if(hash[t[i] - 'a'] != 0) hash[t[i]-'a']--;
        }
        if(*max_element(hash.begin(), hash.end())) return false;
        return true;
    }
};