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
            int firstIndex  = q.front().second;
            int lastIndex = firstIndex;
            while(size--)
            {
                TreeNode*node = q.front().first;
                long long num = q.front().second - firstIndex;
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
            cout<<firstIndex<<" "<<lastIndex<<endl;
            ans = max(ans,lastIndex + 1);
        }    
        return ans;
    }
};