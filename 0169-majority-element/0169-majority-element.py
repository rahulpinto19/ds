class Solution(object):
    def majorityElement(self, nums):
        
        cnt = 0
        res = -1
        curr = nums[0]

        for i in nums:
            if i == curr:
                cnt+=1
            else:
                cnt-=1

                if cnt < 0:
                    curr = i
                    cnt = 1
        return curr