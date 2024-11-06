class Solution(object):
    def judgeSquareSum(self, c):
        
        if(c == 0):
            return True

        for i in range(1,int(sqrt(c))+1):
            a = i
            b = c - (i**2)

            sqrtb = int(sqrt(b)) 

            if(sqrtb**2 == b):
                return True
        return False
        