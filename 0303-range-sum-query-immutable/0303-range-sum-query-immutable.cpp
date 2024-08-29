class NumArray {
public:
    vector<int>k;
    NumArray(vector<int>& nums) 
    {
        k.push_back(0);
        int temp=0;
        for(int i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            k.push_back(temp);
        }
    }
    
    int sumRange(int left, int right) {
            return k[right+1]-k[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */