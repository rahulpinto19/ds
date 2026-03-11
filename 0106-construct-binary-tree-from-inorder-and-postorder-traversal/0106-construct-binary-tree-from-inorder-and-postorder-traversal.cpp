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
    vector<int>in,po;
    unordered_map<int,int>mp;
    TreeNode* help(int instart,int inend,int pstart,int pend) {

        if(instart > inend or pstart > pend) return NULL;

        TreeNode* curr = new TreeNode(po[pend]);
        int rootIndex = mp[po[pend]];
        int leftnodes = rootIndex - instart;

        curr->left = help(instart,rootIndex-1,pstart,pstart+leftnodes-1);
        curr->right = help(rootIndex+1,inend,pstart+leftnodes,pend-1);
    
        return curr;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        in = inorder;
        po = postorder;
        int n = inorder.size();
        for(int i = 0;i<n;i++) {
            mp[in[i]] = i;
        }

        return help(0,n-1,0,n-1);

    }
};