/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node)
            return NULL;
        
        unordered_map<Node*,Node*>mp;
        mp[node] = new Node(node->val);
        queue<Node*>q;
        q.push(node);
     
        while(q.size())
        {
            Node* CurrNode = q.front();
            
            q.pop();
            for(auto neighbor:CurrNode->neighbors)
            {

                    if(mp.find(neighbor) == mp.end())
                    {
                        q.push(neighbor);
                        mp[neighbor] = (new Node(neighbor->val));

                    }
                    mp[CurrNode]->neighbors.push_back(mp[neighbor]);

            }
        }
        return mp[node];
       
    }
};