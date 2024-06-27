class MinStack {
public:
   
    MinStack() {
        
    }
    
    void push(int val) {
         ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        int mini;
        if(st.empty()) mini = val;
        else{
            mini = min(st.top().second, val);
        }
            st.push({val,mini});
    }
    
    void pop() {
    int tmp = st.top().first;
    st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
    private:
    stack<pair<int,int>> st;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */