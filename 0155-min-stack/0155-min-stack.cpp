class MinStack {
public:
    stack<int> st;     // main stack to store values
    stack<int> minSt;  // auxiliary stack to track minimums

    // Constructor
    MinStack() {
    }
    // Push value onto stack
    void push(int val) {
        st.push(val);
        // If minSt is empty OR val is smaller/equal to current min, push onto minSt
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    // Pop top element
    void pop() {
        // If the element being popped is the current minimum, pop from minSt too
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    // Return top element
    int top() {
        return st.top();
    }
    
    // Return current minimum
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */