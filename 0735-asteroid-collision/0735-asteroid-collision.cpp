class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i = 0;
        int n = asteroids.size();
        while (i < n) {
            int item = asteroids[i];
            bool isDestroyed = false; // checks if item is destroyed;
            if (st.empty()) {
                st.push(item);
            } else {
                if (!((item ^ st.top()) >= 0)) {
                    while (!st.empty() && item < 0 && st.top() > 0) {
                        if (abs(st.top()) < abs(item)) {
                            st.pop();
                            continue;
                        } else if (abs(st.top()) == abs(item)) {
                            st.pop();
                            isDestroyed = true;
                            break;
                        } else {
                            // top asteroid is larger; current destroyed
                            isDestroyed = true;
                            break; // current asteroid destroyed, exit loop
                        }
                    }
                }
                if (isDestroyed == false)
                    st.push(item);
            }
            i++;
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        ranges::reverse(ans);
        return ans;
    }
};