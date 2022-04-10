// https://leetcode.com/problems/min-stack/

// 155. Min Stack

// Min Stack using two stack

class MinStack {
public:
    stack<int> st;
    stack<int> mn;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mn.empty() || mn.top()>=val){
            mn.push(val);
        }
    }
    
    void pop() {
        int top = st.top();
        st.pop();
        if(mn.top()==top){
            mn.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
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



// without using extra stack


class MinStack {
public:
    stack<long long> st;
    long long mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
          mn = val;
            st.push(val);
        }else{
        
            if(val < mn){
                long long tmp = (2*(val*1LL))-mn;
                st.push(tmp);
                mn = val;
            }else{
                st.push(val);
            }
        }
        
    }
    
    void pop() {
        if(!st.empty()){
            if(st.top()>=mn){
                return st.pop();
            }else{
                int tmp = (2*mn )- st.top();
                mn = tmp;
                st.pop();
            }
        }
    }
    
    int top() {
        if(st.top()>mn){
            return st.top();
        }else{
           
            return mn;
        }
    }
    
    int getMin() {
        return mn;
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
