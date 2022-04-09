class MyQueue {
private:
    vector<stack<int>> stacks;
    bool curr_stack;
public:
    MyQueue() {
        stacks.resize(2);
        curr_stack = 0;
    }
    
    void push(int x) {
        while(!stacks[curr_stack].empty()){
            stacks[1-curr_stack].push(stacks[curr_stack].top());
            stacks[curr_stack].pop();
        }
        stacks[curr_stack].push(x);
        while(!stacks[1-curr_stack].empty()){
            stacks[curr_stack].push(stacks[1-curr_stack].top());
            stacks[1-curr_stack].pop();
        }
    }
    
    int pop(bool isNotPeek = true) {
        int top = -1;
        if(!stacks[curr_stack].empty()){
            top = stacks[curr_stack].top();
            if(isNotPeek) stacks[curr_stack].pop();
        }
        return top;
    }
    
    int peek() {
        return pop(false);
    }
    
    bool empty() {
        return stacks[curr_stack].empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
