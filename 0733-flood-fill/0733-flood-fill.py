class Solution(object):
    def help(self,image,sr,sc,color,original_color):
        if sr<0 or sc<0 or sr>= len(image)  or sc>= len(image[0]) or image[sr][sc] != original_color:
            return
        
        image[sr][sc] = color
        self.help(image,sr+1,sc,color , original_color)
        self.help(image,sr,sc+1,color , original_color)
        self.help(image,sr,sc-1,color , original_color)
        self.help(image,sr-1,sc,color , original_color)


        return 


    def floodFill(self, image, sr, sc, color):

        original_color = image[sr][sc]
        if original_color != color:
            self.help(image,sr,sc,color,original_color)
        return image