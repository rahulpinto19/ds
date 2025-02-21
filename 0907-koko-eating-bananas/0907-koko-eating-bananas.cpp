class Solution {
public:
    bool possible(int k,vector<int>&piles,int h)
    {
        for(auto x:piles)
        {
            h-=((x/k));
            h-= (!(!(x%k)));
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = INT_MIN;

        for(auto x:piles)
        {
            high = max(high,x);
        }    
        int ans = -1;
        while(low < high)
        {
            int mid = (low + high)/2;

            if(possible(mid,piles,h))
            {
                high = mid;
            }
            else
                low = mid+1;
        }
        return low;
    }
};