class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        map<int,int>mp;;
        for(auto x:hand)
        mp[x]++;

        if(hand.size()%groupSize)
        return 0;

        for(int i=0;i<hand.size()/groupSize;i++)
        {
            auto it  = mp.begin();
            int top = it->first;
            for(int j=0;j<groupSize;j++)
            {
             
                if(mp.find(top) ==mp.end())
                return 0;
                mp[top]--;

                if(mp[top] == 0)
                mp.erase(top);
                
                top++;
            }
        }    
        return 1;
    }
};