class Solution {
public:
    int maxTotalReward(vector<int>& r) 
    {
        sort(r.begin(),r.end());
        set<int>s;
        s.insert(0);
        for(auto x:r)
        {
            set<int>temp;
            for(auto element:s)
            {
                if(element<x)
                temp.insert(x+element);
            }
            s.insert(temp.begin(),temp.end());
           
        }
        return *s.rbegin();
    }
};