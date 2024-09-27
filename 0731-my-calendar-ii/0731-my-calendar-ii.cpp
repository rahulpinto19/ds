class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) 
    {
        mp[start]++;
        mp[end]--;    
        int booked = 0;

        for(auto x:mp)
        {
            booked+= x.second;
            if(booked ==3)
            {
                mp[start]--;
                mp[end]++;
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */