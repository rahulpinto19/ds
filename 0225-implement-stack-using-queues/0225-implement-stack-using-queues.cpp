class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) 
    {
        q2.push(x);
        while(q1.size())
        {
            q2.push(q1.front());
            q1.pop();
        }    
        q1= q2;
        while(q2.size())
            q2.pop();
    }
    
    int pop() 
    {
        int val = q1.front();
        q1.pop();   
        return val; 
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() {
        return !(q1.size());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */