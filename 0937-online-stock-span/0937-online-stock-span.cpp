class StockSpanner {
public:

    //m-1 using single stack
    stack<pair<int, int>> st; 
    StockSpanner() {
        
    }
    int next(int price) {
        int count = 1;
        while (!st.empty() && st.top().first <= price) {
            count += st.top().second;
            st.pop();
        }
        
        st.push({price, count});
        return count;
    }

    //m-2 using double stack
    // stack<int>st;
    // stack<int>st2;
    // StockSpanner() {
        
    // }
    
    // int next(int price) {
    //     int count=1;
    //     if(!st.empty())
    //     {
    //         // count=1;
    //         while(!st.empty() && st.top() <= price)
    //         {
    //             st2.push(st.top());
    //             st.pop();
    //             count++;
    //         }
    //         while(!st2.empty())
    //         {
    //             st.push(st2.top());
    //             st2.pop();
    //         }
    //         st.push(price);
    //         return count;
    //     }
    //     else 
    //     {
    //         return count;
    //     }
    
    // }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */