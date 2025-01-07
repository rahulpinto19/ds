class Solution(object):
    def stringMatching(self, words):
        ans = []
        for i in range(len(words)):
            for j in range(len(words)):
                if i!=j and words[i] in words[j]:
                    ans.append(words[i])
                    break
        return ans
        
        