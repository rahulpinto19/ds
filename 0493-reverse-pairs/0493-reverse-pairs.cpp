class Solution {
public:
    unordered_map<int,set<int,int>>mp;
    void merge(vector<int>&nums,int start,int mid,int end)
    {
        vector<int>left,right;
        for(int i=start;i<=mid;i++) left.push_back(nums[i]);
        for(int i=mid+1;i<=end;i++) right.push_back(nums[i]);

        int p1 = 0,p2 = 0,k = start;
        while(p1<left.size() and p2<right.size())
        {
            if(left[p1] <= right[p2])
            {
                nums[k++] = left[p1++];
            }
            else
            {
                nums[k++] = right[p2++];

            }
        } 
        while(p1<left.size())
            nums[k++] = left[p1++];
        while(p2<right.size())
            nums[k++] = right[p2++];

    }
    int ans = 0;
    void help(vector<int>&nums,int start,int mid,int end)
    {
        int j = mid+1;
        for(int i = start;i<=mid;i++)
        {
            while (j <= end && (long long)nums[i] > 2LL * (long long)nums[j])
                    j++;
            ans+=(j - (mid+1));
        }
    }
    void mergesort(vector<int>&nums,int start,int end)
    {
        if(start>=end) return;

        int mid = start + ( end - start)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        help(nums,start,mid,end);
        merge(nums,start,mid,end);
    }
    int reversePairs(vector<int>& nums) 
    {
        mergesort(nums,0,nums.size()-1);
       
        return ans;
    }
};