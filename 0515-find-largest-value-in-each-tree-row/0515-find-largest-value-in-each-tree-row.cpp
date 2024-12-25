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
    vector<int> largestValues(TreeNode* root) 
    {
        if(!root)
        return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        ans.push_back(root->val);
        while(!q.empty())
        {
            int size = q.size();
            int set = INT_MIN;
            while(size--)
            {
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left)
                {
                    if(set<temp->left->val)
                    set =temp->left->val;
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    if(set<temp->right->val)
                    set =temp->right->val;
                    q.push(temp->right);
                }
            }
            if(q.size())
            ans.push_back(set);
        }    
        return ans;
    }
};