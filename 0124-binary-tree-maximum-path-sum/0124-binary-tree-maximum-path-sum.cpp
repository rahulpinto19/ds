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
    int ans = INT_MIN;
    int help(TreeNode*root)
    {
        if(!root) return 0;

        int left = help(root->left);
        int right = help(root->right);

        int bothLeftRight = left + right + root->val;

        int LeftOrRight = max(left,right) + root->val;

        int onlyRoot = root->val;

        ans = max({ans,bothLeftRight,LeftOrRight,onlyRoot});

        return max({LeftOrRight,onlyRoot});

    }
    int maxPathSum(TreeNode* root) 
    {
        help(root);
        return ans;
    }
};