struct Node
{
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k = 0, int v = 0) : key(k), value(v), prev(NULL), next(NULL) {}  // Constructor added
};

class dll
{
    int size = 0;
    public:
    Node*head,*tail;
    dll()
    {
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    Node* insertAtend(int key,int val)
    {
        size++;
       Node*node = new Node(key,val);

       Node*prev = tail->prev;
       prev->next = node;
       node->next = tail;
       tail->prev = node;
       node->prev = prev;

       return node; 
    }
    
    
    int deleteNode(Node*root )
    {
        int key = root->key;
        root->prev->next = root->next;
        root->next->prev = root->prev;
        delete root;
        return key;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    dll ll;
    int size = 0;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end())
        {
            Node* node = mp[key];
            int k = node->key;
            int v = node->value;
            mp.erase(ll.deleteNode(node));
            mp[key] = ll.insertAtend(k,v);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key) == mp.end())
        {
            if(size == cap)
            {
                int oldkey = ll.deleteNode(ll.head->next);
                mp.erase(oldkey);
                size--;
            }
            mp[key] = ll.insertAtend(key,value);
            size++;
        }
        else
        {
            ll.deleteNode(mp[key]);
            mp.erase(key);
            mp[key] = ll.insertAtend(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */