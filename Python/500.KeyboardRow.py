#Function findWords return list of thoes words from words list that can be typed using only one row from US keyboard.
class Solution(object):
    def canUseRow(self, row, word):
        return len([x for x in word if x not in row]) == 0
    
    def isOneRowEnough(self, word):
        firstRow = "qwertyuiop"
        secondRow = "asdfghjkl"
        thirdRow = "zxcvbnm"
        word = word.lower()
        return self.canUseRow(firstRow, word) or self.canUseRow(secondRow, word) or self.canUseRow(thirdRow, word)
        
        
    def findWords(self, words):
        return [x for x in words if self.isOneRowEnough(x)]
