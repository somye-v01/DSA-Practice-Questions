class MyQueue {
    stack<int>inp;
    stack<int>out;
public:

    MyQueue() {
        
    }
    
    void push(int x) {
        inp.push(x);
        return;
    }
    
    int pop() {
        if(!out.empty()){
            int topi = out.top();
            out.pop();
            return topi;
        }
        else{
            int topi = -1;
            while(!inp.empty()){
                topi = inp.top();
                out.push(inp.top());
                inp.pop();
            }
            out.pop();
            return topi;
        }
    }
    
    int peek() {
        //top element nikalo
        if(!out.empty()){
            int topi = out.top();
            return topi;
        }
        while(!inp.empty()){
            out.push(inp.top());
            inp.pop();
        }
        return out.top();
    }
    
    bool empty() {
        return inp.empty() && out.empty();
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