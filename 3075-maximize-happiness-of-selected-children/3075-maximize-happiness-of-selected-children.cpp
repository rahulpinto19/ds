class Solution {
public:
    static bool comp(int a ,int b) {
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        // priority_queue<int>pq;
        sort(happiness.begin(),happiness.end(),comp);

        int number = 0,ptr = 0;
        long long res = 0;
        while(ptr<happiness.size() and k and happiness[ptr]-number > 0) {

            res+=(happiness[ptr]-number);
            number++;
            ptr++;
            k--;
        }
        return res;
    }
};