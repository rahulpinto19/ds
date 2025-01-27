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
    int ans = 1;
    void countGoodNodes(TreeNode* root,int val)
    {
        if(!root) return ;

    if(root->left and root->left->val >= val){
	    ans++;
	    countGoodNodes(root->left,root->left->val);
        }
    else
        countGoodNodes(root->left,val);

    if(root->right and root->right->val >=val){
	    ans++;
	    countGoodNodes(root->right,root->right->val);
        }
        else
        countGoodNodes(root->right,val);
    }
    int goodNodes(TreeNode* root) 
    {
        countGoodNodes(root,root->val);
        return ans;
    }
};