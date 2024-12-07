class Solution(object):
    def maximumSubarraySum(self, nums, k):
       
        dict = {}
        n = len(nums)

        ans = 0
        currsum = 0

        for i in range(k):

            if nums[i] in dict:
                dict[nums[i]]+=1
            else:
                dict[nums[i]] = 1

            currsum += nums[i]

        if len(dict) == k:
            ans = max(ans,currsum)

        for i in range(k,n):

            currsum = currsum - nums[i-k] + nums[i]
            if dict[nums[i-k]] == 1:
                dict.pop(nums[i-k])
            else:
                dict[nums[i-k]] -=1

            if nums[i] in dict:
                dict[nums[i]]+=1
            else:
                dict[nums[i]] = 1
            
            if len(dict) == k:
                ans = max(ans,currsum)

        return ans

            