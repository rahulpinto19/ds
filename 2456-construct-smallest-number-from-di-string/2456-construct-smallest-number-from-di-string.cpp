class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        stack<int>st;
        for(int index = 0;index<=pattern.size();index++)
        {
            st.push(index + 1);

            if(index == pattern.size() || pattern[index] == 'I')
            {
                while(st.size())
                {
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return res;
    }
};