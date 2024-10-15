class Solution(object):
    def removeDuplicates(self, nums):
        st = set()
        for i in nums:
            st.add(i)
        ls = []
        for i in st:
            ls.append(i)
        
        ls.sort()

        for i in range(0,len(ls)):
            nums[i] = ls[i]
        
        return len(ls)
        