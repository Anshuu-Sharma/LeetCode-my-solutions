class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> numY(n + 1, 0); // number of Y at and after ith index
        vector<int> numN(n + 1, 0); // number of N before ith index

        // Count 'N' moving forward
        for (int i = 0; i < n; i++) {
            numN[i + 1] = numN[i] + (customers[i] == 'N' ? 1 : 0);
        }

        // Count 'Y' moving backward
        for (int i = n - 1; i >= 0; i--) {
            numY[i] = numY[i + 1] + (customers[i] == 'Y' ? 1 : 0);
        }

        int minPen = INT_MAX;
        int bestHour = 0;

        // Check all potential closing hours from 0 to n
        for (int i = 0; i <= n; i++) {
            int penalty = numY[i] + numN[i];
            if (penalty < minPen) {
                minPen = penalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};