class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int>ans;
        for(int i = 0;i<n;i++)
        {
            int x = i-1,y = i+1;
            int cnt = 0;
            while(x>=0)
            {
                if(boxes[x] == '1')
                    cnt+=abs(x-i);
                x--;
            }
            while(y<n)
            {
                if(boxes[y] == '1')
                    cnt+=abs(y-i);
                y++;
            }
            ans.push_back(cnt);
        }    
        return ans;
    }
};