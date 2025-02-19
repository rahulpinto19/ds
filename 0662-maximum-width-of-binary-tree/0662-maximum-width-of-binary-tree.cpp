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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans = 0;
        while(q.size())
        {
            int size = q.size();
            int minVal = q.front().second;
            int i = minVal,j = minVal;
            while(size--)
            {
                auto node = q.front();
                q.pop();
                j = node.second;
                if(node.first->left)
                {
                    q.push({node.first->left, (2*(node.second - minVal))});
                }
                if(node.first->right)
                {
                    q.push({node.first->right, (2*(node.second - minVal) + 1)});
                }
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};

/*
 queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans = 0;
        while(q.size())
        {
         
            int size = q.size();
            int firstIndex  = q.front().second;
            int lastIndex = firstIndex;
            while(size--)
            {
                TreeNode*node = q.front().first;
                int num = q.front().second - firstIndex;
                q.pop();
                lastIndex = num;
                if(node->left)
                {
                    q.push({node->left,(num*2)});
                }
                if(node->right)
                {
                    q.push({node->right,(num*2) + 1});
                }
            }
            ans = max(ans,lastIndex + 1);
        }    
        return ans;
*/ 