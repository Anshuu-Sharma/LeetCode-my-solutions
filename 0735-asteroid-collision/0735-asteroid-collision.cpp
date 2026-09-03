class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        
        for (int asteroid : asteroids) {
            bool alive = true;
            while (!stack.empty() && asteroid < 0 && stack.top() > 0) {
                if (stack.top() < -asteroid) {
                    stack.pop();
                    continue;
                } else if (stack.top() == -asteroid) {
                    stack.pop();
                }
                alive = false;
                break;
            }
            if (alive) {
                stack.push(asteroid);
            }
        }
        
        vector<int> result(stack.size());
        for (int i = stack.size() - 1; i >= 0; --i) {
            result[i] = stack.top();
            stack.pop();
        }
        
        return result;
    }
};