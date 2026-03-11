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
    bool ans = 0;
    bool help(TreeNode*root,TreeNode*subRoot) {
        
        if(root == subRoot) return true;
        
        if(!root or !subRoot) return false;

        if(root->val != subRoot->val)
            return false;
        
            return help(root->left,subRoot->left) and help(root->right,subRoot->right);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(ans) return ans;
        if(!root or !subRoot) return false;

        if(root == subRoot) return true;
        
        if(root->val == subRoot->val)
            ans|= help(root,subRoot);

        ans|=isSubtree(root->left,subRoot);
        ans|=isSubtree(root->right,subRoot);


        return ans;
    }
};