class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int pos = 0,curr_tank = 0,total_tank = 0,n = cost.size();
        for(int i = 0;i < n;i++) {

                int gain = gas[i] - cost[i];
                total_tank += gain;
                curr_tank += gain;

                if(curr_tank < 0) {
                    pos = i + 1;
                    curr_tank = 0;
                }
        }

        if(total_tank >= 0) return pos;
        return -1;
    }
};

// 4-1 => 3

