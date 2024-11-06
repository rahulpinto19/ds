class Solution:
    def mySqrt(self, x: int) -> int:
        start = 1
        end = x

        
        lowerBound = 0
        while start<=end:

            mid = (start+end)//2
            if mid == x/mid:
                return mid
            elif mid > x/mid:
                end = mid-1
            else:
                lowerBound = mid
                start = mid+1
        return lowerBound

        