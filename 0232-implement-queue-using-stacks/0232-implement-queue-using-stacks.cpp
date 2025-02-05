class MyQueue {
public:
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x)
    {
        help(x);
    }
    void help(int x)
    {
        if(s.size() == 0)
        {
            s.push(x);
            return;
        }
        int tempVal = s.top();
        s.pop();
        help(x);
        s.push(tempVal);

    }
    int pop() 
    {
        int val = s.top();
        s.pop();
        return val;    
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() 
    {
        return !(s.size());    
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