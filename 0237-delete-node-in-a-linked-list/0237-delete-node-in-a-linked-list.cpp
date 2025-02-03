/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode *to_be_deleted = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete  to_be_deleted;
    }
};