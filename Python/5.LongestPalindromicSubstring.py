#check if string is palindrome or not
def isPalindrome(s, x, y):
    while x < y:
        if s[x] != s[y]:
            return False
        x += 1
        y -= 1
    return True

def longestPalindrome(s):
    n = len(s)
    max_ = 0
    ans = ''

    if n == 1:
        return s

    for i in range(n):
        #list of all index which is same as s[i]
        duplicate = [j for j in range(i+1, n) if s[j] == s[i]]
        
        #look through all elements in duplicate if the string is palindrome
        for j in duplicate:
            #if palinfrome update max value and add sub-string to ans
            if isPalindrome(s, i, j) and j - i + 1 > max_:
                max_ = j - i + 1
                ans = ''.join(s[i:j+1])
    
    return ans

s = 'abacddcliril'

l = longestPalindrome(list(s))

print(l) #liril
        