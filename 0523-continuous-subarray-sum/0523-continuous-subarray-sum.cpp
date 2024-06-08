class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int Pref_Sum = 0;
        unordered_map<int,int>mp;
        int index = 0;
        for(auto element:nums)
        {
            Pref_Sum=(Pref_Sum + element)%k;
            
            if(!Pref_Sum and index)
            return 1;

            if(mp.find(Pref_Sum) != mp.end())
            {
                if(index - mp[Pref_Sum] > 1)
                return 1;
            }
            else
            {
                mp[Pref_Sum] = index;
            }
            index++;
        }    
        return 0;
    }
};