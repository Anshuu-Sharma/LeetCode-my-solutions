class Solution {
public:
    string stringBuilder(vector<string>& words){
        string temp = "";
        for(string it:words){
            temp = temp + it;
        }
        return temp;
    }
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;

        s1 = stringBuilder(word1);
        s2 = stringBuilder(word2);

        return s1 == s2;
    }
};