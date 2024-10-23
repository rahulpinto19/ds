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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int size = q.size(),sum = 0;
            vector<TreeNode*>v;
            while(size--)
            {
                TreeNode*temp  = q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left) q.push(temp->left),sum+=temp->left->val;
                if(temp->right) q.push(temp->right),sum+=temp->right->val;
            }
            for (auto x:v)
            {
                int t = sum;
                if(x->left) t-=x->left->val;
                if(x->right) t-=x->right->val;
                if(x->left) x->left->val = t;
                if(x->right) x->right->val = t;
            }
        }
        return root;
    }
};