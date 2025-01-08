class Solution(object):
    def convert(self, s, numRows):
        rows=[""]*numRows
        position=0
        direction=1
        n=numRows
        dir = 1
        pos = 0
        if(numRows == 1):
            return s 
        for char in s:
            
            if(pos==0):
                dir = +1
            if(pos == n-1):
                dir = -1
            rows[pos]+=(char)
            pos+=dir
           
        return ''.join(rows)