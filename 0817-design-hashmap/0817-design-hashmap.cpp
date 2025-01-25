class MyHashMap {
public:
        vector<vector<pair<int,int>>>map;
        const int size = 10000;
    MyHashMap() 
    { 
        map.resize(size);
    }

    void put(int key, int value) 
    {
       int index = key%size;
       vector<pair<int,int>>&rows = map[index];
       for(auto &x:rows)
       {
            if(x.first == key)
            {
                x.second = value;
                return;
            }
       }
       map[index].push_back({key,value});
    }
    
    int get(int key) 
    {
        int index = key%size;
        vector<pair<int,int>>&rows = map[index];
        for(auto &x:rows)
        {
            if(x.first == key)
                return x.second;
        }    
        return -1;
    }
    
    void remove(int key) 
    {
        int index = key%size;
        vector<pair<int,int>>&rows = map[index];
        for(auto &x:rows)
        {
            if(x.first == key)
                {
                    x.first = -1;
                    x.second = -1;
                }
        }    
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */