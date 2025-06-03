class Solution {
public:
    bool uniqueCharacters(string str) {
        sort(str.begin(), str.end());

        for (int i = 0; i < str.length()-1; i++) {
            if (str[i] == str[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int helper(int ind, vector<string>& arr, string s) {
        if(ind == arr.size()) return s.size();

        int take = 0;
        if(uniqueCharacters(s+arr[ind])) {
            take = helper(ind+1, arr, s+arr[ind]);
        }
        int notTake = helper(ind+1, arr, s);

        return max(take, notTake);

    }

    int maxLength(vector<string>& arr) {
        return helper(0, arr, "");
    }
};