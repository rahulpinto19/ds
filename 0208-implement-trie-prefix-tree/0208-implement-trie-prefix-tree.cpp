struct Node
{
    Node*next[26];
    bool isWord;
    Node()
    {
        for(auto &a:next)
            a = NULL;
        isWord = false;
    }
};
class Trie {
public:
    Node*root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node*ptr = root;
        for(auto x:word)
        {
            int i = x-'a';
            if(!(ptr->next[i])) ptr->next[i] = new Node;
            ptr = ptr->next[i];
        }    
        ptr->isWord = true;
    }
    
    bool search(string word) {
        Node*ptr = root;
        for(auto x:word)
        {
            int i = x -'a';
            if(!ptr->next[i]) return false;
            ptr = ptr->next[i];
        }
        return ptr->isWord;
    }
    
    bool startsWith(string prefix) {
        
        Node*ptr = root;
        for(auto x:prefix)
        {
            int i = x -'a';
            if(!ptr->next[i]) return false;
            ptr = ptr->next[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */