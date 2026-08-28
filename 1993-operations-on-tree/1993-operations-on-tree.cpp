class LockingTree {
    vector<int> parent;
    vector<vector<int>> children; 
    unordered_map<int, int> locker; // num -> user
    int n;

public:
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        this->n = parent.size();
        
        // Build children list in O(N) once
        children.resize(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    int isLocked(int num) {
        if (locker.count(num)) return locker[num];
        return -1;
    }

    bool lock(int num, int user) {
        if (isLocked(num) != -1) return false;
        locker[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (isLocked(num) != user) return false;
        locker.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        // 1. Target node must be unlocked
        if (isLocked(num) != -1) return false;

        // 2. Check ancestors
        int temp = parent[num];
        while (temp != -1) {
            if (isLocked(temp) != -1) return false;
            temp = parent[temp];
        }

        // 3. BFS to check for locked descendants and unlock them
        queue<int> q;
        q.push(num);
        bool oneDesc = false;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Iterate only over direct children instead of 0..n-1
            for (int child : children[current]) {
                q.push(child);
                if (isLocked(child) != -1) {
                    oneDesc = true;
                    locker.erase(child);
                }
            }
        }

        if (oneDesc) {
            locker[num] = user;
            return true;
        }

        return false;
    }
};