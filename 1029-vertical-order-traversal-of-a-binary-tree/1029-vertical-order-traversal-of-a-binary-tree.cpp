/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {

            TreeNode*r = q.front().first;
            int level = q.front().second.first;
            int pos = q.front().second.second;
            q.pop();
            nodes[pos][level].insert(r->val);
            if(r->left)
            {
                q.push({r->left,{level+1,pos-1}});
            }
            if(r->right)
            {
                q.push({r->right,{level+1,pos+1}});
            }
            }
        }    
        vector<vector<int>>ans;
        for(auto p:nodes)
        {
            vector<int>temp;
            for(auto q:p.second)
            {
                temp.insert(temp.end(),q.second.begin(),q.second.end());
                // cout<<val.first;
                // temp.push_back(val.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};