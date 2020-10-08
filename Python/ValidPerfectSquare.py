Python 4 Methods with time testing

1. Solving with Bitwise trick.

    def BitwiseTrick(self, num):
       root = 0
       bit = 1 << 15
       
       while bit > 0 :
           root |= bit
           if root > num // root:    
               root ^= bit                
           bit >>= 1        
       return root * root == num

2. Using Newton's Method

    def NewtonMethod(self, num):
        r = num
        while r*r > num:
            r = (r + num/r) // 2
        return r*r == num
3. Math Trick for Square number is 1+3+5+ ... +(2n-1)

    def Math(self, num):
        i = 1
        while (num>0):
            num -= i
            i += 2       
        return num == 0
4. Binary Search Method

    def BinarySearch(self, num):
        left = 0
        right = num
        
        while left <= right:
            mid = left + (right-left)//2
            if  mid ** 2 == num:
                return True
            elif mid ** 2 > num:
                right = mid -1
            else:
                left = mid +1
        return False
        
I test these Four methods with for i in range(100000): function(i), and get results as below.

Time for Bitwise's Method : 0.45249104499816895
Time for Newton's Method : 0.3492701053619385
Time for Math's Method : 2.641957998275757
Time for Binary Search's Method : 1.5031492710113525
