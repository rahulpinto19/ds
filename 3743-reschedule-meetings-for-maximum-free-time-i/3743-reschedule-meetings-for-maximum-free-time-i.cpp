class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) 
    {
        int n = s.size();
        vector<int>gaps(1,s[0]);
        for(int i=0;i<n-1;i++)
        {
            gaps.push_back(s[i+1] - e[i]);        
        }
        gaps.push_back(eventTime - e.back());
        
         
        int sum =0,ans = 0;
        for(int i = 0;i<gaps.size();i++)
        {
            sum+=gaps[i] - ((i>=k+1) ? gaps[i-(k+1)] : 0);
            ans = max(ans,sum);
        }
        return ans;
    }
};