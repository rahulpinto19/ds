/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    bool help(ListNode*head,TreeNode *root)
    {
        if(!head)
        return 1;
        if(!root || head->val != root->val)
        return 0;

        return help(head->next,root->left) | help(head->next,root->right);

    }
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int size = q.size();

            while(size)
            {
                TreeNode*first = q.front();
                q.pop();
                
                if(first->val == head->val and help(head,first))
                return 1;
                // cout<<endl;
                if(first->left)
                q.push(first->left);

                if(first->right)
                q.push(first->right);
                
                size--;
            }
        }
        return 0;
    }
};