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
    
    int maxDepth(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        if(!root)
            return level;
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode*top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            level++;
        }
        return level;
    }
};