class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        /*
        20
        20/2 = 10
        10/2 = 5
        5-1 = 4 -> if number odd then -1 otherwise half if maxDoubles left
        4/2 = 2
        2-1 = 1
        */

        int moves = 0;
        int limit = maxDoubles;

        while (target > 1) {
            // Optimization: If no doubles left, directly add remaining steps
            if (limit == 0) {
                moves += (target - 1);
                break;
            }

            // If target is even, divide by 2
            if (target % 2 == 0) {
                target /= 2;
                limit--;
            } 
            // If target is odd, subtract 1 to make it even
            else {
                target--;
            }

            moves++;
        }

        return moves;
    }
};