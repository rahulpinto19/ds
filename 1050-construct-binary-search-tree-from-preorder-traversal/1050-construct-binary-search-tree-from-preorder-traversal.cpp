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
    TreeNode*help(vector<int>&preorder,int start,int end)
    {
        if(start>end)
            return NULL;
        if(end == start)
            return new TreeNode(preorder[end]);

        TreeNode*root = new TreeNode(preorder[start]);
        int ind = start + 1;
        while(ind <= end and preorder[ind] < preorder[start])
            ind++;
        root->left = help(preorder,start+1,ind-1);
        root->right = help(preorder,ind,end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        return help(preorder,0,preorder.size()-1);
    }
};