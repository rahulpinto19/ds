class Solution {
public:
    int parse(string str)
    {
        int ind  = 0;
        int hour = 0;
        int min = 0;
        int flip = 1;
        while(ind<str.size())
        {
            if(str[ind] == ':')
            {
                flip = !flip;
                ind++;
                continue;
            }
            if(flip)
            {
                hour = hour*10 + (str[ind] - '0');
            }
            else
            {
                min = min*10 + (str[ind] - '0');
            }
            ind++;
        }
        return min + 60*hour;
    }
    
    int findMinDifference(vector<string>& t) 
    {
        vector<int>mins;
        for(auto x:t)
        {
            mins.push_back(parse(x));
        } 
        sort(mins.begin(),mins.end());
        
        int ans = INT_MAX;

        for(int i=1;i<=mins.size();i++)
        {
            ans = min
            ({
                
                ans,
                (1440 - abs(mins[i%mins.size()] - mins[i-1])),
                abs(mins[i%mins.size()]-mins[i-1])
                });
        }
        return ans;
    }
};