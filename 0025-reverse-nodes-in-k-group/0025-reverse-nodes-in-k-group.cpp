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
private:
    ListNode*dummy = new ListNode(-1),*prev = dummy;
    int len = 0;
    int length(ListNode*root)
    {
        if(!root)
            return 0;
        return 1 + length(root->next);
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        dummy->next = head;
        len = length(head);
        for(int i = 0;i<len/k;i++)
        {
            for(int j = 1;j<k;j++)
            {
                ListNode *temp = prev->next;
                prev->next = head->next;
                head->next = head->next->next;
                prev->next->next = temp;
            }
            prev = head;
            head = head->next;
        }
        return dummy->next;
    }
};