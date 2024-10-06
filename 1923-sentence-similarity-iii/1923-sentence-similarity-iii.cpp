class Solution {
public:
 
    bool areSentencesSimilar(string sentence1, string sentence2) 
    {
       
        deque<string>a,b;
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        string word;

        while(ss1>>word)
        a.push_back(word);
        while(ss2>>word)
        b.push_back(word);

        while(a.size() and b.size() and a.front() == b.front())
        a.pop_front(),b.pop_front();

        while(a.size() and b.size() and a.back() == b.back())a.pop_back(),b.pop_back();
        
        return !(a.size() and b.size());
        
       
    }
};