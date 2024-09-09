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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>>ans(m,vector<int>(n,-1));


        
        int right =n-1, down = m-1, up =0,left =0;
        while(head)
        {
            for(int i=left ;i<=right and head;i++ )
            {
                ans[up][i] = head->val;
                head = head->next;
            }
            for(int i=up+1 ;i<=down-1 and head;i++)
            {
                ans[i][right] = head->val;
                head = head->next;
            }
            for(int i = right;i>=left and head;i--)
            {
                ans[down][i] = head->val;
                head = head->next;
            }
             for(int i = down-1;i>=up+1 and head ;i--)
            {
                ans[i][left] = head->val;
                head = head->next;
            }
            right--;up++;down--;left++;
        }
        return ans;
    }
};