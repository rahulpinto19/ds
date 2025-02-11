class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        stack<char>st;
        for(auto x:s)
        {
            if(part.back() == x)
            {
                int flag = 1;
                stack<char>temp = st;
                for(int i = part.size()-2;i>=0;i--)
                {
                    if(temp.size() and temp.top() != part[i])
                    {
                        flag = 0;break;
                    }
                    else
                    {
                        if(temp.size())
                        temp.pop();
                        else
                        {
                            flag = 0;break;
                        }
                    }
                }
                if(flag)
                    st = temp;
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