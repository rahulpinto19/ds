class Solution {
public:
    int valid(int x) {

        int rem = 2;
        int res = 1 + x;
        for(int i = 2;i<=x/2 and rem <=5;i++) {

                if(x%i == 0) {
                    rem++;
                    res+=i;
                }
        }
        return rem == 4 ? res : 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        
        int res = 0;
        for(auto x:nums) {

            int curr = valid(x);


            res+=curr;
        }
        
        return res;
    }
};

