class Solution {
public:
   
    string cal(int n,string str)
    {
        string temp = "";
        for(int i = 0;i<n;i++)
        {
            temp+=str;
        }
        return  temp;

    }
    bool isNum(char c)
    {
        return c>='0' and c<='9';
    }
    string decodeString(string s) 
    {
        stack<char>st;
     
        for(auto x:s)
        {
            if(x == ']')
            {
                string temp = "";
                while(st.size())
                {
                    if(st.top() == '[')
                    {
                        st.pop();
                        string numberString = "";
                        int number = 0;
                        while(st.size() and isNum(st.top()))
                        {
                            numberString=st.top() + numberString;
                            st.pop();
                        }
                        number = stoi(numberString);
                        reverse(temp.begin(),temp.end());
                        string curr = cal(number,temp);
                        for(auto x:curr)
                        {
                            st.push(x);
                        }
                        break;
                    }
                    temp+=st.top();
                    st.pop();
                }
            }
            else
            st.push(x);
        }
        string ans = "";
        while(st.size())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};