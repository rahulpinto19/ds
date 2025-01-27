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
   TreeNode*first= NULL,*second= NULL,*prev= NULL;
   

void help(TreeNode*root)
{
    if(!root) return ;

    help(root->left);

    if(prev and root->val <= prev->val)
    {
	    if(!first)
	    first = prev;
	    second = root;
    }
    prev  = root;
    help(root->right);
}

    void recoverTree(TreeNode* root) 
    {
        help(root);    
        int temp = first->val;
        first->val = second->val;
        second->val =temp;
    }
};