class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // vector<>
        vector<int>nums1 = nums;
        sort(nums1.begin(),nums1.end());  
        int n = nums.size();
        int i = n-1,j = 0,k = i/2 + 1;
        while(i>=0)
        {
           nums[i--] = nums1[ i&1 ? k++ : j++];
        }
    }
};
// 1 1 2 2 3 3

// 1 2 1 3 1 3