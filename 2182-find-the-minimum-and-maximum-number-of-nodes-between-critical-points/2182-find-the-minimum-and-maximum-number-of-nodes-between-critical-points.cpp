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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int cnt = 1;
        ListNode*prev = NULL;
        vector<int>v;
        vector<int>ans(2,0);
        ans[0] = INT_MAX;
        ans[1] = INT_MIN;

        for(ListNode* ptr = head;ptr;ptr = ptr->next )
        {
            if(prev and ptr->next)
            {
                if(prev->val > ptr->val and ptr->val < ptr->next->val)
                {
                   v.push_back(cnt);
                }
                if(prev->val < ptr->val and ptr->val > ptr->next->val)
                {
                    v.push_back(cnt);
                }
            }
            prev = ptr;
            cnt++;
        }    
        if(v.size() <= 1)
        return {-1,-1};
        
        for(int i=1;i<v.size();i++)
        {
            ans[0] = min(ans[0],v[i] - v[i-1]);
        }
        ans[1] = v[v.size()-1] - v[0];
        return ans;
    }
};