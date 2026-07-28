class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        if(n1 != n2) return false;

        /*
        the thing is that we dont have to actually do it, the question would be little harder when we were asked to calculate minimum number of operations

        for this question:
        we just need to find if frequency count is equal
        */

                std::vector<int> freq1(26, 0);
        std::vector<int> freq2(26, 0);

        for (char ch : word1) {
            freq1[ch - 'a']++;
        }

        for (char ch : word2) {
            freq2[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0)) {
                return false;
            }
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;


    }
};