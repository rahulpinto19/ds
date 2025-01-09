class Solution(object):
    def prefixCount(self, words, pref):
        
        ans = 0
        for word in words:
            
            if len(word)>= len(pref) and word[:len(pref)] == pref:
                ans+=1
        return ans
        