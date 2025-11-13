class Solution(object):
    def maxOperations(self, s):
        res = 0
        countOne = 0
        i = 0
        while i < len(s):

            if s[i] == '0':
                while i+1 < len(s) and s[i+1] == '0':
                    i+=1
                res+=countOne
            else :
                countOne+=1
            i+=1
        return res
        