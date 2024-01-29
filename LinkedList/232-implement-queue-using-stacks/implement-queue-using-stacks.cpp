class MyQueue {
    stack<int> inp;
    stack<int> out;
public:
    MyQueue() {
      
    }
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if(!out.empty()){
            int x = out.top();
            out.pop();
            return x;
        } 
        else{
            while(!inp.empty()){
                out.push(inp.top());
                inp.pop();
            }
            int x = out.top();
            out.pop();
            return x;
        }

    }
    
    
    int peek() {
        if(!out.empty()){
            int x = out.top();
            return x;
        }
        int n = inp.size();
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