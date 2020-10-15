#Function maxNumberOfBalloons takes text and count how many words "balloon" can be spelled using distinct letters from text.
from collections import Counter

class Solution(object):
    def maxNumberOfBalloons(self, text):
        numberOfLetters = Counter(text)
        numberOfLetters['l'] //= 2
        numberOfLetters['o'] //= 2
        
        return min([numberOfLetters[x] for x in 'balon'])
