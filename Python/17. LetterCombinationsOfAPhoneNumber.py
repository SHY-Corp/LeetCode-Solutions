class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        A={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        ans=[]
        for _ in range(len(digits)):
            temp=[]
            for i in range(len(A[digits[_]])):
                for var in ans:
                    temp.append(var+A[digits[_]][i])
            if _ is 0:
                for a in A[digits[_]]:
                    temp.append(a)
            ans=temp[:]
        return ans
            
            