class Solution(object):
    def trap(self, height):
        left , right = 0 , len(height) - 1
        leftMax , rightMax = 0,0
        ans = 0
        while left <= right:

            if height[left] <= height[right]:

                if leftMax > height[left]:
                    ans+=(leftMax - height[left])
                else:
                    leftMax = height[left]
                left+=1
            else:
                if rightMax > height[right]:
                    ans+= (rightMax - height[right])
                else:
                    rightMax = height[right]
                right-=1
        return ans

