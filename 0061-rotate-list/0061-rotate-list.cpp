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
    int len(ListNode*head)
    {
        if(!head)
            return 0;
        int len = 0;
        while(head)
        {
            head = head->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(k == 0 || !head)
            return head;
        if(k == len(head) || len(head) == 1)
            return head;
        
        k%= len(head);

        ListNode*slow = head,*fast = head;
        for(int i = 0;i<k;i++)
        {
            fast = fast->next;
        }
        while(fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }    
        ListNode*ans = slow->next;
        fast->next = head;
        slow->next = NULL;

        return ans;
    }
};