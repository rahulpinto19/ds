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
    int help(TreeNode*root) {
                if(!root) return 0;

        int left = help(root->left);
        int right = help(root->right);


        int blr = root->val + left + right;
        int lor = root->val + max(left,right);
        int oR = root->val;

        ans = max({ans,oR,lor,blr});

        return max(lor,oR);
    }
    int maxPathSum(TreeNode* root) {

        help(root);
        return ans;

    }
};