class NumberContainers {
public:
    unordered_map<int,int>mp1;
    unordered_map<int,set<int>>mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) 
    {
        if(mp1.find(index) != mp1.end())
        {
            mp2[mp1[index]].erase(index);
            if(mp2[mp1[index]].size() == 0)
                mp2.erase(mp1[index]);
            mp1[index] = number;
            mp2[number].insert(index);
        }   
        else
        {
            mp1[index] = number;
            mp2[number].insert(index);
        } 
    }
    
    int find(int number) {
        if(mp2.find(number) == mp2.end())
            return -1;
        for(auto val:mp2[number])
            return val;
        return -1;
        // return mp2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */