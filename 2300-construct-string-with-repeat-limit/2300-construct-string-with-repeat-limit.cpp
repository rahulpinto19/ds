class Solution {
public:
    string repeatLimitedString(string s, int r) 
    {
        vector<int>count(26,0);
        for(auto x:s)
            count[x-'a']++;
        
        int i = 25;
        string ans = "";
        while(i>=0)
        {
            if(!count[i]) {i--;continue;}

            for(int j=0;j<min(count[i],r);j++)
                ans+=('a' + i);
            count[i] -= min(count[i],r);

            if(count[i])
            {
                int j = i-1;
                while(j>=0 and count[j] == 0) j--;

                if(j<0) break;

                ans.push_back(j + 'a');
                count[j]-=1;
            }
        }
        return ans;
    }
};