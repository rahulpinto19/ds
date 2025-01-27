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
    vector<int>arr;int i = 0;
    void Inorder(TreeNode*root)
    {

        if(!root) return;

        Inorder(root->left);
        arr.push_back(root->val);
        Inorder(root->right);
    }
    void putValues(TreeNode*root)
    {
        if(!root) return;
        putValues(root->left);
        root->val = arr[i++];
        putValues(root->right);
    }
    void recoverTree(TreeNode* root) 
    {
        Inorder(root);
        sort(arr.begin(),arr.end());
        putValues(root);
    }
};