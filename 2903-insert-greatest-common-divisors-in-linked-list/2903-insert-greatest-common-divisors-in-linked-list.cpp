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
    int help(int a ,int b)
    {
        for(int i = min(a,b);i>0;i--)
        {
            if(!(a%i) and !(b%i))
                return i;
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        ListNode* k = head;
        while(k  and k->next)
        {
            int value=help(k->val,k->next->val);
            ListNode*temp = new ListNode(value);
            temp->next = k->next;
            k->next = temp;
            k=k->next->next;
        }
        return head;
    }
};