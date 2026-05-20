class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        // years are from 1950 to 2050
        vector<int> prefix(2051, 0);

        for(auto &it : logs) {
            int birth = it[0];
            int death = it[1];

            prefix[birth]++;   // population increases
            prefix[death]--;   // population decreases
        }

        int maxi = 0;
        int ansYear = 1950;
        int population = 0;

        for(int year = 1950; year <= 2050; year++) {
            population += prefix[year];

            if(population > maxi) {
                maxi = population;
                ansYear = year;
            }
        }

        return ansYear;
    }
};