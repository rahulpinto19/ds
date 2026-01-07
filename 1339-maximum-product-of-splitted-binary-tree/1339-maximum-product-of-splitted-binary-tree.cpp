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
    int mod = 1e9 + 7;
    long long totSum = 0;
    long long res = 0;
    int sum(TreeNode* root) {
        if(!root) {
            return 0;
        }

        return root->val + sum(root->left) + sum(root->right);
    }
    long long  help(TreeNode* root) {

        if(!root) return 0;
        
        long long subtreeSum = root->val + help(root->left) + help(root->right);

    long long curProd = subtreeSum * (totSum - subtreeSum);

    if(curProd > res) {
        res = curProd;
    }

    return subtreeSum;

    }
    int maxProduct(TreeNode* root) {
        totSum = sum(root);

        help(root);
        return res%mod;
    }
};