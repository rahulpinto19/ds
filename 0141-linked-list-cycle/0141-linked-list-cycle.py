# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        if head is None:
            return 0
        slow = head
        fast = head.next
        while(fast and fast.next and slow !=fast):
            slow = slow.next
            fast = fast.next.next
        return slow == fast
    
        