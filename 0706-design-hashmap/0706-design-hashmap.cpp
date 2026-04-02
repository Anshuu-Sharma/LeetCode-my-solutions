class MyHashMap {
private:
        vector<vector<int>> hash;
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        vector<int> temp = {key, value};
        for(int i = 0; i<hash.size(); i++){
            if(hash[i][0] == key) {
                hash[i][1] = value;
                return;
            }
        }
        hash.push_back(temp);
        return;
    }
    
    int get(int key) {
        for(int i = 0; i<hash.size(); i++){
            if(hash[i][0] == key) return hash[i][1];
        }
        return -1;
    }
    
    void remove(int key) {
        for(int i = 0; i<hash.size(); i++){
            if(hash[i][0] == key) {
                hash.erase(hash.begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */