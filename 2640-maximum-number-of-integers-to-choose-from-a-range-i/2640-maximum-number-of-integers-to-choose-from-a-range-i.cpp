class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) 
    {
        set<int>s = {b.begin(),b.end()};
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(s.find(i) == s.end())
            v.push_back(i);
        }    
        int i = 0,sum = 0;
       
        while(i<v.size() and sum+v[i]<=maxSum)
        {
            sum+=v[i];
            i++;
        }
        return i;
    }
};