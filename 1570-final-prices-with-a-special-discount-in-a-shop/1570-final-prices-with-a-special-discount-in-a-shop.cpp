class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int>ans;
        for(int i=0;i<prices.size();i++)
        {
            int minval = prices[i];
            int j = i+1;
            while(j<prices.size())
            {
                if(prices[j] <= prices[i])
                {
                    minval = prices[j];
                    break;
                }
                j++;
            }
            if(j<prices.size())
            ans.push_back(prices[i] - minval);
            else
            ans.push_back(prices[i]);
        }
        return ans;
    }
};