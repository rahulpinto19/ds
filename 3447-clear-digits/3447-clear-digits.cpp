class Solution {
    bool isDigit(char c)
    {
        return c>= '0' and c<= '9';
    }
public:
    string clearDigits(string s) 
    {
        stack<char>st;
        for(auto x:s)
        {
            if(isDigit(x))
            {
                if(st.size() and !isDigit(st.top()))
                    st.pop();
                else
                    st.push(x);
            }
            else
            st.push(x);
        }
        string ans = "";
        while(st.size())
        {
            ans = st.top() + ans;
            st.pop();  
        }
        return ans;
    }
};