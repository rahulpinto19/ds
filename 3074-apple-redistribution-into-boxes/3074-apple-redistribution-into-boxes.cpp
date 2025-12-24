class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int apples = accumulate(apple.begin(),apple.end(),0);

        sort(capacity.begin(),capacity.end());

        int cnt = 0;
        int ptr =  capacity.size()-1;
        while(apples>0 and ptr>=0) {
            cnt++;
            apples-=capacity[ptr--];
        }
        return cnt;
    }
};