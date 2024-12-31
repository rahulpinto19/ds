class Solution {
public:
    int n ;
    int dp[10001];
    int help(vector<int>& days, vector<int>& costs,int pos)
    {
        if(pos>=days.size())
            return 0;
        if(dp[pos] !=-1)
            return dp[pos];

        int buy1,buy7,buy30;
        buy1=buy7=buy30 = 0;

        buy1 = costs[0] + help(days,costs,pos+1);
        int tempPos = pos;
        while(tempPos<n and days[tempPos] < days[pos] + 7)
            tempPos++;
        buy7 = costs[1] + help(days,costs,tempPos);

        tempPos = pos;
        while(tempPos<n and days[tempPos] < days[pos] + 30)
            tempPos++;
        buy30 = costs[2] + help(days,costs,tempPos);

        dp[pos] =  min({buy1,buy7,buy30});
        return dp[pos];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        memset(dp,-1,sizeof(dp));
        n = days.size();
        return help(days,costs,0);    
    }
};