class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        set<string>st,st2;
        for(auto x:folder)
        {
           
            st.insert(x);
        }    
        for(auto x:st)
        {
            int i=1;
            string temp = "/";
            while(i<x.size())
            {
                while(i<x.size() and x[i]!='/')
                temp += x[i++];

                // cout<<temp<<" ";
                if(st.find(temp) != st.end() and temp != x)
                {
                    st2.insert(x);
                 
                }

                if(i<x.size())
                temp+=x[i++];
            }
            // cout<<endl;
        }
        vector<string>ans;
        for(auto x:st)
        {
            if(st2.find(x) == st2.end())
            ans.push_back(x);
        }
        return ans;
    }
};