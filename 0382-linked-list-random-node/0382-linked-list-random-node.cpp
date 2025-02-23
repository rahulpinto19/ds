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
    ListNode*root;
    int len = 0;
    Solution(ListNode* head) 
    {
        root = head;
        while(head)
        {
            len++;
            head = head->next;
        }
    }
    
    int getRandom() 
    {
        ListNode*curr = root;
        int rand = random();
        rand%=len;
        while(rand and curr->next)
        {
            curr = curr->next;
            rand--;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */