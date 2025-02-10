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
    unordered_map<long long,int>mp;
    int ans = 0;
    void help(TreeNode*root,int target,long long currSum)
    {
        if(!root)
            return;
        
        currSum+=root->val;
        if(mp.find( currSum - target) != mp.end())
            ans+=mp[ currSum - target];
        mp[currSum]++;
        
        help(root->left,target,currSum);
        help(root->right,target,currSum);

        mp[ currSum ]--;
    }
    int pathSum(TreeNode* root, int targetSum) 
    {
        mp[0] = 1; 
        help(root,targetSum,0);    
        return ans;
    }
};