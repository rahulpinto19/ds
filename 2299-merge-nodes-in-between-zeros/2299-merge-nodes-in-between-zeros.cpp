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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode* ans = new ListNode(-1);
        ListNode*ptr = ans;
        int sum = 0;

        for(ListNode*temp = head;temp ; temp = temp->next )
        {
            sum+=temp->val;
            if(sum and !(temp->val))
            {
                cout<<sum<<" ";
                ptr->next = new ListNode(sum);
                ptr = ptr->next;
                sum = 0;
            }
        }    
       
       return ans ->next;
    }
};