class Solution {
public:
    bool isValid(string word) {
        if(word.size()<=2) return false;
        if (word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != string::npos) return false;
        if (word.find_first_of("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ") == std::string::npos) return false;
        if (word.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") == string::npos) return false;
        if (word.find_first_of("aeiouAEIOU") == std::string::npos) return false;

        return true;


    }
};