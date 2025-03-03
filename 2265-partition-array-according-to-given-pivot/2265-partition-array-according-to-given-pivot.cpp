class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>small,big,same,ans;
        for(auto l:nums)
        {
            if(l<pivot)
            small.push_back(l);
            else if(l==pivot)
            same.push_back(l);
            else
            big.push_back(l);
        }
         small.insert(small.end(),same.begin(),same.end());
        small.insert(small.end(),big.begin(),big.end());
        return small;
    }
};