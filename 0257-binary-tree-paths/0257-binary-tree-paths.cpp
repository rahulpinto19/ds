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
    vector<string>ans;
    void help(TreeNode*root,string &str)
    {
        if(!root)
        {
            return ;
        }
        if(!root->left and !root->right)
            {ans.push_back(str + (str.size() ? "->" :"") + to_string(root->val)); return;}
       
        string temp = str + (str.size() ? "->" : "") + to_string(root->val);
        help(root->left,temp);
        help(root->right,temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string temp="";
        help(root,temp);
        return ans;
    }
};