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
    vector<vector<int>>ans;
    void help(TreeNode*root,int currSum,int target,vector<int>&currpath)
    {
        if(!root) return;
        currpath.push_back(root->val);
        currSum+=root->val;
        if(!(root->left) and  !(root->right) and currSum == target)
        {
            ans.push_back(currpath);
        }
        else
        {
            help(root->left,currSum ,target,currpath);
            help(root->right,currSum ,target,currpath);
        }
        currpath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int>temp;
        help(root,0,targetSum,temp);    
        return ans;
    }
};