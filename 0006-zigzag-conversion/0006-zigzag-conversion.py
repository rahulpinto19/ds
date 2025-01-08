class Solution(object):
    def convert(self, s, numRows):
        rows=[""]*numRows
        position=0
        direction=1
        n=numRows
        dir = 1
        pos = 0
        
        for char in s:
            
            if(pos==0):
                dir = +1
            if(pos == n-1):
                dir = -1
            rows[pos]+=(char)
            pos+=dir
            if(pos<0):
                pos = 0
            if(pos == numRows):
                pos = numRows-1
        return ''.join(rows)