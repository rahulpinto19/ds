class Solution(object):
    def __init__(self):
        self.ans = []
    def help(self,index,cand,target,temp):
        if target<0 or index >= len(cand):
            return
        if target == 0:
            
            self.ans.append(temp[:])
            return 
        temp.append(cand[index])
        self.help(index,cand,target - cand[index],temp)
        temp.pop()
        self.help(index+1,cand,target,temp)

    def combinationSum(self, candidates, target):
        self.help(0,candidates,target,[])
        return self.ans
        