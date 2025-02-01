class Solution {
public:
    int trap(vector<int>& h) 
    {
        int left =0,right = h.size()-1;
        int leftMax = 0,rightMax = 0,ans = 0;
        while(left<right)
        {
            if(h[left] <= h[right])
            {
                if(h[left] >= leftMax)
                    leftMax = h[left];
                else
                    ans += abs(leftMax - h[left]);
                left++;
            }
            else
            {
                if(h[right] >= rightMax)
                    rightMax = h[right];
                else
                    ans+=abs(rightMax - h[right]);
                right--;
            }
        }
        return ans;
    }
};

/*
  int left = 0,right = h.size()-1;
        int ans=0,leftMax=0,rightMax=0;
        while(left<=right)
        {
            if(h[left] <= h[right])
            {
                if(h[left]>=leftMax)
                leftMax = h[left];
                else
                ans+=abs(h[left]-leftMax);
                left++;
            }
            else
            {
                if(h[right] >=rightMax)
                rightMax = h[right];
                else
                ans+=abs(h[right]-rightMax);
                right--;
            }
        }    
        return ans;
*/ 