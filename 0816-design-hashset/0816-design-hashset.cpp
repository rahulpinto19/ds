class MyHashSet {
public:
    vector<list<int>>st;
    const int size = 500;
    MyHashSet() 
    {
        st.resize(size);
    }
    
    void add(int key) 
    {
        if(contains(key)) return;
        int index = key%size;
        st[index].push_back(key);
    }
    
    void remove(int key) 
    {
        int index = key%size;
        st[index].remove(key);
    }
    
    bool contains(int key) 
    {
        
        
        int index = key%size;
        for (int storedKey : st[index]) {
            if (storedKey == key) {
                return true;
            }
        }
        return false;
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */