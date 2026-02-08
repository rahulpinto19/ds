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
    int help(TreeNode*root,bool &balanced) {

        if(!root)return 0;
        if(!balanced) return 0;

        int left = help(root->left,balanced);
        int right = help(root->right,balanced);

        if(abs(left - right) > 1) balanced = false;
        return 1 + max(help(root->left,balanced),help(root->right,balanced));
    }
    bool isBalanced(TreeNode* root) {
        
        bool balnced = true;
        help(root,balnced);

        return balnced;
    }
};