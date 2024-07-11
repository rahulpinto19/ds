class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<string>st;
        string str = "";
        for(auto x:s)
        {
            if(x=='(')
            {
                st.push(str);
                str = "";
            }
            else if(x == ')')
            {
                reverse(str.begin(),str.end());
                if(st.size())
                {
                    str = st.top() + str;
                    st.pop();
                }
            }
            else
            {
                str+=x;
            }
        }    
        return str;
    }
};