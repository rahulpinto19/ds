class Solution(object):
    def twoSum(self, nums, target):
        dict = {}

        for i in range(0,len(nums)):

            val = target - nums[i]
            if val in dict:
                return [i,dict[val]]
            
            dict[nums[i]] = i
        
        return [-1,-1]