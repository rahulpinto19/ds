class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size()%2 ==0 and nums2.size()%2 == 0)
            return 0;
        else if (nums1.size()%2  == nums2.size()%2)
        {
            int ans = 0;
            for(auto x:nums1)
                ans^=x;
            for(auto x:nums2)
                ans^=x;
            return ans;
        }    
        else
        {
            
            int ans = 0;
            if(nums1.size()%2 == 0)
            {
                
                for(auto x:nums1)
                ans^=x;
            }
            else
            {
               

                for(auto x:nums2)
                ans^=x;
            }
            return ans;
        }
    }
};