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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        set<int>s = {nums.begin(),nums.end()};
        ListNode*ans = new ListNode();
        ListNode*ptr = head;
        ListNode*dummy = ans;
        while(ptr )
        {
            if(s.find(ptr->val) == s.end())
            {
                dummy->next = new ListNode(ptr->val);
                dummy = dummy->next;
            }
            ptr = ptr->next;
        }
        return ans->next;
    }
};