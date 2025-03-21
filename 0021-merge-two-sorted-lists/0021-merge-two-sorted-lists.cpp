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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*dummy = new ListNode(0);
        ListNode*start = dummy;
        ListNode*ptr1 = list1;
        ListNode*ptr2 = list2;

        while(ptr1 || ptr2)
        {
            if(ptr1 == NULL)
            {
                start->next = ptr2;
                break;
            }
            else if (ptr2 == NULL)
            {
                start->next = ptr1;
                break;
            }
            else if(ptr1->val < ptr2->val)
            {
                start->next = ptr1;
                ptr1 = ptr1->next;
                start = start->next;
            }
            else
            {
                start->next = ptr2;
                ptr2 = ptr2->next;
                start = start->next;
            }

        }    
        return dummy->next;
    }
};