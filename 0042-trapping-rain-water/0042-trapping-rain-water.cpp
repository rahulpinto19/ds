class Solution {
public:
    int trap(vector<int>& height) 
    {
        int left = 0,right = height.size()-1;
        int ans = 0;
        int leftMax = 0,rightMax = 0;
        while(left<right)
        {
            if(height[left] <= height[right])
            {
                if(height[left] >= leftMax)
                    leftMax = height[left];
                else
                ans+= abs(leftMax - height[left]);
                left++;
            }
            else
            {
                if(height[right] >= rightMax)
                    rightMax = height[right];
                else
                ans += abs(rightMax - height[right]);
                right--;
            }
        }
        return ans;
    }
};