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
    unordered_map<int,int>mp;
    vector<int>in,po;
    TreeNode* help(int instart,int inend,int pstart,int pend) {

        if(instart > inend or pstart > pend)
         return nullptr;

        TreeNode* root = new TreeNode(po[pstart]);
        int rootIndex = mp[po[pstart]];
        int left = rootIndex - instart;

        root->left = help(instart,rootIndex-1,pstart+1,pstart+left);
        root->right = help(rootIndex+1,inend,pstart+left+1,pend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();

        in = inorder;
        po = preorder;

        for(int i = 0;i<inorder.size();i++) {
            mp[in[i]] = i;
        }

        return help(0,n-1,0,n-1);
    }
};