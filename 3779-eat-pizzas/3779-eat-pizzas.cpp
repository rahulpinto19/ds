class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.begin(),pizzas.end(),greater<int>());
        int days = pizzas.size()/4;
        int oddDays = (days + 1)/2;
        long long ans = 0;

        for(int i = 0,day = 1;day <= days;i++,day++)
        {
            if(day > oddDays)i++;
            ans+=pizzas[i];
        }
        return ans;
        
    }
};