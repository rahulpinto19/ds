class Solution(object):
    def hammingWeight(self, n):

        val = n
        ans = 0
        while val != 0:
            if val&1 == 1:
                ans+=1
            val>>=1
        return ans
        