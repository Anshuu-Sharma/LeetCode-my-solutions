class Solution {
public:
    long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
        // Sort both the robot and factory vectors to have the elements in ascending order.
        sort(robots.begin(), robots.end());
        sort(factories.begin(), factories.end());


        vector<vector<long long>> memo(robots.size(), vector<long long>(factories.size(), 0));
      

        std::function<long long(int, int)> calculateMinDistance = [&](int robotIndex, int factoryIndex) -> long long {

            if (robotIndex == robots.size()) return 0;

            if (factoryIndex == factories.size()) return 1e15;


            if (memo[robotIndex][factoryIndex] != 0) return memo[robotIndex][factoryIndex]; 


            long long answer = calculateMinDistance(robotIndex, factoryIndex + 1);
            long long tempDistance = 0;


            for (int k = 0; k < factories[factoryIndex][1]; ++k) {

                if (robotIndex + k >= robots.size()) break;

                tempDistance += std::abs(robots[robotIndex + k] - factories[factoryIndex][0]);

                answer = std::min(answer, tempDistance + calculateMinDistance(robotIndex + k + 1, factoryIndex + 1));
            }


            memo[robotIndex][factoryIndex] = answer;
            return answer;
        };


        return calculateMinDistance(0, 0);
    }
};
