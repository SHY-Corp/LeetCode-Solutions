#Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        #initialize an empty list 
        self_dividing_nos = []
        #check for all the numbers in given range if they are self dividing
        for num in range(left, right + 1):
            num_original = num      
            while (num > 0):
                digit = num % 10
                if digit != 0:
                    if (num_original % digit == 0):
                        num = num // 10
                    else:
                        break
                else:
                    break
            if num == 0:
                self_dividing_nos.append(num_original)
        return self_dividing_nos
                
            
