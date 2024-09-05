class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int x = 0;
        int y = accumulate(rolls.begin(),rolls.end(),0);
        int size = n + rolls.size();
        int totalsum = size*mean;
        x = totalsum - y;
        if(x<0 )
        return {};
        vector<int>ans(n,x/n);
        int rem = x%n;
        int i = 0;
        if(ans[0]>6 || ans[0] ==0)
        return {};
        for(int i=0;i<rem;i++)
        {
            ans[i]+=1;
            if(ans[i]>6 )
            return {};
        }
        
        return ans;
    }
};