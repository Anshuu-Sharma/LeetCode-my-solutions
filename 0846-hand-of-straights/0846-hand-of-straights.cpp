class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> freq;

        for (int x : hand) {
            freq[x]++;
        }

        while (!freq.empty()) {

            int start = freq.begin()->first;

            for (int i = 0; i < groupSize; i++) {

                int card = start + i;

                if (freq.find(card) == freq.end()) {
                    return false;
                }

                freq[card]--;

                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};