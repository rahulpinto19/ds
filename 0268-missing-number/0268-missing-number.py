class Solution(object):
    def missingNumber(self, nums):
        
        res = 0
        for i in range(0,len(nums)):
            res^=(nums[i]^(i+1))
        return res
        